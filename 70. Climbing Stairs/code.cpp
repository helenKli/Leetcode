//https://leetcode.com/problems/climbing-stairs/

#include <iostream>

int climbStairs(int n) {
    if (n == 1) {
        return n;
    }
    int count[n];
    count[0] = 1;
    count[1] = 2;
    for (int i = 2; i < n; i++) {
        count[i] = count[i - 1] + count[i - 2];
    }
    return count[n - 1];
}

void test(int val, int correctAnswer) {
    int result = climbStairs(val);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    test(10, 89);
    test(25, 121393);
    return 0;
}
