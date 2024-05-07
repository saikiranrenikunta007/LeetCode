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
    ListNode* reverse(ListNode *head) {

         ListNode *curr = head;
         ListNode *prev = NULL;
         while(curr != NULL) {
            ListNode *next = curr->next;
            curr -> next = prev ;
            prev = curr;
            curr = next;
         }
         return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode *temp = new ListNode(INT_MAX),*dummy = temp;
        int carry=0;
        while(head != NULL) {

             int val = 2*(head->val) + carry;
             temp->next = new ListNode(val%10);
             head = head->next;
             carry = val/10;
             temp = temp ->next;
        }
        while(carry>0) {
            temp->next = new ListNode(carry%10);
            temp = temp->next;
            carry/=10;
        }
        return reverse(dummy->next);
    }
};