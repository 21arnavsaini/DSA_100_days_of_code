/*A secret system stores code names in forward order. To display them in mirror format, 
you must transform the given code name so that its characters appear in the opposite order.*/
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
    printf("%s\n", s);
    return 0;
}
