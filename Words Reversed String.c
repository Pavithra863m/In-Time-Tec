#include <stdio.h>

#define MAX_LENGTH 100

int main(){

    char sentence[MAX_LENGTH];
    int word_start_index = 0, word_end_index = 0;
    int start,end;
    
    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);

    for(int i = 0; sentence[i] != '\0'; i++){
        if(sentence[i] == ' ' || sentence[i + 1] == '\0'){
            
            if(sentence[i] == ' ') {
                word_end_index = i - 1;
            } 
            else{
                word_end_index = i;
            }

            start = word_start_index, end = word_end_index;
            while(start < end){
                char temp = sentence[start];
                sentence[start] = sentence[end];
                sentence[end] = temp;
                start++;
                end--;
            }

            word_start_index = i + 1;
        }
    }

    printf("Words Reversed sentence: %s\n", sentence);

    return 0;
}
