#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
class Stack {
private:
    int* arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    bool isFull() {
        return top == capacity - 1;
    }
bool isEmpty() {
        return top == -1;
    }
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1;
        }
        return arr[top--];
    }
    int peek() {
        if (isEmpty()) return -1;
        return arr[top];
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack contents (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
class CharStack {
private:
    char arr[100];
    int top;
public:
    CharStack() { top = -1; }
    void push(char c) { arr[++top] = c; }
    char pop() { return arr[top--]; }
    char peek() { return (top == -1) ? '\0' : arr[top]; }
    bool isEmpty() { return top == -1; }
};
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
string infixToPostfix(string infix) {
    CharStack s;
    string postfix = "";
   for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop();
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                if (c == '^' && s.peek() == '^') break; 
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    return postfix;
}
int evaluatePostfix(string postfix) {
    Stack s(postfix.length());
   for (char c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.pop();
}
int main() {
    cout << "--- 1. Stack Implementation Demo ---" << endl;
    int N = 3;
    Stack myStack(N);
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.display();
    cout << "Popped: " << myStack.pop() << endl;
    myStack.display();
    cout << "\n--- 2. Infix to Postfix & Evaluation Demo ---" << endl;
    string infix = "2+3*4-(5-2)^2"; 
    cout << "Infix Expression: " << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    int result = evaluatePostfix(postfix);
    cout << "Evaluated Result: " << result << endl;
    return 0;
}