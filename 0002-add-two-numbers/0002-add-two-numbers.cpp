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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(INT_MAX);
        ListNode *temp =dummy;
        int carry=0;
        while(l1 != NULL || l2 != NULL)
        {
            int v= carry + (l1==NULL ? 0 : l1->val) + (l2==NULL ? 0 : l2->val);
            if(l1 != NULL) l1=l1->next;
            if(l2 != NULL) l2=l2->next;
            ListNode * new_node = new ListNode(v%10);
            carry=(v/10);
            dummy->next = new_node;
            dummy = dummy->next;
        }
        while(l1!=NULL)
        {
               int v = carry+ l1->val;
               l1=l1->next;
               ListNode * new_node = new ListNode(v%10);
               carry=(v/10);
               dummy->next = new_node;
               dummy = dummy->next;
        }
        while(l2!=NULL)
        {
               int v = carry+ l2->val;
               l2=l2->next;
               ListNode * new_node = new ListNode(v%10);
               carry=(v/10);
               dummy->next = new_node;
               dummy = dummy->next;
        }
        while(carry>0)
        {
               ListNode * new_node = new ListNode(carry%10);
               carry/=10;
               dummy->next = new_node;
               dummy = dummy->next;
        }
        return temp->next;

    }
};