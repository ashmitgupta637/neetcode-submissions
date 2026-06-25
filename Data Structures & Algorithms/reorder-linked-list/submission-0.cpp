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
    void reorderList(ListNode* head) {
        if(head == nullptr) {
            return ; 
        }

        
        ListNode* slow  = head  ; 
        ListNode* fast = head ; 
        
        while(fast!= nullptr && fast->next != nullptr ) {
            slow = slow->next ; 
            fast = fast->next->next ; 

        }
        ListNode* mid = slow->next ; 
        slow->next = nullptr ; 

        ListNode* prev = NULL ; 
        ListNode* curr = mid ; 
        while(curr != nullptr) {
            ListNode* temp = curr->next ; 
            
            curr->next = prev   ; 
            prev = curr ; 
            curr = temp ; 

            
        }
        ListNode* temp1 = head  ; 
        while(prev != nullptr ) {
            
            ListNode* temp2 = temp1->next ; 
            ListNode* temp3  =prev->next ; 
            temp1->next  = prev ; 
             
            prev->next = temp2 ; 
            temp1 = temp2 ;  ; 
            prev = temp3  ; 

        }
        
          


        
        
    }
};