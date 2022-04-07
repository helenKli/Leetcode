//https://leetcode.com/problems/palindrome-number/

#include <iostream>

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    int rev = 0;
    while (rev < x) {
        int y = x % 10;
        x /= 10;
        rev = rev * 10 + y;
    }
    if (rev  == x || rev/10 == x) {
        return true;
    }
    return false;
}

void test(int numb, bool correctAnswer) {
    bool result = isPalindrome(numb);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    test(1234321, 1);
    test(65284, 0);
    test(10, 0);
    return 0;
}
