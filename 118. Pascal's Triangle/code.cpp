//https://leetcode.com/problems/pascals-triangle/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> result(numRows);
    for (int i = 0; i < numRows; i++) {
        std::vector<int> row(i+1);
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                row[j] = 1;
            } else {
                row[j] = result[i-1][j] + result[i-1][j-1];
            }
        }
        result[i] = row;
    }
    return result;
}

void test(int num, const std::vector<std::vector<int>>& correctAnswer) {
    std::vector<std::vector<int>> result = generate(num);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    test(5, {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}});
    test(1, {{1}});
    return 0;
}
