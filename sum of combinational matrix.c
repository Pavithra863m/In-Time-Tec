#include <stdio.h>
#include <stdlib.h>

void allocate_matrix(char ***matrix, int number_of_rows, int number_of_columns){
    *matrix = (char **)malloc(number_of_rows * sizeof(char *));
    for(int row_index = 0; row_index < number_of_rows; row_index++){
        (*matrix)[row_index] = (char *)malloc(number_of_columns * sizeof(char));
    }
}

void free_matrix(char **matrix, int number_of_rows){
    for(int row_index = 0; row_index < number_of_rows; row_index++){
        free(matrix[row_index]);
    }
    free(matrix);
}

void input_matrix(char **matrix, int number_of_rows, int number_of_columns){
    for(int row_index = 0; row_index < number_of_rows; row_index++){
        for(int column_index = 0; column_index < number_of_columns; column_index++){
            scanf(" %c", &matrix[row_index][column_index]);
        }
    }
}

int sum_matrix_elements(char **matrix, int number_of_rows, int number_of_columns){
    int sum_of_elements = 0;
    for(int row_index = 0; row_index < number_of_rows; row_index++){
        for(int column_index = 0; column_index < number_of_columns; column_index++){
            if(matrix[row_index][column_index] >= '0' && matrix[row_index][column_index] <= '9'){
                sum_of_elements += matrix[row_index][column_index] - '0';
            } 
            else{
                sum_of_elements += (int)matrix[row_index][column_index];
            }
        }
    }
    return sum_of_elements;
}

int main(){
    int number_of_rows, number_of_columns;
    
    printf("Enter the number of rows: ");
    scanf("%d", &number_of_rows);

    printf("Enter the number of columns: ");
    scanf("%d", &number_of_columns);

    char **matrix;
    allocate_matrix(&matrix, number_of_rows, number_of_columns);

    printf("Enter the matrix elements:\n");
    input_matrix(matrix, number_of_rows, number_of_columns);

    int sum_of_elements = sum_matrix_elements(matrix, number_of_rows, number_of_columns);
    
    printf("Sum of the integers and characters in the matrix: %d\n", sum_of_elements);

    free_matrix(matrix, number_of_rows);

    return 0;
}
