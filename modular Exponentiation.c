#include <stdio.h>

// Function to caluculate the expression (B^N) % M
long long calculateModularExponentiation(long long base, long long exponent, long long modulus){
    // Initailised the result as 1
    long long result = 1;

    // Optimization of the base(B) value to avoid large numbers 
    base = base % modulus;

    // Loop while exponent is greater than O
    while(exponent > 0){
        // If the exponent is odd then multiply the result by base
        if(exponent % 2 == 1){
            // Multiply result by base to keep the number within bounds.
            result = (result * base) % modulus;
        }
        // Square the base and reduce the exponent by half
        base = (base * base) % modulus;
         // Divide the exponent by 2. This reduces the exponent gradually.
        exponent = exponent / 2;
    }

    return result;
}

int main(){
    long long base, exponent, modulus, final_result;

    printf("Enter the base (B): ");
    scanf("%lld", &base);
    

    printf("Enter the exponent (N): ");
    scanf("%lld", &exponent);
    // Input validation for exponent (N) to ensure it is non-negative
    if(exponent < 0){
        printf("Invalid input. The exponent (N) must be non-negative.\n");
        return -1;
    }


    printf("Enter the modulus (M): ");
    scanf("%lld", &modulus);
    // Input validation for modulus (M) to ensure it is greater than 1
    if(modulus<=1){
        printf("Invalid input. The modulus (M) must be greater than 1.\n");
        return -1;
    } 

    // call the modular exponentiation function and store the result in final_result
    final_result = calculateModularExponentiation(base, exponent, modulus);

    // Display the result of base^exponent % modulus
    printf("Result: %llu", final_result);

    return 0;
}
