#include <stdio.h>
#include <stdlib.h>

int main(){
    int num_rows, num_cols;

    printf("Enter number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter number of columns: ");
    scanf("%d", &num_cols);

    char ***matrix = (char ***)malloc(num_rows * sizeof(char **));
    
    
    printf("Enter string matrix:\n");
    for(int row = 0; row < num_rows; row++){
        matrix[row] = (char **)malloc(num_cols * sizeof(char *));
        for(int col = 0; col < num_cols; col++){
            matrix[row][col] = (char *)malloc(100 * sizeof(char));
            scanf("%s", matrix[row][col]);
        }
    }

    printf("Snake Traversal of the matrix:\n");

    for(int row = 0; row < num_rows; row++){
        if(row % 2 == 0){
            for(int col = 0; col < num_cols; col++){
                printf("%s ", matrix[row][col]);
            }
        } 
        else{
            for(int col = num_cols - 1; col >= 0; col--){
                printf("%s ", matrix[row][col]);
            }
        }
    }

    for(int row = 0; row < num_rows; row++){
        for(int col = 0; col < num_cols; col++){
            free(matrix[row][col]);
        }
        free(matrix[row]);
    }
    free(matrix);

    return 0;
}
