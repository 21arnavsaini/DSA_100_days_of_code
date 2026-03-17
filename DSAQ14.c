/* Write a program to check whether a given square matrix is an 
Identity Matrix. An identity matrix is a square matrix in which all
 diagonal elements are 1 and all non-diagonal elements are 0.*/
 #include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int mat[100][100];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    int isIdentity = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) {
                if(mat[i][j] != 1) {
                    isIdentity = 0;
                }
            } else {
                if(mat[i][j] != 0) {
                    isIdentity = 0;
                }
            }
        }
    }
    if(isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }
    return 0;
}
