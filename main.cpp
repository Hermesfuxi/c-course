#include <iostream>

using namespace std;

//利用 `while` 循环打印 100以内的偶数。
void get_even_in_range(int range){
    int i = 0;
    while(i < range){
        if(i % 2 == 0){
            std::cout << i << std::endl;
        }
        i++;
    }
}

//利用 `for` 循环找出 100以内除以 7 余数为偶数的数，打印出来
void get_remainder_even_in_range_by_divisor(int range, int divisor){
    for(int i = 0; i < range; i++){
        if((i % divisor) % 2 == 0){
            std::cout << i << std::endl;
        }
    }
};

void multi_level_pointer(){
    int *p = nullptr;
    cout << p << endl;

    int a = 10;
    int *p1 = &a;
    cout << p1 << endl;
    cout << *p1 << endl;

    int **p2 = &p1;
    cout << p2 << endl;
    cout << *p2 << endl;
    cout << **p2 << endl;

    int ***p3 = &p2;
    cout << p3 << endl;
    cout << *p3 << endl;
    cout << **p3 << endl;
    cout << ***p3 << endl;

    void * p_a = &a;
    cout << p_a << endl;
    cout << (int *)p_a << endl; // 转类型并不会改变指针地址
    cout << *(int *)p_a << endl;
    cout << (static_cast<int *>(p_a)) << endl;
    cout << *(static_cast<int *>(p_a)) << endl;
};

int counter = 1;
int get_counter(int value = counter++){
    return value;
}

int main()
{
    // 输出欢迎信息到控制台
//    std::cout<<"Hello, World!"<<std::endl;
//    get_even_in_range(100);
//    get_remainder_even_in_range_by_divisor(100, 7);
//    multi_level_pointer();
    cout << get_counter() << endl;
    cout << get_counter() << endl;
    cout << get_counter() << endl;
    return 0;
}

