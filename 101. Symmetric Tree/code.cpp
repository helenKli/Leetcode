//https://leetcode.com/problems/symmetric-tree/

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

bool isSymmetric(TreeNode* root) {
    TreeNode* p1 = root->left;
    TreeNode* q1 = root->right;
    std::stack<TreeNode*> p; p.push(p1);
    std::stack<TreeNode*> q; q.push(q1);
    while (!p.empty() && !q.empty()) {
        p1 = p.top(); p.pop();
        q1 = q.top(); q.pop();
        if (p1 != nullptr && q1 != nullptr) {
            if (p1->val == q1->val) {
                p.push(p1->right);
                p.push(p1->left);
                q.push(q1->left);
                q.push(q1->right);
            } else {
                return false; 
            }
        } else if (p1 != nullptr || q1 != nullptr) {
            return false;
        }    
    }
    return true;
}

void test(TreeNode* root, const bool& correctAnswer) {
    bool result = isSymmetric(root);
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
    test(&t1, false);
    test(&q1, true);
}