class Solution 
{
    public:
        ListNode* reverseList(ListNode* head) 
        {
            ListNode* prev=NULL;
            ListNode* cur=head;
            ListNode* n;
            while(cur!=NULL)
            {
                n=cur->next;
                cur->next=prev;
                prev=cur;
                cur=n;
            }
            return prev;
        }
};
