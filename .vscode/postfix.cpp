#include <iostream>
#include <stack>
#include <cctype>
#include <unordered_map>
using namespace std;

int evaluatePostfix(const string& expr, unordered_map<char, int>& values) {
    stack<int> s;
    for (char ch : expr) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else if (isalpha(ch)) {
            s.push(values[ch]);
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push(a ^ b); break;
            }
        }
    }
    return s.top();
}

int main() {
    string expr = "ab2*c3^/-";
    unordered_map<char, int> values = {{'a', 3}, {'b', 2}, {'c', 1}};
    cout << evaluatePostfix(expr, values) << endl;  // Output: -1
    return 0;
}
