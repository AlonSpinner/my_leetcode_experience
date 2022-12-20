#include <iostream>


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}     
};
 
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode result_list(0); //we will advance
        ListNode* new_list = &result_list;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1 -> val < list2 -> val) {
                new_list -> next = list1;
                list1 = list1 -> next;
            } else {
                new_list -> next = list2;
                list2 = list2 -> next;
            }
            new_list = new_list -> next;
        }
        if (list1 != NULL && list2 == NULL) {
            new_list -> next = list1;
            std::cout << "flushing list 2" << std::endl;
        }
        if (list1 == NULL && list2 != NULL) {
            new_list -> next = list2;
            std::cout << "flushing list 1" << std::endl;
        }

        return result_list.next;
    }
};

int main() {
    Solution s;
    //build list1
    ListNode list1_c(3);
    ListNode list1_b(2, &list1_c);
    ListNode list1_a(1, &list1_b);
    ListNode list1 = list1_a;

    //check it out:
    // ListNode* ptr_list1 = &list1;
    // while (ptr_list1 != NULL) {
    //     std::cout << ptr_list1 -> val << std::endl;
    //     ptr_list1 = ptr_list1 ->next;
    // };

    ListNode list2_c(6);
    ListNode list2_b(5, &list2_c);
    ListNode list2_a(4, &list2_b);
    ListNode list2 = list2_a;

    ListNode list3;

    auto newlist = s.mergeTwoLists(&list1, &list2);
    while (newlist != NULL) {
        std::cout << newlist -> val << std::endl;
        newlist = newlist -> next; //dereference
    };
}