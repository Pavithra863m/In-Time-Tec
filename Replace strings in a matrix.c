#include <stdio.h>
#include <stdlib.h>

int compare_strings(char *str1, char *str2){
    while (*str1 && *str2){
        if (*str1 != *str2){
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1 == *str2);
}

void replace_string(char *str, char *target, char *replace){
    int i = 0, j, k;
    while (str[i] != '\0'){
        j = 0;
        while(target[j] == str[i + j] && target[j] != '\0'){
            j++;
        }
        if(target[j] == '\0'){
            k = 0;
            while(replace[k] != '\0'){
                str[i + k] = replace[k];
                k++;
            }
            str[i + k] = '\0';
        }
        i++;
    }
}

int main(){
    int row_count, column_count;
    char target_string[20], new_string[20];

    printf("Enter the number of rows: ");
    scanf("%d", &row_count);
    printf("Enter the number of columns: ");
    scanf("%d", &column_count);

    char ***matrix = (char ***)malloc(row_count * sizeof(char **));
    for(int row_index = 0; row_index < row_count; row_index++){
        matrix[row_index] = (char **)malloc(column_count * sizeof(char *));
        for(int column_index = 0; column_index < column_count; column_index++){
            matrix[row_index][column_index] = (char *)malloc(20 * sizeof(char));
        }
    }

    printf("Enter the matrix elements:\n");
    for(int row_index = 0; row_index < row_count; row_index++){
        for(int column_index = 0; column_index < column_count; column_index++){
            scanf("%s", matrix[row_index][column_index]);
        }
    }

    printf("Enter the target string: ");
    scanf("%s", target_string);
    printf("Enter the new string: ");
    scanf("%s", new_string);

    for(int row_index = 0; row_index < row_count; row_index++){
        for(int column_index = 0; column_index < column_count; column_index++){
            if(compare_strings(matrix[row_index][column_index], target_string)){
                replace_string(matrix[row_index][column_index], target_string, new_string);
            }
        }
    }

    printf("Modified matrix:\n");
    for(int row_index = 0; row_index < row_count; row_index++){
        for(int column_index = 0; column_index < column_count; column_index++){
            printf("%s ", matrix[row_index][column_index]);
        }
        printf("\n");
    }

    for(int row_index = 0; row_index < row_count; row_index++){
        for(int column_index = 0; column_index < column_count; column_index++){
            free(matrix[row_index][column_index]);
        }
        free(matrix[row_index]);
    }
    free(matrix);

    return 0;
}
