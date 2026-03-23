/*Given an array of integers, count the number of subarrays whose sum is equal to zero.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUM 100
#define HT_SIZE 100

typedef struct Node {
    long long key;
    long long val;
    struct Node* next;
} Node;

Node* ht[HT_SIZE];

unsigned long myhash(long long k) {
    return (unsigned long)((k + MAX_SUM) % HT_SIZE);
}

long long get_freq(long long k) {
    unsigned long idx = myhash(k);
    Node* node = ht[idx];
    while (node) {
        if (node->key == k) return node->val;
        node = node->next;
    }
    return 0;
}

void update_freq(long long k, long long v) {
    unsigned long idx = myhash(k);
    Node* node = ht[idx];
    while (node) {
        if (node->key == k) {
            node->val = v;
            return;
        }
        node = node->next;
    }
    // Insert new
    Node* newn = (Node*)malloc(sizeof(Node));
    newn->key = k;
    newn->val = v;
    newn->next = ht[idx];
    ht[idx] = newn;
}

void clear_ht() {
    for (int i = 0; i < HT_SIZE; i++) {
        Node* node = ht[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
        ht[i] = NULL;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    long long a[100001];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    memset(ht, 0, sizeof(ht));
    update_freq(0, 1);  // Empty prefix

    long long sum = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans += get_freq(sum);
        long long curr_freq = get_freq(sum) + 1;
        update_freq(sum, curr_freq);
    }

    printf("%lld\n", ans);
    clear_ht();  // Cleanup
    return 0;
}
