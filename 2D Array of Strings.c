#include <stdio.h>

// Function to calculate the length of a string
int calculate_string_length(const char *string){
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

// Function to check if a character is a vowel
int is_character_vowel(char character){
    if(character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U'){
        return 1;
    }
    return 0;
}

// Function to copy a name into the longest names array
void copy_name(char source_name[], char destination_name[]){
    int i = 0;
    while(source_name[i] != '\0'){
        destination_name[i] = source_name[i];
        i++;
    }
    destination_name[i] = '\0';
}

int main(){
    int number_of_rows, number_of_columns;
    int row_index, column_index, index = 0;
    int vowel_start_count = 0, maximum_name_length = 0;
    char names[10][10][51];
    char longest_names[10][51];

    do{
        printf("Enter number of rows: ");
        scanf("%d", &number_of_rows);
    }while(number_of_rows < 1 || number_of_rows > 10);

    do{
        printf("\nEnter number of columns: ");
        scanf("%d", &number_of_columns);
    }while(number_of_columns < 1 || number_of_columns > 10);

    for(row_index = 0; row_index < number_of_rows; row_index++){
        for(column_index = 0; column_index < number_of_columns; column_index++){
            printf("\nName at (%d,%d): ", row_index, column_index);
            scanf("%s", names[row_index][column_index]);

            // Counting the number of names starting with vowels
            if(is_character_vowel(names[row_index][column_index][0])){
                vowel_start_count++;
            }

            int name_length = calculate_string_length(names[row_index][column_index]);

            // Finding Longest names
            if(name_length > maximum_name_length){
                maximum_name_length = name_length;
                index = 0;
                copy_name(names[row_index][column_index], longest_names[index]);
                index++;
            }
            else if(name_length == maximum_name_length){
                copy_name(names[row_index][column_index], longest_names[index]);
                index++;
            }
        }
    }

    // Printing the names in 2D array
    printf("\nThe 2D array of names is:\n");
    for(row_index = 0; row_index < number_of_rows; row_index++){
        for(column_index = 0; column_index < number_of_columns; column_index++){
            printf("%s\t", names[row_index][column_index]);
        }
        printf("\n");
    }


    printf("\nNumber of names starting with a vowel: %d\n", vowel_start_count);

    // Print longest names
    printf("\nThe Longest names: ");
    for (int i = 0; i < index; i++) {
        printf("%s\n", longest_names[i]);
    }

    return 0;
}
