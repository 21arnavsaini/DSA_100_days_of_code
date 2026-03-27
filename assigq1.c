#include <stdio.h>
int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5, i;
    for(i = n; i > 1; i--) {
        arr[i] = arr[i-1];
    }
    arr[1] = 25;
    n++;
    printf("After Insertion(%d): ", n);
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    for(i = 4; i < n; i++) {
        arr[i] = arr[i+1];
    }
    n--;
    printf("\nAfter Deletion(%d): ", n);
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
