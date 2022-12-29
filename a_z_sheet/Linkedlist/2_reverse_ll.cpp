/*   # Reverse linked list #

You have given a pointer to the head node of a linked list, the task is to reverse the linked list. 
We need to reverse the list by changing the links between nodes.
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

ListNode *reverse(ListNode *head)
{
    if(head==NULL||head->next==NULL){
        return head;
        
    }
    ListNode* prev=NULL;
    ListNode*curr=head;
    ListNode* frwd=NULL;
    while(curr!=NULL){
        frwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=frwd;
        
    }
    return prev;
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

    ListNode *head = reverse(dummy->next);
    while (head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
