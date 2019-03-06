struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    if (headA == NULL || headB == NULL) {  return NULL; }
    
    int lengthA  = 0;
    struct ListNode *temp = headA;
    while (temp != NULL) {
        lengthA++;
        temp = temp->next;
    }
    
    int lengthB  = 0;
    temp = headB;
    while (temp != NULL) {
        lengthB++;
        temp = temp->next;
    }

    if(lengthA > lengthB) {
        for(int i =  0; i < lengthA - lengthB; i++) {
            headA = headA->next;
        }
    }else {
         for(int i =  0; i < lengthB - lengthA; i++) {
            headB = headB->next;
        }
    }
    
     while(headA != NULL) {
        if(headA == headB) {
            return headA;
        }else{
            headA = headA->next;
            headB = headB->next;
        }
    }
    return NULL;
}