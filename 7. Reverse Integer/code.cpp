//https://leetcode.com/problems/reverse-integer/

#include <iostream>
#include <climits>

int reverse(int x) {
    long long int rev = 0;
    while (x != 0) {
        int y = x % 10;
        x /= 10;
        rev = rev * 10 + y;
        if (rev > INT_MAX || rev < INT_MIN) return 0;
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
    test(1123456789, 0);
    test(-545673, -376545);
    return 0;
}
