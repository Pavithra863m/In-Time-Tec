#include <stdio.h>
#include <stdlib.h>

void find_longest_palindromic_substring(char *input_string){
    int palindrome_start = 0, max_palindrome_length = 1;
    int string_length = 0;

    while(input_string[string_length] != '\0'){
        string_length++;
    }

    for(int center_index = 0; center_index < string_length; center_index++){
        int left_index = center_index, right_index = center_index;
        while(left_index >= 0 && right_index < string_length && input_string[left_index] == input_string[right_index]){
            if(right_index - left_index + 1 > max_palindrome_length){
                palindrome_start = left_index;
                max_palindrome_length = right_index - left_index + 1;
            }
            left_index--;
            right_index++;
        }
        
        left_index = center_index, right_index = center_index + 1;
        while(left_index >= 0 && right_index < string_length && input_string[left_index] == input_string[right_index]){
            if(right_index - left_index + 1 > max_palindrome_length){
                palindrome_start = left_index;
                max_palindrome_length = right_index - left_index + 1;
            }
            left_index--;
            right_index++;
        }
    }

    printf("Longest Palindromic Substring: ");
    for(int i = palindrome_start; i < palindrome_start + max_palindrome_length; i++){
        putchar(input_string[i]);
    }
    printf("\n");
}

int main(){
    char *input_string = (char *)malloc(1000 * sizeof(char));

    printf("Enter a string: ");
    scanf("%s", input_string);
    
    find_longest_palindromic_substring(input_string);
    
    free(input_string);

    return 0;
}
