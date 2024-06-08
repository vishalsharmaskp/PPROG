#ifndef DETERMINANT_H
#define DETERMINANT_H

double* allocate_matrix(int N);
void free_matrix(double* matrix);
int map_to_superindex(int i, int j, int N);
void map_to_indices(int a, int N, int *i, int *j);
void generate_minor(double* matrix, double* minor, int N, int row, int col);
double determinant(double* matrix, int N);

#endif