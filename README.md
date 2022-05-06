# RCA
Random cell automata for hash algorithm.


# 文件说明：
- sts-2.1.2 是助教提供的随机性检测软件
- rca.hpp 是 hash function 主体部分
- prng.hpp 是 presudo-random-number-generator(伪随机数生成器)
- main.cpp 是 提供的运行和测速接口

# 运行方式
$ gcc main.cpp -o rca
$ ./rca
$ 之后手动输入测试字符串

或者在input.txt输入测例，使用以下命令测试
$ ./rca < input.txt

