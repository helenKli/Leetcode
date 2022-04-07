//https://leetcode.com/problems/minimum-depth-of-binary-tree/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right != nullptr) {
        return 1 + minDepth(root->right);
    } else if (root->right == nullptr && root->left != nullptr) {
        return 1 + minDepth(root->left);
    } else {
        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }
}

void test(TreeNode* root, int correctAnswer) {
    int result = minDepth(root);
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
    TreeNode q1(1);
    test(&t1, 2);
    test(&q1, 1);
    return 0;
}
