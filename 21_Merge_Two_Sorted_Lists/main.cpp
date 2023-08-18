#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = nullptr;

        if (list1 == list2)
            return list1;

        if (list1 == nullptr)
            return list2;

        if (list2 == nullptr)
            return list1;
        
        if (list1->val <= list2->val)
        {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        }
        else
        {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }

        return result;
    }
};

bool comparator(ListNode* list1, ListNode* list2) {
    if (list1 == list2) {
        return true;
    }

    while (list1 && list2) {
        if (list1->val != list2->val) {
            return false;
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    return list1 == list2;
}

int main() {
    Solution solution;

    // Test Case 1
    ListNode *input1_list1 = new ListNode(1);
    input1_list1->next = new ListNode(2);
    input1_list1->next->next = new ListNode(4);

    ListNode *input1_list2 = new ListNode(1);
    input1_list2->next = new ListNode(3);
    input1_list2->next->next = new ListNode(4);

    ListNode *expected_output1 = new ListNode(1);
    expected_output1->next = new ListNode(1);
    expected_output1->next->next = new ListNode(2);
    expected_output1->next->next->next = new ListNode(3);
    expected_output1->next->next->next->next = new ListNode(4);
    expected_output1->next->next->next->next->next = new ListNode(4);

    ListNode *output_1 = solution.mergeTwoLists(input1_list1, input1_list2);
    std::cout << "Test Case 1: " << (comparator(expected_output1, output_1) ? "Passed" : "Failed") << "\n";

    // Test Case 2
    ListNode *input2_list1 = nullptr;
    ListNode *input2_list2 = nullptr;
    ListNode *expected_output2 = nullptr;

    ListNode *output_2 = solution.mergeTwoLists(input2_list1, input2_list2);
    std::cout << "Test Case 2: " << (comparator(expected_output2, output_2) ? "Passed" : "Failed") << "\n";

    // Add more test cases...

    return 0;
}
