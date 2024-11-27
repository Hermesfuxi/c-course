#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

int fibonacci_sequence_v1(int n){
    if(n==0 or n==1){
        return n;
    }else {
        return fibonacci_sequence_v1(n - 1) + fibonacci_sequence_v1(n - 2);
    }
};
int fibonacci_sequence_v2(int n){
    if(n==0 or n==1){
        return n;
    }else {
        int a = 0;
        int b = 1;
        int c;
        for(int i = 2; i<=n; i++){
            c = a + b;
            a = b;
            b = c;
        };
        return c;
    }
};
int get_func_runtime(const string& func_name,int (*func)(int), int n){
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << func(n) << std::endl;
    auto finish = std::chrono::high_resolution_clock::now();
    // 计算持续时间
    std::chrono::duration<double> elapsed = finish - start;
    // 输出执行时间
    std::cout << func_name << " 函数执行时间为: " << elapsed.count() << "s\n";

};

int main()
{
    get_func_runtime("fibonacci_sequence_v1", fibonacci_sequence_v1, 40);
    get_func_runtime("fibonacci_sequence_v2", fibonacci_sequence_v2, 40);
    return 0;
}

