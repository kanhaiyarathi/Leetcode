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
    
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *prev = NULL, *curr = head, *fwd = head->next;
        
        while(curr!=NULL){
            curr->next = prev;
            prev = curr;
            curr = fwd;
            if(fwd!=NULL)
                fwd = fwd->next;
        }
        return prev;
    }
    
    ListNode* mergeListAlternate(ListNode* l1, ListNode* l2){
        
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        
        while(l1!=NULL && l2!=NULL){
            temp->next = l1;
            temp = temp->next;
            l1=l1->next;
            temp->next = l2;
            temp=temp->next;            
            l2=l2->next;            
        }
        if(l1!=NULL)
            temp->next=l1;
        if(l2!=NULL)
            temp->next=l2;
        
        return ans->next;
    }
    
    void printList(ListNode* head, string what){
        cout << what << ":";
        while(head!=NULL){
            cout << head->val << " -> ";
            head = head->next;
        }
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return;
        
        ListNode *prev = NULL, *temp = head, *tempfast = head;
        
        while(tempfast!=NULL && tempfast->next!=NULL){
            prev = temp;
            temp = temp->next;
            tempfast=tempfast->next->next;
        }
        prev->next=NULL;
        ListNode* first = head;
        ListNode* second = temp;
        second = reverseList(second);
        //printList(first, "first");
        //printList(second, "second");
        head = mergeListAlternate(first, second);

    }
};
