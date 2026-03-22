/*Given an array of integers, find two elements whose sum is closest to zero*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int best_i = 0, best_j = 1;
    int min_abs = abs(arr[0] + arr[1]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int s = arr[i] + arr[j];
            int abs_s = abs(s);
            if (abs_s < min_abs) {
                min_abs = abs_s;
                best_i = i;
                best_j = j;
            }
        }
    }

    if (best_i > best_j) {
        int t = best_i;
        best_i = best_j;
        best_j = t;
    }
    printf("%d %d\n", arr[best_i], arr[best_j]);
    return 0;
}
