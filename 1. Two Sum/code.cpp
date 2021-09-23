// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::vector<int> res(2);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                res[0] = i; res[1] = j;
            }
        } 
    }
    return res;
}

void test(const std::vector<int>& nums, int target, const std::vector<int>& correctAnswer) {
    const std::vector<int> result = twoSum(nums, target);
    if (result[0] == correctAnswer[0] && result[1] == correctAnswer[1]) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    test({1, 2, 3, 4, 5, 6}, 11, {4, 5});
    test({1, 2, 3, 4, 6, 12, 16}, 13, {0, 5});
    test({1, 2, 3, 4, 5, 6, 10, 14}, 3, {0, 1});
}
