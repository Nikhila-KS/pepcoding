/*   # Middle Of A Linked List #

given a singly linked list with head node head, return a middle node of linked list.
if there is 2 mid node then return first mid node.
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *midNode(ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
        
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
    }
    return slow;
}

int main()
{
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = midNode(dummy->next);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
