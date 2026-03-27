#include <stdio.h>
#include <stdlib.h>
struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    if(pos == 0) {
        struct Node* newnode = createNode(data);
        newnode->next = head;
        if(head) head->prev = newnode;
        return newnode;
    }
    struct Node* temp = head;
    for(int i = 0; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    struct Node* newnode = createNode(data);
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    if(temp->next) temp->next->prev = newnode;
    return head;
}
void display(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    struct Node* head = NULL;
    head = insertAtPosition(head, 10, 0);
    head = insertAtPosition(head, 20, 1);
    head = insertAtPosition(head, 30, 2);
    head = insertAtPosition(head, 25, 2);
    display(head);
    return 0;
}

