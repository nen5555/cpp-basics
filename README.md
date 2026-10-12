# cpp-basics
as a newer,it was used to recording the progress

check environment
```bash
g++ --version
gdb --version
cmake --version
```

Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
cmake version 3.28.3

CMake suite maintained and supported by Kitware (kitware.com/cmake).
GNU gdb (Ubuntu 15.1-1ubuntu1~24.04.1) 15.1
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
cmake version 3.28.3

CMake suite maintained and supported by Kitware (kitware.com/cmake).

```bash
g++ -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined main.cpp -o main
```

-std=c++17	指定语言标准（language standard）
-Wall -Wextra	打开大部分警告（warnings）。警告要当错误来对待
-g	生成调试信息（debug info），GDB 要用
-fsanitize=address,undefined	运行时检查内存错误和未定义行为（UB），入门阶段最好的"老师"