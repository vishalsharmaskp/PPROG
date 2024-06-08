# include <stdio.h>
# include <math.h>
# include "determinant.h"

int main() {
    int N = 3;
    double* matrix = allocate_matrix(N);
    
    double alpha = M_PI/3;
    double beta = M_PI/3;
    double gamma = M_PI/4;

    double values[] = {
        cos(alpha)*cos(beta), cos(alpha)*sin(beta)*sin(gamma) - sin(alpha)*cos(gamma), cos(alpha)*sin(beta)*cos(gamma) + sin(alpha)*sin(gamma),
        sin(alpha)*cos(beta), sin(alpha)*sin(beta)*sin(gamma) + cos(alpha)*cos(gamma), sin(alpha)*sin(beta)*cos(gamma) - cos(alpha)*sin(gamma),
        -sin(beta), cos(beta)*sin(gamma), cos(beta)*cos(gamma)
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[map_to_superindex(i, j, N)] = values[map_to_superindex(i, j, N)];
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         if (i == j) {
    //             matrix[map_to_superindex(i, j, N)] = i + 2  ; // or any non-zero value
    //         } else {
    //             matrix[map_to_superindex(i, j, N)] = 0;
    //         }
    //     }
    // }

    double det = determinant(matrix, N);
    printf("Determinant: %f\n", det);

    free_matrix(matrix);

    return 0;
}
