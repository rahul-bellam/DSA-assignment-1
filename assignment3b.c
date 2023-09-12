#include <stdio.h>

void subtractSparseMatrices(int A[][3], int B[][3], int k) {
    int result[100][3];
    int i = 0, j = 0, r = 0;

    while (i < k && j < k) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            result[r][0] = A[i][0];
            result[r][1] = A[i][1];
            result[r][2] = A[i][2];
            i++;
        } else if (A[i][0] > B[j][0] || (A[i][0] == B[j][0] && A[i][1] > B[j][1])) {
            result[r][0] = B[j][0];
            result[r][1] = B[j][1];
            result[r][2] = -B[j][2]; // Subtract B's value
            j++;
        } else {
            result[r][0] = A[i][0];
            result[r][1] = A[i][1];
            result[r][2] = A[i][2] - B[j][2]; // Subtract B's value
            i++;
            j++;
        }
        r++;
    }

    while (i < k) {
        result[r][0] = A[i][0];
        result[r][1] = A[i][1];
        result[r][2] = A[i][2];
        i++;
        r++;
    }

    while (j < k) {
        result[r][0] = B[j][0];
        result[r][1] = B[j][1];
        result[r][2] = -B[j][2]; // Negate B's value
        j++;
        r++;
    }

    printf("Resultant Sparse Matrix after Subtraction:\n");
    for (int x = 0; x < r; x++) {
        printf("%d %d %d\n", result[x][0], result[x][1], result[x][2]);
    }
}

int main() {
    int k;
    printf("Enter the value of k (number of non-zero elements): ");
    scanf("%d", &k);

    int A[100][3], B[100][3];

    printf("Enter elements of A[k][3] in the format [row] [column] [value]:\n");
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }

    printf("Enter elements of B[k][3] in the format [row] [column] [value]:\n");
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);
    }

    subtractSparseMatrices(A, B, k);

    return 0;
}
