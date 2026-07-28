/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL){
            return head;
        }
        Node* curr = head;
        while(curr != NULL){
            if(curr->child != NULL){
                // step1 - Flatten the child node
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;
                // step2 - find tail
                while(curr->next != NULL){
                    curr = curr->next;
                }
                // step3 - attach the tail to next ptr
                if(next != NULL){
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};