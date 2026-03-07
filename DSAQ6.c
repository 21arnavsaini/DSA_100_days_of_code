/*
Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
*/
#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int n;
    scanf("%d", &n);
    int arr[MAX_SIZE];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int j = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            arr[++j] = arr[i];
        }
    }
    int new_size = j + 1;
    for(int i = 0; i < new_size; i++) {
        printf("%d", arr[i]);
        if(i + 1 < new_size) printf(" ");
    }
    printf("\n");
    return 0;
}
