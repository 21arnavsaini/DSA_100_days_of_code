#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[100000];
    int freq[200001] = {0};
    int max_val = -1000000, min_val = 1000000;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[arr[i] + 100000]++;
        if (arr[i] > max_val) max_val = arr[i];
        if (arr[i] < min_val) min_val = arr[i];
    }

    int first = 1;
    for (int x = min_val; x <= max_val; x++) {
        if (freq[x + 100000] > 0) {
            if (!first) printf(" ");
            printf("%d:%d", x, freq[x + 100000]);
            first = 0;
        }
    }
    printf("\\n");
    return 0;
}
