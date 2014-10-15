#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL|| head->next->next == NULL)
            return;

        ListNode *slow = head, *fast = head->next->next;
        ListNode *newHead = NULL, *middle = NULL;
        while(fast != NULL)
        {
            if(newHead == NULL)
            {
                cout << "newhead == NULL" << endl;
                newHead = slow;
                cout << newHead << endl;
                slow = slow->next;
                newHead->next = NULL;
            } else {
                cout << "newhead != NULL" << endl;
                ListNode *tmp = slow->next;
                cout << tmp << endl;
                slow->next = newHead;
                cout << slow->next << endl;
                newHead = slow;
                cout << newHead << endl;
                slow = tmp;
                cout << slow << endl;
            }

            ListNode *bar = newHead;
            while(bar != NULL)
            {
                cout << bar->val << endl;
                bar = bar->next;
            }

            cout << "next slow" << endl;
            cout << fast->val << endl;
            if(fast->next != NULL)
            {
                fast = fast->next->next;
            } else {
                fast = NULL;
            }

            cout << "next fast" << endl;
        }
        cout << "finished sorting" << endl;
        middle = slow;
//        while(middle != NULL)
//        {
//            ListNode *tmp = middle->next;
//            middle->next = newHead->next;
//            newHead
//        }

        head = newHead;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Solution foo;

    ListNode node1(1);
    ListNode node2(2);
    node1.next = &node2;
    ListNode node3(3);
    node2.next = &node3;
    ListNode node4(4);
    node3.next = &node4;
    ListNode node5(5);
    node4.next = &node5;

    foo.reorderList(&node1);
    ListNode *tmp = &node1;
    while(tmp != NULL)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}
