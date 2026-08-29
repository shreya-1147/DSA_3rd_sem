#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    stack<char> s;

    
    for (char ch : str) {
        s.push(ch);
    }

    
    bool isPalindrome = true;
    for (char ch : str) {
        if (ch != s.top()) {
            isPalindrome = false;
            break;
        }
        s.pop();
    }

    if (isPalindrome)
        cout << "Palindrome" << endl;
    else
        cout << "Not a Palindrome" << endl;

    return 0;
}