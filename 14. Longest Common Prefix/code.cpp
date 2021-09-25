//https://leetcode.com/problems/longest-common-prefix/

#include <iostream>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    int n = strs[0].length();
    std::string res = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        int k = 0;
        if (res.length() <= strs[i].length()) {
            while (res[k] == strs[i][k] && k < res.length()) {
                k++;
            }
        } else {
            while (res[k] == strs[i][k] && k < strs[i].length()) {
                k++;
            }
        }
        if (k < n) {
            n = k;
        }
        if (n == 0) {
            return "";
        }
    }
    res.erase(n, res.length() - n);
    return res;
}

void test(std::vector<std::string> str, std::string correctAnswer) {
    std::string result = longestCommonPrefix(str);
    if (result == correctAnswer){
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    test({"flower","flow","flight"}, "fl");
    test({"dog","racecar","car"}, "");
}