//https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } else {
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
}

void test(TreeNode* root, const int& correctAnswer) {
    int result = maxDepth(root);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    TreeNode t5(5);
    TreeNode t4(4);
    TreeNode t3(3, &t4, &t5);
    TreeNode t2(2);
    TreeNode t1(1, &t2, &t3);
    TreeNode q7(4), q6(4);
    TreeNode q5(3, &q7, nullptr);
    TreeNode q4(3, nullptr, &q6);
    TreeNode q3(5, nullptr, &q5);
    TreeNode q2(5, &q4, nullptr);
    TreeNode q1(11, &q2, &q3);
    test(&t1, 3);
    test(&q1, 4);
}