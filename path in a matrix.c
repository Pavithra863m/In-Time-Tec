#include <stdio.h>
#include <stdlib.h>

int is_safe(int **matrix, int **visited, int row, int col, int total_rows, int total_cols){
    return row >= 0 && row < total_rows && col >= 0 && col < total_cols && matrix[row][col] == 1 && !visited[row][col];
}

int find_path_with_trace(int **matrix, int **visited, int row, int col, int total_rows, int total_cols, int **path, int step){
    if(row == total_rows - 1 && col == total_cols - 1){
        path[row][col] = step;
        return 1;
    }

    visited[row][col] = 1;
    path[row][col] = step;

    // Move down
    if(is_safe(matrix, visited, row + 1, col, total_rows, total_cols)){
        if(find_path_with_trace(matrix, visited, row + 1, col, total_rows, total_cols, path, step + 1)){
            return 1;
        }
    }

    // Move right
    if(is_safe(matrix, visited, row, col + 1, total_rows, total_cols)){
        if(find_path_with_trace(matrix, visited, row, col + 1, total_rows, total_cols, path, step + 1)){
            return 1;
        }
    }

    // Move up
    if(is_safe(matrix, visited, row - 1, col, total_rows, total_cols)){
        if(find_path_with_trace(matrix, visited, row - 1, col, total_rows, total_cols, path, step + 1)){
            return 1;
        }
    }

    // Move left
    if(is_safe(matrix, visited, row, col - 1, total_rows, total_cols)){
        if(find_path_with_trace(matrix, visited, row, col - 1, total_rows, total_cols, path, step + 1)){
            return 1;
        }
    }

    visited[row][col] = 0;
    path[row][col] = 0;
    return 0;
}

int main() {
    int **matrix, **visited, **path;
    int total_rows, total_cols;

    printf("Enter the number of rows: ");
    scanf("%d", &total_rows);

    printf("Enter the number of columns: ");
    scanf("%d", &total_cols);

    matrix = (int **)malloc(total_rows * sizeof(int *));
    visited = (int **)malloc(total_rows * sizeof(int *));
    path = (int **)malloc(total_rows * sizeof(int *));
    for (int i = 0; i < total_rows; i++) {
        matrix[i] = (int *)malloc(total_cols * sizeof(int));
        visited[i] = (int *)malloc(total_cols * sizeof(int));
        path[i] = (int *)malloc(total_cols * sizeof(int));
    }

    printf("Enter the matrix values (0 or 1):\n");
    int total_values = total_rows * total_cols;
    for(int i = 0; i < total_values; i++){
        int value;
        scanf("%d", &value);
        int row = i / total_cols;
        int col = i % total_cols;
        matrix[row][col] = value;
        visited[row][col] = 0;
        path[row][col] = 0;
    }

    if(matrix[0][0] == 1 && find_path_with_trace(matrix, visited, 0, 0, total_rows, total_cols, path, 1)){
        printf("\nPath exists\n");
        printf("\nPath steps:\n");
        for(int i = 0; i < total_rows; i++){
            for(int j = 0; j < total_cols; j++){
                printf("%d ", path[i][j]);
            }
            printf("\n");
        }
    } 
    else{
        printf("\nNo path exists\n");
    }

    for(int i = 0; i < total_rows; i++){
        free(matrix[i]);
        free(visited[i]);
        free(path[i]);
    }
    free(matrix);
    free(visited);
    free(path);

    return 0;
}
