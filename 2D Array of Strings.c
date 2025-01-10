#include <stdio.h>

int calculate_string_length(const char *string){
    int length = 0;
    while(string[length] != '\0'){
        length++;
    }
    return length;
}


int is_character_vowel(char character){
    if(character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U'){
        return 1;
    }
    return 0;
}


void copy_name(const char *source_name, char *destination_name){
    int i = 0;
    while(source_name[i] != '\0'){
        destination_name[i] = source_name[i];
        i++;
    }
    destination_name[i] = '\0';
}


void input_rows_and_columns(int *rows, int *cols) {
    do{
        printf("Enter number of rows: ");
        scanf("%d", rows);
    }while(*rows < 1 || *rows > 10);

    do{
        printf("Enter number of columns: ");
        scanf("%d", cols);
    }while(*cols < 1 || *cols > 10);
}

void input_names(int rows, int cols, char names[10][51], int *vowel_start_count, char *longest_name, int *max_length){
    char name[51];

    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            printf("Name at (%d,%d): ", row, col);
            scanf("%s", name);

            copy_name(name, names[row * cols + col]);

            if(is_character_vowel(name[0])){
                (*vowel_start_count)++;
            }

            int length = calculate_string_length(name);
            if(length > *max_length){
                *max_length = length;
                copy_name(name, longest_name);
            }
        }
    }
}

void print_names(int rows, int cols, char names[10][51]) {
    printf("\nThe 2D array of names is:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%s\t", names[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    int vowel_start_count = 0, max_length = 0;
    char names[100][51];
    char longest_name[51];

    input_rows_and_columns(&rows, &cols);

    input_names(rows, cols, names, &vowel_start_count, longest_name, &max_length);

    print_names(rows, cols, names);

    printf("\nNumber of names starting with a vowel: %d\n", vowel_start_count);
    printf("The longest name: %s\n", longest_name);

    return 0;
}
