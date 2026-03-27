#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int power;
    struct Node* next;
};
struct Node* createNode(int coeff, int power) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = NULL;
    return newnode;
}
struct Node* insertEnd(struct Node* head, int coeff, int power) {
    struct Node* newnode = createNode(coeff, power);
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
struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    while(p1 != NULL && p2 != NULL) {
        if(p1->power > p2->power) {
            result = insertEnd(result, p1->coeff, p1->power);
            p1 = p1->next;
        } else if(p2->power > p1->power) {
            result = insertEnd(result, p2->coeff, p2->power);
            p2 = p2->next;
        } else {
            result = insertEnd(result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while(p1 != NULL) {
        result = insertEnd(result, p1->coeff, p1->power);
        p1 = p1->next;
    }
    while(p2 != NULL) {
        result = insertEnd(result, p2->coeff, p2->power);
        p2 = p2->next;
    }
    return result;
}
void display(char* label, struct Node* head) {
    printf("%s: ", label);
    struct Node* temp = head;
    while(temp != NULL) {
        if(temp != head) printf("+");
        printf("%dx^%d", temp->coeff, temp->power);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Node* p1 = NULL;
    struct Node* p2 = NULL;
    p1 = insertEnd(p1, 5, 3);
    p1 = insertEnd(p1, 3, 2);
    p1 = insertEnd(p1, 2, 0);
    p2 = insertEnd(p2, 4, 2);
    p2 = insertEnd(p2, 7, 1);
    p2 = insertEnd(p2, 1, 0);
    display("P1", p1);
    display("P2", p2);
    struct Node* result = addPolynomials(p1, p2);
    display("Result", result);
    return 0;
}
