#include <stdio.h>

void printPascalTriangle(int n){
    char letter;

    for(int line = 0; line < n; line++){
        for (int space = 1; space < n - line; space++) {
            printf("  ");
        }

        letter = 'a';
        
        for(int i = 0; i <= line; i++){
            printf("%c ", letter);
            letter++;
        }

        letter--;
        
        for(int i = line - 1; i >= 0; i--){
            letter--;
            printf("%c ", letter);
        }

        printf("\n");
    }
}

int main(){
    int n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printPascalTriangle(n);

    return 0;
}
