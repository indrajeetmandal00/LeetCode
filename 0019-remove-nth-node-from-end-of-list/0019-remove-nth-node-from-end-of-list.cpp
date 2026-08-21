/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL)
        {
            cnt++;
            temp = temp->next;
        }
        if(n==cnt) return head->next;
        cnt = cnt-n;
        ListNode* dummy = head;
        while(cnt>1)
        {
            cnt--;
            dummy = dummy->next;
        }
        if(dummy->next->next!=NULL) dummy->next = dummy->next->next;
        else dummy->next = NULL;
        return head;
    }
//please upvote...
};