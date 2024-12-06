//
// Created by hermesfuxi on 2024/11/26 0026.
//
#include "iostream"
#include <limits>

using namespace std;

void get_size_of_type(){
    // 字符类型（Character Types）：char/wchar_t/char16_t/char32_t
    cout << "size of char: " << sizeof(char) << endl;
    cout << "size of unsigned char: " << sizeof(unsigned char) << endl;
    cout << "size of signed char: " << sizeof(signed char) << endl;
    cout << "size of wchar_t: " << sizeof(wchar_t) << endl;
    cout << "size of char16_t: " << sizeof(char16_t) << endl;
    cout << "size of char32_t: " << sizeof(char32_t) << endl;

    // 整数类型（Integer Types）: short/int/long/long long
    cout << "size of short: " << sizeof(short) << endl;
    cout << "size of signed short: " << sizeof(signed short) << endl;
    cout << "size of unsigned short: " << sizeof(unsigned short) << endl;

    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of unsigned int: " << sizeof(unsigned int) << endl;
    cout << "size of signed int: " << sizeof(signed int) << endl;

    cout << "size of short int: " << sizeof(short int) << endl;
    cout << "size of signed short int: " << sizeof(signed short int) << endl;
    cout << "size of unsigned short int: " << sizeof(unsigned short int) << endl;

    cout << "size of long int: " << sizeof(long int) << endl;
    cout << "size of long long int: " << sizeof(long long int) << endl;
    cout << "size of unsigned long long int: " << sizeof(unsigned long long int) << endl;

    cout << "size of long: " << sizeof(long) << endl;
    cout << "size of signed long: " << sizeof(signed long) << endl;
    cout << "size of unsigned long: " << sizeof(unsigned long) << endl;

    cout << "size of long long: " << sizeof(long long) << endl;
    cout << "size of signed long long: " << sizeof(signed long long) << endl;
    cout << "size of unsigned long long: " << sizeof(unsigned long long) << endl;

    // 浮点类型（Floating-Point Types）: float/double/long double
    cout << "size of float: " << sizeof(float) << endl;
    cout << "size of double: " << sizeof(double) << endl;
    cout << "size of long double: " << sizeof(long double) << endl;

    cout << "size of bool: " << sizeof(bool) << endl;
};


int main()
{
    get_size_of_type();
    return 0;
};
