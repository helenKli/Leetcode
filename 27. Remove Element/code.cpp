//https://leetcode.com/problems/remove-element/

#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}

void test(std::vector<int>& nums, const int target, const int& correctAnswer) {
    const int result = removeElement(nums, target);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    std::vector<int> nums1 = {0, 1, 2, 2, 3, 0, 4, 2};
    std::vector<int> nums2 = {1, 2, 7, 4, 3, 3, 7, 2, 8, 3, 13};
    test(nums1, 2, 5);
    test(nums2, 3, 8);
}
