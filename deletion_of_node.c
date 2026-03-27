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
    newnode->prev = temp;
    return head;
}
struct Node* deleteByValue(struct Node* head, int key) {
    struct Node* temp = head;
    while(temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if(temp == NULL) return head;
    if(temp->prev == NULL) {
        head = temp->next;
    } else {
        temp->prev->next = temp->next;
    }
    if(temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
    return head;
}
void display(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    display(head);
    head = deleteByValue(head, 20);
    display(head);
    return 0;
}
