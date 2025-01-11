#include <stdio.h>
#include <stdlib.h>

void set_zero_matrix(int **matrix, int num_rows, int num_columns){
    int *rows_to_zero = (int *)malloc(num_rows * sizeof(int));
    int *columns_to_zero = (int *)malloc(num_columns * sizeof(int));

    for(int i = 0; i < num_rows; i++){
        rows_to_zero[i] = 0;
    }
    for(int j = 0; j < num_columns; j++){
        columns_to_zero[j] = 0;
    }

    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_columns; j++){
            if(matrix[i][j] == 0){
                rows_to_zero[i] = 1;
                columns_to_zero[j] = 1;
            }
        }
    }

    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_columns; j++){
            if(rows_to_zero[i] == 1 || columns_to_zero[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }

    free(rows_to_zero);
    free(columns_to_zero);
}

void print_matrix(int **matrix, int num_rows, int num_columns){
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_columns; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int num_rows, num_columns;
    printf("Enter the number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter the number of columns: ");
    scanf("%d", &num_columns);

    int **matrix = (int **)malloc(num_rows * sizeof(int *));
    for(int i = 0; i < num_rows; i++){
        matrix[i] = (int *)malloc(num_columns * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_columns; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Original Matrix:\n");
    print_matrix(matrix, num_rows, num_columns);

    set_zero_matrix(matrix, num_rows, num_columns);

    printf("\nMatrix after change:\n");
    print_matrix(matrix, num_rows, num_columns);

    for(int i = 0; i < num_rows; i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
