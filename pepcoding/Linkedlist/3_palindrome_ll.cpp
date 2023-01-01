/*   # palindrome linked list #

Given a singly linked list of Integers, determine it is a palindrome or not.
Input Format
1->2->3->4->3->2->1->null
1->2->3->4->2->1->null
Output Format
true
false

solution :
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

ListNode* mid(ListNode*head){
    ListNode*slow=head;
    ListNode*fast=head;        // we want to find first mid in case of even nodes
    while(fast->next->next!=NULL && fast->next!=NULL){      
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

ListNode* reverse(ListNode*head){
    ListNode*prev=NULL;
    ListNode*curr=head;
    ListNode*frwd=head;
    while(curr!=NULL){
        frwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=frwd;
    }
    return prev;
}


bool isPalindrome(ListNode *head)
{
    ListNode* midnode=mid(head);
    ListNode*nhead=midnode->next;
    midnode->next=NULL;
    nhead=reverse(nhead);
    while(nhead!=NULL){
        if(nhead->val==head->val){
            nhead=nhead->next;
            head=head->next;
        }
        else{
            return false;
        }
    }
    return true;
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

    cout << (boolalpha) << isPalindrome(dummy->next) << endl;

    return 0;
}