//https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    ListNode* step = head;
    while (step->next != nullptr) {    
        if (step->next->val == step->val) {
            step->next = step->next->next;
        } else {
            step = step->next;
        }
    }
    return head;
}

void test(ListNode* l1, ListNode* correctAnswer) {
    ListNode* result = deleteDuplicates(l1);
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
    ListNode a8(4);
    ListNode a7(4, &a8);
    ListNode a6(4, &a7);
    ListNode a5(3, &a6);
    ListNode a4(1, &a5);
    ListNode a3(1, &a4);
    ListNode a2(1, &a3);
    ListNode a1(1, &a2);
    ListNode c3(4);
    ListNode c2(3, &c3);
    ListNode c1(1, &c2);
    test(&a1, &c1);
    return 0;
}
