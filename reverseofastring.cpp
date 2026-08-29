#include <iostream>
#include <string>
using namespace std;

char stack[100];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}

void pop()
{
    while (top != -1)
    {
        char x = stack[top];
        cout << x;
        top--;
    }
}
int main()
{
    int i = 0;
    string str;

    cin >> str;

    while (str[i] != '\0')
    {
        push(str[i]);
        i++;
    }

    pop();

    return 0;
}