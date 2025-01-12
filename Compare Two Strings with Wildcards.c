#include <stdio.h>

int match(const char *str, const char *pattern){
    while(*str){
        if(*pattern == '*'){
            while(*(pattern + 1) == '*'){
                pattern++;
            }
            if(match(str, pattern + 1)){
                return 1;
            }
            str++;
        }
        else if(*pattern == '?' || *pattern == *str){
            str++;
            pattern++;
        }
        else{
            return 0;
        }
    }

    while(*pattern == '*'){
        pattern++;
    }

    return *pattern == '\0';
}

int main() {
    char str[100], pattern[100];
    
    printf("Enter the string: ");
    scanf("%[^\n]%*c", str);
    
    printf("Enter the pattern: ");
    scanf("%[^\n]", pattern);

    if (match(str, pattern)){
        printf("The string matches the pattern.\n");
    }
    else{
        printf("The string does not match the pattern.\n");
    }

    return 0;
}
