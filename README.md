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

test.py提供了随机生成字符串的方法，可以在脚本中修改生成串的个数、长度范围，通过重定向到input.txt可以方便之后的加密：
$ python3 test.py > input.txt
利用生成脚本或者手动输入得到input.txt后，使用以下命令测试：
$ ./rca < input.txt
密钥会经过stdio输出，同时以二进制形式写入output.bin，方便之后进行随机性检验。
