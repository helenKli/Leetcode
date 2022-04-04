//https://leetcode.com/problems/merge-sorted-array/

#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, const int& m, std::vector<int>& nums2, const int& n) {
    int i = 0;
    int j = 0;
    if (m == 0) {
        nums1 = nums2;
    } else {
        while (j < n && i <= m) {
            if (i == m){
                nums1[m + n -1 - i - j] = nums2[n - 1 - j];
                j++;
            } else if (nums1[m - 1 - i] > nums2[n - 1 - j]) {
                nums1[m + n - 1 - i - j] = nums1[m - 1 - i];
                i++;
            } else {
                nums1[m + n -1 - i - j] = nums2[n - 1 - j];
                j++;
            }
        }
    }
}

void test(std::vector<int>& v1, const int& n1, std::vector<int>& v2, const int& n2, const std::vector<int>& correctAnswer) {
    merge(v1, n1, v2, n2);
    if (v1 == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    std::vector<int> nums1 = {1, 3, 4, 6, 7, 8, 0, 0, 0, 0, 0};
    std::vector<int> nums2 = {2, 4, 6, 7, 11};
    std::vector<int> nums3 = {1};
    std::vector<int> nums4 = {};
    test(nums1, 6, nums2, 5, {1, 2, 3, 4, 4, 6, 6, 7, 7, 8, 11});
    test(nums3, 1, nums4, 0, {1});
}