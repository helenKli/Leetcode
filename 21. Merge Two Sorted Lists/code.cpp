//https://leetcode.com/problems/merge-two-sorted-lists/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* step = nullptr;
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }
    while (l1 != nullptr || l2 != nullptr) {
        if (step == nullptr) {
            if (l1->val <= l2->val) {
                head = l1;
                step = l1;
                l1 = l1->next;
            } else {
                head = l2;
                step = l2;
                l2 = l2->next;
            }
        }
        if (l1 == nullptr) {
            step->next = l2; 
            return head;
        }
        if (l2 == nullptr) {
            step->next = l1; 
            return head;
        }
        if (l1->val <= l2->val) {
            step->next = l1;
            step = step->next;
            l1 = l1->next;
        } else {
            step->next = l2;
            step = step->next;
            l2 = l2->next;
        }
    }
    return head;
}

void test(ListNode* l1, ListNode* l2, ListNode* correctAnswer) {
    ListNode* result = mergeTwoLists(l1, l2);
    while (result != nullptr && correctAnswer != nullptr) {
        if (result->val == correctAnswer->val) {
            result = result->next;
            correctAnswer = correctAnswer->next;
        } else {
            break;
        }
    }
    if (result != nullptr || correctAnswer != nullptr) {
        std::cout << "Test not passed" << std::endl;
    } else {
        std::cout << "Test passed" << std::endl;
    }
}

int main() {
    ListNode a2(4);
    ListNode a1(2, &a2);
    ListNode a(1, &a1);
    ListNode b2(4);
    ListNode b1(3, &b2);
    ListNode b(1, &b1); 
    ListNode c5(4);
    ListNode c4(4, &c5);
    ListNode c3(3, &c4);
    ListNode c2(2, &c3);
    ListNode c1(1, &c2);
    ListNode c(1, &c1);
    test(&a, &b, &c);
    return 0;
}
