/* Given an array of integers, rotate the array to the right by k positions.*/
#include <stdio.h>
#define MAXN 100
int arr[MAXN];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int k;
    scanf("%d",&k);
    k%=n;
    for(int i=0;i<k;i++){
        int last=arr[n-1];
        for(int j=n-1;j>0;j--) arr[j]=arr[j-1];
        arr[0]=last;
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        if(i<n-1) printf(" ");
    }
    printf("\n");
    return 0;
}
