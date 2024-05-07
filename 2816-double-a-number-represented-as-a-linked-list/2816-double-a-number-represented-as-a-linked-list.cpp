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
        ListNode *temp = head;
        int carry=0;
        while(temp != NULL) {

             int val = 2*(temp->val) + carry;
             temp->val = val%10;
             carry = val/10;
             if(temp->next == NULL) break;
             temp = temp ->next;
        }
        while(carry>0) {
            temp->next = new ListNode(carry%10);
            temp = temp->next;
            carry/=10;
        }
        return reverse(head);
    }
};