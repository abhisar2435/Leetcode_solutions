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
        if(head==nullptr || k==1) return head;
        vector<ListNode*> x;
        ListNode* temp=head;
        while(temp!=nullptr){
            x.push_back(temp);
            temp=temp->next;
        }
        for(int i=0;i+k<=x.size();i+=k){
            reverse(x.begin()+i, x.begin()+i+k);
        }
        for(int i=1;i<x.size();i++){
            x[i-1]->next=x[i];
        }
        x.back()->next=nullptr;
        return x[0];
    }
};