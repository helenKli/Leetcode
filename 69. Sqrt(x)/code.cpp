//https://leetcode.com/problems/sqrtx/

#include <iostream>

int mySqrt(const int& x) {
    if (x <= 1) {
        return x;
    }
    int low = 2; 
    int high = x;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid == x / mid) {
            return mid;
        }
        if (mid > x / mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (low > x / low) {
        return --low;
    } else {
        return low;
    }
}

void test(const int& val, const int& correctAnswer) {
    int result = mySqrt(val);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    test(8, 2);
    test(1234567, 1111);
}