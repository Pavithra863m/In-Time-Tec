#include <stdio.h>
#include <stdlib.h>

void rotate_matrix_90_degree(char ***matrix, char ***rotated_matrix, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            rotated_matrix[j][rows - 1 - i] = matrix[i][j];
        }
    }
}

void print_matrix(char ***matrix, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%s ", matrix[i][j]);
        }
        printf("\n");
    }
}

char*** allocate_matrix(int rows, int cols){
    char ***matrix = (char ***)malloc(rows * sizeof(char **));
    for(int i = 0; i < rows; i++){
        matrix[i] = (char **)malloc(cols * sizeof(char *));
        for(int j = 0; j < cols; j++){
            matrix[i][j] = (char *)malloc(100 * sizeof(char)); 
        }
    }
    return matrix;
}

int main(){
    int rows, cols;
    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    char ***matrix = allocate_matrix(rows, cols);
    char ***rotated_matrix = allocate_matrix(cols, rows);

    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf("%s", matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    print_matrix(matrix, rows, cols);

    rotate_matrix_90_degree(matrix, rotated_matrix, rows, cols);

    printf("\nRotated Matrix:\n");
    print_matrix(rotated_matrix, cols, rows);

    for(int i = 0; i < rows; i++){
        free(matrix[i]);
    }
    free(matrix);

    for(int i = 0; i < cols; i++){
        free(rotated_matrix[i]);
    }
    free(rotated_matrix);

    return 0;
}
