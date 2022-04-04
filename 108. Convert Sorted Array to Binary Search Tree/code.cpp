//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
    if (nums.size() == 0) {
        return nullptr;
    }
    if (nums.size() == 1) {
        TreeNode* node = new TreeNode();
        node->val = nums[0];
        return node;
    }
    int mid = nums.size() / 2; 
    TreeNode* node = new TreeNode();
    node->val = nums[mid];
    std::vector<int> nums_left(mid);
    std::vector<int> nums_right(nums.size() - mid - 1);
    for (int i = 0; i < mid; i++) {
        nums_left[i] = nums[i];
    }
    for (int i = 0; i < nums_right.size(); i++){
        nums_right[i] = nums[mid + 1 + i];
    }
    node->left = sortedArrayToBST(nums_left);
    node->right = sortedArrayToBST(nums_right);
    return node;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    std::stack<TreeNode*> p1; p1.push(p);
    std::stack<TreeNode*> q1; q1.push(q);
    while (!p1.empty() && !q1.empty()) {
        p = p1.top(); p1.pop();
        q = q1.top(); q1.pop();
        if (p != nullptr && q != nullptr) {
            if (p->val == q->val) {
                p1.push(p->right);
                q1.push(q->right);
                p1.push(p->left);
                q1.push(q->left);
            } else {
                return false;
            }
        } else if (p != nullptr || q != nullptr) {
            return false;
        }
    }
    return true;
}

void test(const std::vector<int>& nums, TreeNode* correctAnswer) {
    TreeNode* result = sortedArrayToBST(nums);
    if (isSameTree(result, correctAnswer)) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    TreeNode t6(7), t5(3), t4(-10);
    TreeNode t3(9, &t6, nullptr);
    TreeNode t2(-5, &t4, &t5);
    TreeNode t1(6, &t2, &t3);
    TreeNode q3(7), q2(2); 
    TreeNode q1(4, &q2, &q3);
    test({-10, -5, 3, 6, 7, 9}, &t1);
    test({2, 4, 7}, &q1);
}