//https://leetcode.com/problems/plus-one/

#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    int end = digits.size() - 1;
    while (digits[end] == 9) {
        digits[end] = 0;
        end--;
        if (end < 0) {
            digits.resize(digits.size() + 1);
            digits[0] = 1;
            return digits;
        }
    }
    digits[end]++;
    return digits;
}

void test(std::vector<int>& nums, const std::vector<int>& correctAnswer) {
    std::vector<int> result = plusOne(nums);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    std::vector<int> nums1 = {1, 0, 2, 4, 9};
    std::vector<int> nums2 = {1, 9, 2, 9, 9};
    test(nums1, {1, 0, 2, 5, 0});
    test(nums2, {1, 9, 3, 0, 0});
    return 0;
}
