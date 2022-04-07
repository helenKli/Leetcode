//https://leetcode.com/problems/search-insert-position/

#include <iostream>
#include <vector>

int searchInsert(const std::vector<int>& nums, int target) {
    int index = 0;
    int end = nums.size() - 1;
    while (index < end) {
        if (nums[(end + index) / 2] == target) {
            return (end + index) / 2; 
        }
        if (nums[(end + index) / 2] < target) {
            index = (end + index) / 2 + 1;
        }
        if (nums[(end + index) / 2] > target) {
            end = (end + index) / 2 - 1;
        }
    }
    if (nums[index] >= target) {
        return index;
    } else {
        return end + 1;
    }
}

void test(const std::vector<int>& nums, int target, int correctAnswer) {
    int result = searchInsert(nums, target);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    test({1, 4, 8, 12, 16, 23, 28, 29, 33, 39, 43}, 25, 6);
    test({-14, -12, -7, -4, -2, -1, 1, 2}, 3, 8);
    return 0;
}
