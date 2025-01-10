#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 100

int compare_strings(const char *string1, const char *string2){

    while(*string1 != '\0' && *string2 != '\0'){
        if(*string1 != *string2) {
            return 0;
        }
        string1++;
        string2++;
    }
    return(*string1 == '\0' && *string2 == '\0');

}

int main(){

    int number_of_rows, number_of_columns;
    char search_string[MAX_STRING_LENGTH];

    printf("Enter the number of rows: ");
    scanf("%d", &number_of_rows);

    printf("Enter the number of columns: ");
    scanf("%d", &number_of_columns);

    char ***matrix = (char ***)malloc(number_of_rows * sizeof(char **));

    for(int row_index = 0; row_index < number_of_rows; row_index++){
        matrix[row_index] = (char **)malloc(number_of_columns * sizeof(char *));
        
        for(int column_index = 0; column_index < number_of_columns; column_index++){
            matrix[row_index][column_index] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        }
    }

    printf("Enter the Strings for the matrix:\n");
    for(int row_index = 0; row_index < number_of_rows; row_index++){
        for(int column_index = 0; column_index < number_of_columns; column_index++){
            scanf("%s", matrix[row_index][column_index]);
        }
    }

    printf("Enter a string: ");
    scanf("%s", search_string);

    int is_found = 0;
    for(int row_index = 0; row_index < number_of_rows; row_index++){
        for(int column_index = 0; column_index < number_of_columns; column_index++){
            if(compare_strings(matrix[row_index][column_index], search_string)){
                printf("String Found\n");
                is_found = 1;
                break;
            }
        }
        
        if(is_found){
            break;
        }
    }

    if(!is_found){
        printf("String Not found\n");
    }

    for(int row_index = 0; row_index < number_of_rows; row_index++){
        for(int column_index = 0; column_index < number_of_columns; column_index++){
            free(matrix[row_index][column_index]);
        }
        free(matrix[row_index]);
    }
    free(matrix);

    return 0;
}
