# C++ 学习路线图（ROADMAP）

> 最终目标：在本机（WSL Ubuntu 22.04 + RTX 4060 Ti 16G）上，用 C++ 跑通 **SuperPoint + LightGlue** 特征匹配。
>
> 路线：先懂图像 → 再学传统特征匹配 → 补齐 C++ 前置知识 → 部署深度模型 → 多线程扩展。

---

## 已完成：C++ 入门（01–09）

- [x] 01 输入输出与统计（cin / cout、边界情况）
- [x] 02 函数（返回值 vs 输出参数、按值 / 按引用传递）
- [x] 03 vector 与 string（size_t、signed/unsigned、getline）
- [x] 04 指针（取地址、解引用、nullptr、段错误 SEGV）
- [x] 05 struct 与 class（封装、环形缓冲区 RingBuffer、矩形重叠面积）
- [x] 06 构造 / 析构与 RAII（生命周期、内存泄漏、double free、Rule of Zero）
- [x] 07 多文件与 CMake（声明 vs 定义、编译 vs 链接）
- [x] 08 GoogleTest 单元测试（third_party 本地依赖、include/src/tests 布局）
- [x] 09 OpenCV 源码编译与调用（find_package、OpenCV_DIR）

遗留小问题：
- [ ] 08 `ring_buffer.h`：`const` 位置改为 `bool empty() const;`（.h 和 .cpp 都改）
- [ ] 08 / 09 `geometry.h`：删掉多余的 `#include`
- [ ] `third_party/README.md`：补上 OpenCV 4.10.0 的记录

---

## 工程组织方式

- **阶段 A**：概念练习，每个练习一个独立文件夹（`10-xxx/`），小而快。
- **阶段 B 起**：建立一个持续演进的工程 **`vision-lab/`**，每个阶段往里加一个模块，培养工程思维：

```
vision-lab/
├── CMakeLists.txt
├── include/vision/        ← 对外接口（头文件）
│   ├── image_utils.h      ← 阶段 B：绘图、读写等工具
│   ├── features.h         ← 阶段 B：ORB、匹配、RANSAC
│   └── deep_matcher.h     ← 阶段 D：SuperPoint / LightGlue
├── src/                   ← 实现
├── apps/                  ← 可执行程序（命令行工具），例如 match_orb、match_splg
├── tests/                 ← GoogleTest 单元测试
├── models/                ← ONNX 模型（不提交，写下载说明）
└── data/                  ← 测试图片
```

原则：
- 功能写成**库**（library），`apps/` 里的程序只负责调用；
- 每加一个模块，配上对应的单元测试；
- 第三方依赖统一放在仓库根目录的 `third_party/`，大的库只提交版本记录和构建脚本。

---

## 阶段 A：图像是什么（约 3 天）

- [ ] **10 函数重载（function overloading）**
  - 用 OpenCV 写 `drawBox` 的两个重载版本：两点版（左上角 + 右下角）和 Rect 版，画在 `cv::Mat` 上
  - 默认参数（default argument）、命名空间（namespace）
  - 实验：只有返回类型不同、歧义调用（ambiguous call）、`nm` 查看名字修饰（name mangling）
- [ ] **11 Mat 的内部结构**
  - 宽、高、通道数、类型 `CV_8UC3`、**BGR 通道顺序**
  - 按行存储（row-major）、步长（stride / step）、连续内存（continuous）
  - 用 `at<>` 和 `ptr` 访问像素，**手写**彩色转灰度，与 `cv::cvtColor` 对拍
  - `Mat` 的浅拷贝 vs `clone()` 深拷贝（接上 06 的拷贝语义）
- [ ] **12 经典图像操作**
  - 二值化（threshold）、模糊（blur）、卷积核（kernel）
  - Sobel 梯度、Canny 边缘检测
  - **手写一个 3×3 卷积**，处理好图像边界

## 阶段 B：传统特征匹配（约 3 天）→ 开始 `vision-lab/`

- [ ] **B1 特征点与描述子**：ORB 检测关键点（keypoint）、计算描述子（descriptor），绘制；理解尺度和旋转不变性
- [ ] **B2 特征匹配**：暴力匹配（BFMatcher）、汉明距离（Hamming distance）、比率测试（ratio test），绘制匹配连线
- [ ] **B3 几何验证**：`findHomography` + RANSAC 剔除错误匹配，统计内点（inlier），透视变换（warp）
- C++：lambda、`std::sort` / `std::remove_if` 筛选匹配结果

> 意义：SuperPoint 替代的是 ORB 的"检测 + 描述"，LightGlue 替代的是"暴力匹配 + 比率测试"。先走通传统流程，才知道深度模型替换了哪一环，也有了对比基准。

## 阶段 C：部署前的 C++ 补课（约 2 天）

- [ ] **C1 智能指针**：`std::unique_ptr`、`std::shared_ptr`、所有权（ownership）
- [ ] **C2 移动语义（move semantics）**：左值 / 右值、`std::move`、移动构造
- [ ] **C3 RAII 封装**：把一个"申请 / 释放"成对出现的资源封装成类（为推理引擎的 session 做准备）

## 阶段 D：C++ 部署 SuperPoint + LightGlue（约 5 天）

- [ ] **D0 环境准备**
  - WSL 中确认 GPU 可用：`nvidia-smi`
  - 准备 SuperPoint、LightGlue 的 ONNX 模型
  - ONNX Runtime 预编译包放入 `third_party/`（只提交版本记录和下载脚本）
- [ ] **D1 推理入门（CPU）**：加载模型，打印输入输出的名字和形状（shape）；用 Netron 查看模型结构
- [ ] **D2 SuperPoint**
  - 预处理：灰度 → float → 除以 255 → NCHW 布局
  - 推理、后处理：得到关键点、置信度、描述子
  - 绘制关键点，与 ORB 对比
- [ ] **D3 LightGlue**
  - 输入两张图的关键点 + 描述子，输出匹配
  - 用 B3 的 RANSAC 过滤，与 ORB + BFMatcher 的结果对比
- [ ] **D4 GPU 加速**：切换到 CUDA 执行器（Execution Provider），用 `std::chrono` 测量耗时，对比 CPU / GPU
- [ ] **D5 收尾实验**：两张图先做相同的二值化，再用 SP+LG 匹配，观察效果

验证方式：用 Python 版 SP+LG 处理同一对图片作为参考（reference），与 C++ 输出对拍（关键点数量、匹配数量、内点数量）。

## 之后：多线程扩展

- [ ] `std::thread`、`std::mutex`、条件变量（condition variable）
- [ ] 线程安全队列（thread-safe queue）：把 RingBuffer 改造成线程安全版本
- [ ] 视频流水线：读帧 → 推理 → 显示（生产者-消费者 producer-consumer）

---

## 学习方式（约定）

- 代码自己写；AI 负责检查仓库、指出问题，不直接给完整答案
- 编译报错直接贴给 AI，不在语法错误上耗时间；精力放在概念、逻辑和测试设计上
- 测试代码可以交给 AI 写，但要自己检查**测了什么**，并故意改坏代码验证测试是否有效
- 新概念放在上午学；下午做修 bug、补注释、整理提交
- 编译参数：`-Wall -Wextra -Wshadow -Werror=return-type -g -fsanitize=address,undefined`
- 每完成一步就 commit + push，提交信息用 `feat(xx): ...` / `fix(xx): ...`
