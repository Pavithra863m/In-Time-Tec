#include <stdio.h>

// Function to calculate (B^N) % M using Binary Exponentiation
long long calculateModularExponentiation(long long base, long long exponent, long long modulus){

    long long result = 1;
    
    // Optimization of the base(B) value to avoid large numbers 
    base = base % modulus;

    while(exponent > 0){
        if(exponent % 2 == 1){
            // Multiply result by base to keep the number within bounds.
            result = (result * base) % modulus;
        } 
        base = (base * base) % modulus;
        exponent /= 2;
    }

    return result;
}

int main(){
    long long base, exponent, modulus;

    // Input and validate base
    do{
        printf("Enter the base (B): ");
        scanf("%lld", &base);
        if(base < 0){ 
            printf("Invalid input. The base (B) must be non-negative.\n");
        }
    }while(base < 0);

    // Input and validate exponent
    do{
        printf("Enter the exponent (N): ");
        scanf("%lld", &exponent);
        if(exponent < 0){
            printf("Invalid input. The exponent (N) must be non-negative.\n");
        }
    }while(exponent < 0);

    // Input and validate modulus
    do{
        printf("Enter the modulus (M): ");
        scanf("%lld", &modulus);
        if(modulus <= 1){
            printf("Invalid input. The modulus (M) must be greater than 1.\n");
        }
    }while(modulus <= 1);

    printf("Result: %lld\n", calculateModularExponentiation(base, exponent, modulus));

    return 0;
}
