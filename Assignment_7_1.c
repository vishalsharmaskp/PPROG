# include <stdio.h> 

// void changeMatrix(int matrix[][3], int , int ); 
void changeMatrix(int (*matrix)[3], int rows, int columns);
// void changeMatrix(int *matrix[3], int rows, int columns);

int main(){

    int M[2][3] = {{1, 2, 3},
                 {4, 5, 6}};

    printf("matrix element printing with arrary notation\n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", M[i][j]);
        }
    printf("\n");
    }

    
    int (*M_ptr_1)[3] = M; // pointer to an array of 3 integers
    int *M_ptr_2 = &M[0][0];  
    int (*M_ptr_3)[2][3] = &M; // pointer to a 2D array of 2 rows and 3 columns
    // int **M_ptr_3 = M;  // double pointer to an integer (suitable for a dynamic 2D array)

    changeMatrix(M , 2, 3);
    // changeMatrix(M_ptr_1 , 2, 3);

    // printf("%p\n", p) ;
    // printf("%p\n", p + 1) ;
    // printf("%p\n", p + 2) ;
    
    printf("matrix element printing with pointer notation\n");

    for (int i = 0; i < 2; ++i) {  // assuming there are 2 rows
        for (int j = 0; j < 3; ++j) {  // assuming there are 3 columns
            printf("%d ", (*M_ptr_1)[j] );  // prints the j-th element of the i-th row
        }
        M_ptr_1++;  // move to the next row
        printf("\n");
    }

    printf("matrix element printing with double pointer notation\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\n", *(M_ptr_2 + i * 3 + j));  // prints the j-th element of the i-th row
        }
    }

    printf("Size of M is %lu\n" , sizeof(M));
    printf("size of M[0] is %lu\n", sizeof(M[0]));
    printf("size of M[0][0] is %lu\n", sizeof(M[0][0]));
    // printf("size of pointers are")
    printf("Size of M_ptr_1 is %lu\n", sizeof(M_ptr_1));
    printf("Size of *M_ptr_1 is %lu\n", sizeof(*M_ptr_1));
    printf("Size of M_ptr_2 is %lu\n", sizeof(M_ptr_2));

    return 0;

}


// void changeMatrix( int matrix[][3] , int rows , int columns ) {
//     printf ("In changeMatrix :\n") ;
//     printf (" sizeof ( matrix ) = %lu\n", sizeof matrix ) ;
//     printf (" sizeof ( matrix [0]) = %lu\n", sizeof matrix[0]) ;
//     printf (" sizeof ( matrix [0][0]) = %lu\n", sizeof matrix[0][0]) ;
//     if(rows >1)
//         matrix [1][0]=111;
//     matrix = NULL ;
// }

void changeMatrix( int (*matrix)[3] , int rows , int columns ) {
    printf ("In changeMatrix :\n") ;
    printf (" sizeof ( matrix ) = %lu\n", sizeof matrix ) ;
    printf (" sizeof ( matrix [0]) = %lu\n", sizeof matrix[0]) ;
    printf (" sizeof ( matrix [0][0]) = %lu\n", sizeof matrix[0][0]) ;
    if(rows >1)
        matrix [1][0]=111;
    matrix = NULL ;
}
