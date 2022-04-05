//https://leetcode.com/problems/same-tree/

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

void test(TreeNode* root1, TreeNode* root2, bool correctAnswer) {
    bool result = isSameTree(root1, root2);
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
    TreeNode r5(5);
    TreeNode r4(4);
    TreeNode r3(3, &r4, &r5);
    TreeNode r2(2);
    TreeNode r1(1, &r2, &r3);
    TreeNode w5(4);
    TreeNode w4(5, nullptr, &w5);
    TreeNode w3(3, nullptr, &w4);
    TreeNode w2(2);
    TreeNode w1(1, &w2, &w3);
    test(&t1, &r1, true);
    test(&t1, &w1, false);
    return 0;
}
