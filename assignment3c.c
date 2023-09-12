#include <stdio.h>

void multiplySparseMatrices(int A[][3], int B[][3], int k1, int k2) {
    int result[100][3];
    int r = 0;

    for (int i = 0; i < k1; i++) {
        for (int j = 0; j < k2; j++) {
            if (A[i][1] == B[j][0]) {
                result[r][0] = A[i][0];
                result[r][1] = B[j][1];
                result[r][2] = A[i][2] * B[j][2];
                r++;
            }
        }
    }

    printf("Resultant Sparse Matrix after Multiplication:\n");
    for (int x = 0; x < r; x++) {
        printf("%d %d %d\n", result[x][0], result[x][1], result[x][2]);
    }
}

int main() {
    int k1, k2;
    printf("Enter the value of k1 (number of non-zero elements in matrix A): ");
    scanf("%d", &k1);

    printf("Enter the value of k2 (number of non-zero elements in matrix B): ");
    scanf("%d", &k2);

    int A[100][3], B[100][3];

    printf("Enter elements of A[k1][3] in the format [row] [column] [value]:\n");
    for (int i = 0; i < k1; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }

    printf("Enter elements of B[k2][3] in the format [row] [column] [value]:\n");
    for (int i = 0; i < k2; i++) {
        scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);
    }

    if (k1 > 0 && k2 > 0 && A[k1 - 1][1] == B[k2 - 1][0]) {
        multiplySparseMatrices(A, B, k1, k2);
    } else {
        printf("Matrix multiplication is not possible due to incompatible dimensions.\n");
    }

    return 0;
}
