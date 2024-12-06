#include <iostream>

using namespace std;

void multiplication_table_with_for()
{
    for (int n = 1; n < 10; n++){
        for (int i = 1; i <= n; i++)
        {
            cout << n << " x " << i << " = " << n * i << "  ";
        }
        cout << endl;
    }

}

void multiplication_table_with_while()
{
    int n = 1;
    while (n < 10){
        int i = 1;
        while (i <= n)
        {
            cout << n << " x " << i << " = " << n * i << "  ";
            i++;
        }
        cout << endl;
        n++;
    }
}

void multiplication_table_with_goto()
{
    int n = 1;
    label1:
    int i = 1;
    label2:
    cout << n << " x " << i << " = " << n * i << "  ";
    i++;
    if(i <= n){
        goto label2;
    }
    cout << endl;
    n++;
    if(n<10){
        goto label1;
    }
}

int main()
{
    multiplication_table_with_for();
    multiplication_table_with_while();
    multiplication_table_with_goto();
    return 0;
}