//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>

int maxProfit(const std::vector<int>& prices) {
    int profit = 0;
    int min = prices[0], max = prices[0];
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < min) {
            min = prices[i];
            max = prices[i];
        }
        if (prices[i] > max) {
            max = prices[i];
        }
        if (max - min > profit) {
            profit = max - min;
        }
    }
    return profit;
}

void test(const std::vector<int>& pr, int correctAnswer) {
    int result = maxProfit(pr);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    test({10, 8, 5, 3, 2, 1}, 0);
    test({7, 4, 1, 6, 4, 9}, 8);
    return 0;
}
