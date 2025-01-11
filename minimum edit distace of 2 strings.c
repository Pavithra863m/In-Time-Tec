#include <stdio.h>
#include <stdlib.h>

int find_min(int option1, int option2, int option3){
    if(option1 <= option2 && option1 <= option3){
        return option1;
    }
    if(option2 <= option1 && option2 <= option3){
        return option2;
    }
    return option3;
}

int calculate_edit_distance(char *first_string, char *second_string){
    int first_string_length = 0;
    int second_string_length = 0;
    int minimum_edit_distance;
    int *current_row, *previous_row;

    while(first_string[first_string_length] != '\0'){
        first_string_length++;
    }

    while(second_string[second_string_length] != '\0'){
        second_string_length++;
    }

    previous_row = (int *)malloc((second_string_length + 1) * sizeof(int));
    current_row = (int *)malloc((second_string_length + 1) * sizeof(int));

    for(int j = 0; j <= second_string_length; j++){
        previous_row[j] = j;
    }

    for(int i = 1; i <= first_string_length; i++){
        current_row[0] = i;

        for(int j = 1; j <= second_string_length; j++){
            if(first_string[i - 1] == second_string[j - 1]){
                current_row[j] = previous_row[j - 1];
            }
            else{
                current_row[j] = find_min(previous_row[j - 1] + 1, previous_row[j] + 1, current_row[j - 1] + 1);
            }
        }

        int *temp = previous_row;
        previous_row = current_row;
        current_row = temp;
    }

    minimum_edit_distance = previous_row[second_string_length];

    free(previous_row);
    free(current_row);

    return minimum_edit_distance;
}

int main(){
    
    int minimum_edit_distance;
    char *first_string = (char *)malloc(200 * sizeof(char));
    char *second_string = (char *)malloc(200 * sizeof(char));

    printf("Enter the first string: ");
    scanf("%[^\n]%*c", first_string);

    printf("Enter the second string: ");
    scanf("%[^\n]", second_string);

    minimum_edit_distance = calculate_edit_distance(first_string, second_string);
    printf("The minimum edit distance is: %d\n", minimum_edit_distance);

    free(first_string);
    free(second_string);

    return 0;
}
