/*Read a string and check if it is a palindrome using two-pointer comparison.*/
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000]; // Buffer to store the input string
    scanf("%s", s);

    int left = 0;
    int right = strlen(s) - 1;
    int isPalindrome = 1; // 1 represents YES

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0; // 0 represents NO
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}