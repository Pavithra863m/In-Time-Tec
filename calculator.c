#include <stdio.h>
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
    return(character == '+' || character == '-' || character == '*' || character == '/');
}

void shiftOperands(int array[], int size, int start){
    for(int i = start; i < size - 1; i++){
        array[i] = array[i + 1];
    }
}

void shiftOperators(char array[], int size, int start){
    for(int i = start; i < size - 1; i++){
        array[i] = array[i + 1];
    }
}

int parseOperand(const char *expression, int *index){
    int currentValue = 0;
    
    while(isDigit(expression[*index])){
        currentValue = currentValue * 10 + (expression[*index] - '0');
        (*index)++;
    }
    
    return currentValue;
}

int evaluateOperator(char operatorArray[], int *operatorCount, int operandArray[], int *operandCount){
    for(int i = 0; i < *operatorCount; i++){
        if(operatorArray[i] == '/'){
            if(operandArray[i + 1] == 0){
                printf("Error: Division by zero.\n");
                return -1;
            }
            operandArray[i] = operandArray[i]/ operandArray[i + 1];
            shiftOperands(operandArray, *operandCount, i + 1);
            shiftOperators(operatorArray, *operatorCount, i);
            (*operandCount)--;
            (*operatorCount)--;
            i--;
        }
    }

    for(int i = 0; i < *operatorCount; i++){
        if(operatorArray[i] == '*'){
            operandArray[i] = operandArray[i] * operandArray[i + 1];
            shiftOperands(operandArray, *operandCount, i + 1);
            shiftOperators(operatorArray, *operatorCount, i);
            (*operandCount)--;
            (*operatorCount)--;
            i--;
        }
    }

    for(int i = 0; i < *operatorCount; i++){
        if(operatorArray[i] == '+'){
            operandArray[i] = operandArray[i] + operandArray[i + 1];
            shiftOperands(operandArray, *operandCount, i + 1);
            shiftOperators(operatorArray, *operatorCount, i);
            (*operandCount)--;
            (*operatorCount)--;
            i--;
        }
    }

    for(int i = 0; i < *operatorCount; i++){
        if(operatorArray[i] == '-'){
            operandArray[i] = operandArray[i] - operandArray[i + 1];
            shiftOperands(operandArray, *operandCount, i + 1);
            shiftOperators(operatorArray, *operatorCount, i);
            (*operandCount)--;
            (*operatorCount)--;
            i--;
        }
    }

    return operandArray[0];
}


int evaluateExpression(const char *expression){
    int operandArray[SIZE];
    char operatorArray[SIZE];
    int operandCount = 0, operatorCount = 0;
    int index = 0;

    while(index < stringLength(expression)){
        if(isSpace(expression[index])){
            index++;
            continue;
        }

        if(isDigit(expression[index])){
            operandArray[operandCount++] = parseOperand(expression, &index);
        } 
        else if(isOperator(expression[index])){
            operatorArray[operatorCount++] = expression[index];
            index++;
        }
        else{
            printf("Error: Invalid expression.\n", expression[index]);
            return -1;
        }
    }
    
    if((operandCount != (operatorCount+1)) || operandCount == 0 || operatorCount == 0 ){
        printf("Error: Invalid Expression.\n");
        return -1;
    }
    
    return evaluateOperator(operatorArray, &operatorCount, operandArray, &operandCount);
}

int main() {
    char expression[SIZE];

    printf("Enter a mathematical expression: ");
    scanf("%[^\n]", expression);

    if (stringLength(expression) == 0) {
        printf("Error: Empty expression.\n");
        return 1;
    }

    int result = evaluateExpression(expression);

    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}
