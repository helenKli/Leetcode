//https://leetcode.com/problemset/all/?difficulty=EASY&page=1

#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int k = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != k) {
            k = nums[i];
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}

void test(std::vector<int>& nums, const int& correctAnswer) {
    int result = removeDuplicates(nums);
    if (result != correctAnswer ) {
        std::cout << "Test not passed" << std::endl;
    } else {
        std::cout << "Test passed" << std::endl;
    }
}

int main() {
    std::vector<int> nums1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::vector<int> nums2 = {0, 1, 2, 3, 4, 5, 6};
    test(nums1, 5);
    test(nums2, 7);
    return 0;
}
