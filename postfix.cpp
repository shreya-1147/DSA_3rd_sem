//POST EVALUATION

#include <iostream>
#include <cctype>
using namespace std;
int st[100];
int top = -1;
void push(int a);
int pop();
int main()
{
    int i = 0;
    int num, res, exp[100];
     while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            num = 0;
            while(exp[i] != ',')
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
            if(exp[i] == ',')
                i++;
        }
        else
        {
            int n1 = pop();
            int n2 = pop();
            switch(exp[i])
            {
                case '+':
                    res = n2 + n1;
                    break;

                case '-':
                    res = n2 - n1;
                    break;

                case '*':
                    res = n2 * n1;
                    break;

                case '/':
                    res = n2 / n1;
                    break;
            }
            push(res);
            if(exp[i] == ',')
                i++;
            else
                i++;
        }
    }
    cout << pop();
    return 0;
}
void push(int a)
{
    st[++top] = a;
}
int pop()
{
    return st[top--];
}