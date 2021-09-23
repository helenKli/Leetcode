#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    vector<int> res(2);
    for (int i = 0; i < nums.size(); i++){
        for (int j = i + 1; j < nums.size(); j++){
            if (nums[i] + nums[j] == target){
                res[0] = i; res[1] = j;
            }
        } 
    }
    return res;
}

void test(const vector<int>& nums, int target, const vector<int>& correctAnswer) {
    const vector<int> result = twoSum(nums, target);
    if (result[0] == correctAnswer[0] && result[1] == correctAnswer[1]) {
        cout << "Test passed" << endl;
    } else {
        cout << "Test not passed" << endl;
    }
}

int main() {
    test({1, 2, 3, 4, 5, 6}, 11, {4, 5});
}