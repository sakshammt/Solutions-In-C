/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* merged = NULL;
    struct ListNode* t = NULL;
    if(list1==NULL)
    return list2;

    if(list2==NULL)
    return list1;
    
    if(list1->val < list2->val){
        merged = list1;
        list1=list1->next;
    }
    else{
        merged = list2;
        list2 = list2->next;
    }

    t=merged;

    while(list1!=NULL && list2!= NULL){
        if(list1->val <= list2->val){
            merged->next = list1;
            list1 = list1->next;
            merged = merged->next;
            continue;
        }
        else{
            merged->next = list2;
            list2 = list2->next;
            merged = merged->next;
            continue;
        }
    }

    if(list1!=NULL)
    {
        merged->next=list1;
    }
    else if(list2!=NULL){
        merged->next=list2;
    }

    return t;}
