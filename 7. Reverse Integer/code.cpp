//https://leetcode.com/problems/reverse-integer/

#include <iostream>
#include <climits>

int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int y = x % 10;
        x /= 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && y > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && y < -8)) return 0;
        rev = rev * 10 + y;
    }
    return rev;
}

void test(int x, int correctAnswer) {
    int result = reverse(x);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    test(1234, 4321);
    test(576285, 582675);
}
