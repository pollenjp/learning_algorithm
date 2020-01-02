# A - Darker and Darker (C++)

- https://atcoder.jp/contests/agc033/tasks/agc033_a

## Execute

### Windows

```
> mkdir build && cd build
> cmake ^
    -G "Visual Studio 16 2019" ^
    -D CMAKE_CXX_COMPILER="C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.24.28314/bin/Hostx86/x86/cl.exe" ^
    ..
> cmake --build .
> Debug\main.exe < ..\..\input\sample1.txt

(one line ver)
>
mkdir build && cd build
>
cd .. && rmdir /s build && mkdir build && cd build && cmake -G "Visual Studio 16 2019" -D CMAKE_CXX_COMPILER="C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.24.28314/bin/Hostx86/x86/cl.exe" .. && cmake --build . && Debug\main.exe < ..\..\input\sample1.txt
```
