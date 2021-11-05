//https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <stack>

bool isValid(const std::string s) {
    std::stack <char> steck;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            steck.push(s[i]);
        }
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (steck.empty()) {
                return false;
            }
            switch (s[i]) {
                case ')': if(steck.top() == '('){steck.pop();} else return false; break;
                case '}': if(steck.top() == '{'){steck.pop();} else return false; break;
                case ']': if(steck.top() == '['){steck.pop();} else return false; break;
            }
        }
    }
    return steck.empty();
}

void test(const std::string str, bool correctAnswer){
    bool result = isValid(str);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    test("()[]{}", 1);
    test("([)]", 0);
    test("{[]}", 1);
}