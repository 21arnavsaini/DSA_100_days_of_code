#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newnode = createNode(data);
    if(head == NULL) {
        return newnode;
    }
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}
void traverseReverse(struct Node* head) {
    if(head == NULL) return;
    traverseReverse(head->next);
    printf("%d ", head->data);
}
int main() {
    struct Node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    traverseReverse(head);
    printf("\n");
    return 0;
}
