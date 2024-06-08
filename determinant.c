#include <stdio.h>
#include <stdlib.h>
# include "determinant.h"

// Function to allocate memory for an N x N matrix
double* allocate_matrix(int N) {
    printf("Allocating memory for a %d x %d matrix\n", N, N);
    double* matrix = (double*)malloc(N * N * sizeof(double));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return matrix;
}

// Function to free the memory of a matrix
void free_matrix(double* matrix) {
    free(matrix);
}

// Function to map (i, j) to a
int map_to_superindex(int i, int j, int N) {
    return i * N + j;
}

// Function to map a to (i, j)
void map_to_indices(int a, int N, int *i, int *j) {
    *i = a / N;
    *j = a % N;
}

// Function to generate the minor of a matrix
void generate_minor(double* matrix, double* minor, int N, int row, int col) {
    int minorRow = 0, minorCol = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != row && j != col) {
                minor[map_to_superindex(minorRow, minorCol, N - 1)] = matrix[map_to_superindex(i, j, N)];
                minorCol++;
                if (minorCol == N - 1) {
                    minorCol = 0;
                    minorRow++;
                }
            }
        }
    }
}


// Function to calculate the determinant of a matrix
double determinant(double* matrix, int N) {
    if (N == 1) {
        return matrix[0];
    } else if (N == 2) {
        return matrix[0] * matrix[3] - matrix[1] * matrix[2];
    } else {
        double det = 0.0;
        double* minor = allocate_matrix(N - 1);
        for (int j = 0; j < N; j++) {
            generate_minor(matrix, minor, N, 0, j);
            det += ((j % 2 == 0) ? 1.0 : -1.0) * matrix[j] * determinant(minor, N - 1);
        }
        free_matrix(minor);
        return det;
    }
}

