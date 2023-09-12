#include <stdio.h>
#include <math.h>

void powerSparseMatrix(int A[][3], int k, int n) {
    for (int i = 0; i < k; i++) {
        A[i][2] = pow(A[i][2], n);
    }

    printf("Sparse Matrix after Raising to the Power %d:\n", n);
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", A[i][0], A[i][1], A[i][2]);
    }
}

int main() {
    int k, n;
    printf("Enter the value of k (number of non-zero elements): ");
    scanf("%d", &k);

    printf("Enter the value of n for power operation: ");
    scanf("%d", &n);

    int A[100][3];

    printf("Enter elements of A[k][3] in the format [row] [column] [value]:\n");
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }

    powerSparseMatrix(A, k, n);

    return 0;
}
