#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

int evaluation(char operator, int op1, int op2){
    switch(operator){
        case '+':
            return op1 + op2; 
        case '-': 
            return op1 - op2;
        case '*': 
            return op1 * op2;
        case '/':
            if(op2== 0){ 
                printf("Error: Division by zero.");
                exit(EXIT_FAILURE);
            }
            else{
                return op1 / op2; 
            }
        default:
            printf("Error: Invalid operator.");
            exit(EXIT_FAILURE);
    }
}


int precedence(char operator){
    if(operator == '+' || operator == '-'){
        return 1;
    }
    if(operator == '*' || operator == '/'){
        return 2;
    } 
    return 0;
}


int EvaluateExpression(char *expr){
    int numbers[SIZE];
    char operators[SIZE];
    int nTop = -1, oTop = -1;
    int answer;

    for(int i = 0; i < strlen(expr); i++){
        if(isspace(expr[i])){
            continue;
        } 
        if(isdigit(expr[i])){
            int val = 0;
            while(i < strlen(expr) && isdigit(expr[i])){
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            numbers[++nTop] = val;
        } 
        else if(strchr("+-*/", expr[i])){
            while(oTop != -1 && precedence(operators[oTop]) >= precedence(expr[i])){
                
                int op2= numbers[nTop--]; 
                int op1= numbers[nTop--]; 
                char op = operators[oTop--]; 
                numbers[++nTop] = evaluation(op, op1, op2); 
            }
            operators[++oTop] = expr[i]; 
        } 
        else{
            printf("Error: Invalid expression.");
            return -1;
        }
    }

    while(oTop != -1){
        int op2= numbers[nTop--]; 
        int op1= numbers[nTop--]; 
        char op = operators[oTop--]; 
        numbers[++nTop] = evaluation(op, op1, op2); 
    }
    
    answer = numbers[nTop];
    
    return answer; 
}

int main(){
    char expression[SIZE];

    printf("Enter a mathematical expression: ");
    fgets(expression, SIZE, stdin);
    expression[strcspn(expression, "\n")] = 0; 
    
    if(strlen(expression) == 0){
        printf("Error: Empty expression.");
        return 1;
    }

    for(int i = 0; i < strlen(expression); i++){
        if(!isdigit(expression[i]) && !strchr("+-*/ ", expression[i])){
            printf("Error: Invalid expression.");
            return 1;
        }
    }

    int result = EvaluateExpression(expression);
    if(result != -1){
        printf("Result: %d", result);
    }

    return 0;
}
