#include <stdio.h>

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int string_length(char* str){
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}

void sort_string(char* str, int left, int right){
    for(int i = left; i < right; i++){
        for(int j = i + 1; j <= right; j++){
            if(str[i] > str[j]){
                swap(&str[i], &str[j]);
            }
        }
    }
}

void permute(char* str, int left, int right){
    if(left == right){
        printf("%s\n", str);
        return;
    }

    for(int i = left; i <= right; i++){
        if(i > left && str[i] == str[left]){
            continue;
        }

        swap(&str[left], &str[i]);
        permute(str, left + 1, right);
        swap(&str[left], &str[i]);
    }
}

int main(){
    char str[100];
    int n;

    printf("Enter a string: ");
    scanf("%s", str);

    n = string_length(str);
    sort_string(str, 0, n - 1);
    permute(str, 0, n - 1);

    return 0;
}
