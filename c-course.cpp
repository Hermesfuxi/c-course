// c-course.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//  #include <stdio.h> 是预处理器指令，告诉 C 编译器在实际编译之前要包含 stdio.h 文件。

#include <iostream>
#include <limits.h>
#include <float.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    std::cout << "Hello World!\n";

    printf("这是我的第一个 c 程序 Horld\n");

    printf("%d\n", add(4, 5));

    printf("char 存储大小 : %lu \n", sizeof(char));
    printf("short 存储大小 : %lu \n", sizeof(short));
    printf("int 存储大小 : %lu \n", sizeof(int));
    printf("long 存储大小 : %lu \n", sizeof(long));
    printf("long long 存储大小 : %lu \n", sizeof(long long));
    printf("float 存储大小 : %lu \n", sizeof(float));
    printf("double 存储大小 : %lu \n", sizeof(double));

    printf("float 最小值: %E\n", FLT_MIN);
    printf("float 最大值: %E\n", FLT_MAX);
    printf("精度值: %d\n", FLT_DIG);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
