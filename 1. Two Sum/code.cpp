#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
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

int main() {
    vector<int> test = {1, 2, 3, 4, 5, 6};
    int target = 11;
    const vector<int> result = twoSum(test, target);
    if (result[0] == 4 && result[1] == 5) {
        cout << "Test passed" << endl;
    } else {
        cout << "Test not passed" << endl;
    }
}