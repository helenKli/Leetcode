//https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <vector>

int maxSubArray(const std::vector<int>& nums) {
    int step = nums[0];
    int sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (step + nums[i] >= nums[i]) {
            step += nums[i];
        } else {
            step = nums[i];
        }
        if (step > sum) {
            sum = step;
        }
    }
    return sum;
}

void test(const std::vector<int>& nums, int correctAnswer) {
    int result = maxSubArray(nums);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    test({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6);
    test({3, 1, 5, -2, -4, -2, 5, 3, 6, -4, -2, 5, -3}, 15);
    return 0;
}
