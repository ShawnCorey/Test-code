#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *t1 = head, *t2, *t3 = NULL, *newHead = t1->next;
        while(t1 != NULL && t1->next != NULL)
        {
            t2 = t1->next;
            if(t3 != NULL) t3->next = t2;
            t1->next = t2->next;
            t2->next = t1;
            t3 = t1;
            t1 = t1->next;
        }
        return newHead;
    }
};

int main()
{
    Solution foo;
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    ListNode *temp = foo.swapPairs(&node1);
    while(temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
    return 0;
}
