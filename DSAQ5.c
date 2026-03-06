/*A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. 
Your task is to create a single chronological log that preserves the correct order of arrivals.*/
#include <stdio.h>
#define MAX_SIZE 1000

int main() {
    int p;
    scanf("%d", &p);
    int a[MAX_SIZE];
    for(int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }
    int q;
    scanf("%d", &q);
    int b[MAX_SIZE];
    for(int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }
    int res[MAX_SIZE * 2];
    int i = 0, j = 0, k = 0;
    while(i < p && j < q) {
        if(a[i] <= b[j]) {
            res[k++] = a[i++];
        } else {
            res[k++] = b[j++];
        }
    }
    while(i < p) {
        res[k++] = a[i++];
    }
    while(j < q) {
        res[k++] = b[j++];
    }
    for(int x = 0; x < k; x++) {
        printf("%d", res[x]);
        if(x + 1 < k) printf(" ");
    }
    printf("\n");
    return 0;
}
