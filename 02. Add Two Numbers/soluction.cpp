/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a = 0, b = 0, sum = 0, carry = 0, val = 0;

        ListNode *l1Ptr = l1;
        ListNode *l2Ptr = l2;
        ListNode *l3Ptr = new ListNode(0);
        ListNode *topPtr = l3Ptr;

        while (true) {
            a = b = sum = 0;

            if (l1Ptr != NULL) {
                a = l1Ptr->val;
                l1Ptr = l1Ptr->next;
            }

            if (l2Ptr != NULL) {
                b = l2Ptr->val;
                l2Ptr = l2Ptr->next;
            }

            sum = a + b + carry;
            carry = sum / 10;
            val = sum % 10;
            
            l3Ptr->val = val;
            
            if (l1Ptr == NULL && l2Ptr == NULL && carry == 0) {
                break;
            }

            l3Ptr->next = new ListNode(0); 
            l3Ptr = l3Ptr->next;
        }

        return topPtr; 
    }
};