//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
        return false;
    }
    if (root->left == nullptr && root->right == nullptr && root->val == targetSum) {
        return true;
    } 
    if (root->left == nullptr && root->right == nullptr && root->val != targetSum) {
        return false;
    } 
    if (root->left != nullptr) {
        root->left->val += root->val;
    }
    if (root->right != nullptr) {
        root->right->val += root->val;
    }
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

void test(TreeNode* root, int sum, bool correctAnswer) {
    bool result = hasPathSum(root, sum);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    TreeNode t9(1), t8(2), t7(7);
    TreeNode t6(4, nullptr, &t9);
    TreeNode t5(13);
    TreeNode t4(11, &t7, &t8);
    TreeNode t3(8, &t5, &t6);
    TreeNode t2(4, &t4, nullptr);
    TreeNode t1(5, &t2, &t3);
    test(&t1, 22, true);
    test(&t1, 17, false);
}