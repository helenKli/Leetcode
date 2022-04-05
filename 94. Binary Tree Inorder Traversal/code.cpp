//https://leetcode.com/problemset/all/?difficulty=EASY&page=1

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

std::vector<int> inorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> st;
    std::vector<int> res(0);
    TreeNode* step = root;
    while (step != nullptr) {
        if (step->left != nullptr) {
            st.push(step);
            step = step->left;
        } else if (step->right == nullptr) {
            res.resize(res.size() + 1);
            res[res.size() - 1] = step->val;
            if (st.empty()) {
                return res;
            }
            step = st.top();
            st.pop();
            step->left = nullptr;
        } else if (step->right != nullptr) {
            res.resize(res.size() + 1);
            res[res.size() - 1] = step->val;
            step = step->right;
        }
    }
    return res;
}

void test(TreeNode* r, const std::vector<int>& correctAnswer) {
    std::vector<int> result = inorderTraversal(r);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    TreeNode t1(2);
    TreeNode t2(6);
    TreeNode t3(9);
    TreeNode t4(7, &t1, &t2);
    TreeNode t5(13, nullptr, &t3);
    TreeNode t(1, &t4, &t5);
    TreeNode a1(3);
    TreeNode a2(2, &a1, nullptr);
    TreeNode a(1, nullptr, &a2);
    test(&t, {2, 7, 6, 1, 13, 9});
    test(&a, {1, 3, 2});
    return 0;
}
