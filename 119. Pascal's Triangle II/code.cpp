//https://leetcode.com/problems/pascals-triangle-ii/

#include <iostream>
#include <vector>

std::vector<int> getRow(int rowIndex) {
    std::vector<int> result(rowIndex + 1);
    for (int i = 0; i <= rowIndex; i++) {
        std::vector<int> row(i + 1);
        for (int j = 0; j <= i; j++) {
            if (j ==0 || j ==i) {
                row[j] = 1;
            } else {
                row[j] = result[j] + result[j - 1];
            }
        }
        result = row; 
    }
    return result;
}

void test(int num, const std::vector<int>& correctAnswer) {
    std::vector<int> result = getRow(num);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    test(4, {1, 4, 6, 4, 1});
    test(0, {1});
    return 0;
}
