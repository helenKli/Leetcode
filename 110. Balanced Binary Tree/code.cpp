//https://leetcode.com/problems/balanced-binary-tree/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int heightOfTree(TreeNode* root) {
    if (root == 0) {
        return 0;
    } 
    return 1 + std::max(heightOfTree(root->left), heightOfTree(root->right));
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    int height_left = heightOfTree(root->left);
    int height_right = heightOfTree(root->right);
    if (std::abs(height_left - height_right) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
        return true;
    } else {
        return false;
    }
}

void test(TreeNode* root, bool correctAnswer) {
    bool result = isBalanced(root);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    TreeNode t5(17), t4(7), t2(2);
    TreeNode t3(29, &t4, &t5);
    TreeNode t1(1, &t2, &t3);
    TreeNode q5(4);
    TreeNode q4(3, nullptr, &q5);
    TreeNode q3(2, nullptr, &q4);
    TreeNode q2(2);
    TreeNode q1(1, &q2, &q3);
    test(&t1, true);
    test(&q1, false);
    return 0;
}
