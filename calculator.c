#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int stringLength(const char *string){
    int length = 0;
    while(string[length] != '\0'){
        length++;
    }
    return length;
}

int isDigit(char character){
    return(character >= '0' && character <= '9');
}

int isSpace(char character){
    return(character == ' ' || character == '\t' || character == '\n');
}

int isOperator(char character){
    char operators[] = "+-*/";
    for(int i = 0; operators[i] != '\0'; i++){
        if(operators[i] == character){
            return 1;
        }
    }
    return 0;
}

int evaluateOperator(char operator, int operand1, int operand2){
    switch(operator){
        case '+':
            return operand1 + operand2; 
        case '-': 
            return operand1 - operand2;
        case '*': 
            return operand1 * operand2;
        case '/':
            if(operand2 == 0){ 
                printf("Error: Division by zero.");
                return -1;
            }
            else{
                return operand1 / operand2; 
            }
        default:
            printf("Error: Invalid operator.");
            return -1;
    }
}


int getPrecedence(char operator){
    if(operator == '+' || operator == '-'){
        return 1;
    }
    if(operator == '*' || operator == '/'){
        return 2;
    } 
    return 0;
}

int parseOperand(char *expression, int *index){
    int currentValue = 0;
    while(*index < stringLength(expression) && isDigit(expression[*index])){
        currentValue = currentValue * 10 + (expression[*index] - '0');
        (*index)++;
    }
    return currentValue;
}

void applyOperator(char operatorStack[], int *operatorTop, int operandStack[], int *operandTop){
    char operator = operatorStack[(*operatorTop)--];
    int operand2 = operandStack[(*operandTop)--];
    int operand1 = operandStack[(*operandTop)--];
    int result = evaluateOperator(operator, operand1, operand2);
    operandStack[++(*operandTop)] = result;
}

void processOperator(char operator, char operatorStack[], int *operatorTop, int operandStack[], int *operandTop, char *expression, int *index){
    while(*operatorTop != -1 && getPrecedence(operatorStack[*operatorTop]) >= getPrecedence(operator)){
        applyOperator(operatorStack, operatorTop, operandStack, operandTop);
    }
    operatorStack[++(*operatorTop)] = operator;
    (*index)++;
}

int evaluateExpression(char *expression){
    int operandStack[SIZE];
    char operatorStack[SIZE];
    int operandTop = -1, operatorTop = -1;
    int index = 0;

    while(index < stringLength(expression)){
        if(isSpace(expression[index])){
            index++;
            continue;
        }

        if(isDigit(expression[index])){
            int operand = parseOperand(expression, &index);
            operandStack[++operandTop] = operand;
        }
        else if(isOperator(expression[index])){
            processOperator(expression[index], operatorStack, &operatorTop, operandStack, &operandTop, expression, &index);
        }
        else{
            printf("Error: Invalid expression.\n");
            return -1;
        }
    }

    while(operatorTop != -1){
        applyOperator(operatorStack, &operatorTop, operandStack, &operandTop);
    }

    return operandStack[operandTop];
}

int main(){
    char expression[SIZE];
    int i=0;

    printf("Enter a mathematical expression: ");
   
    while(1){
        char character;
        scanf("%c", &character);
        if(character == '\n' || character == '\0'){
            break;
        }
        expression[i++] = character;
        if(i >= SIZE - 1){
            break;
        }
    }
    expression[i] = '\0';
    
    if(stringLength(expression) == 0){
        printf("Error: Empty expression.");
        return 1;
    }

    for(int i = 0; i < stringLength(expression); i++){
        if(!isDigit(expression[i]) && !isSpace(expression[i]) && !isOperator(expression[i])){
            printf("Error: Invalid expression.");
            return 1;
        }
    }

    int result = evaluateExpression(expression);
    if(result != -1){
        printf("Result: %d", result);
    }

    return 0;
}
