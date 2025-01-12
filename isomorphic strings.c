#include <stdio.h>
#include <stdlib.h>

int are_strings_isomorphic(char *first_string, char *second_string){
    int i, first_length = 0, second_length = 0;

    while(first_string[first_length] != '\0'){
        first_length++;
    }

    while(second_string[second_length] != '\0'){
        second_length++;
    }

    if(first_length != second_length){
        return 0;
    }

    char *first_string_map = (char *)calloc(256, sizeof(char));
    char *second_string_map = (char *)calloc(256, sizeof(char));

    for(i = 0; i < first_length; i++){
        char char_first = first_string[i];
        char char_second = second_string[i];

        if((first_string_map[char_first] != 0 && first_string_map[char_first] != char_second) || (second_string_map[char_second] != 0 && second_string_map[char_second] != char_first)){
            free(first_string_map);
            free(second_string_map);
            return 0;
        }

        first_string_map[char_first] = char_second;
        second_string_map[char_second] = char_first;
    }

    free(first_string_map);
    free(second_string_map);
    return 1;
}

int main(){
    char first_string[100], second_string[100];

    printf("Enter first string: ");
    scanf("%s", first_string);

    printf("Enter second string: ");
    scanf("%s", second_string);

    if(are_strings_isomorphic(first_string, second_string)) {
        printf("The strings are isomorphic.\n");
    } 
    else{
        printf("The strings are not isomorphic.\n");
    }

    return 0;
}
