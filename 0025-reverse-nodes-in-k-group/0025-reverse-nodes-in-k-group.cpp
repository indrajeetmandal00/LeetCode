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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* temp1 = head;
        stack<int> st;

        while (temp) {
            st.push(temp->val);
            if (st.size() == k) {
                int step = k;
                while (step--) {
                    temp1->val = st.top();
                    st.pop();
                    temp1 = temp1->next;
                }
            }
            temp = temp->next;
        }
        return head;
    }
};