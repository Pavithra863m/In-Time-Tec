#include <stdio.h>
#include <stdlib.h>

int starts_with_prefix(char *word, char *prefix){
    while (*prefix){
        char word_char = *word;
        char prefix_char = *prefix;

        if(word_char >= 'A' && word_char <= 'Z'){
            word_char += ('a' - 'A');
        }

        if(prefix_char >= 'A' && prefix_char <= 'Z'){
            prefix_char += ('a' - 'A');
        }

        if(word_char != prefix_char){
            return 0;
        }
        word++;
        prefix++;

    }
    return 1;
}

void find_words_with_prefix(char *input_sentence, char *input_prefix){
    char current_word[100];
    int sentence_index = 0, word_index = 0;

    while(input_sentence[sentence_index] != '\0'){
        word_index = 0;

        while(input_sentence[sentence_index] != ' ' && input_sentence[sentence_index] != '\0'){
            current_word[word_index++] = input_sentence[sentence_index++];
        }
        current_word[word_index] = '\0';

        if(starts_with_prefix(current_word, input_prefix)){
            printf("%s\n", current_word);
        }

        while(input_sentence[sentence_index] == ' '){
            sentence_index++;
        }
    }
}

int main(){
    char input_sentence[1000];
    char input_prefix[100];

    printf("Enter the sentence: ");
    scanf("%[^\n]", input_sentence);

    printf("Enter the prefix: ");
    scanf("%s", input_prefix);

    printf("Words starting with '%s':\n", input_prefix);

    find_words_with_prefix(input_sentence, input_prefix);

    return 0;
}
