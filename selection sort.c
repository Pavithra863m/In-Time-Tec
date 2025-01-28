#include<stdio.h>
void selection_sort(int *array,int number_of_elements){
    int last=number_of_elements-1;
    for(int i=0;i<number_of_elements/2;i++){
        
        int minimum = i;
        int maximum = i;
        
        for(int j=i+1;j<number_of_elements;j++){
            if(array[j]<array[minimum]){
                minimum = j;
            }
        }
        int temp_minimum = array[minimum];
        array[minimum] = array[i];
        array[i] = temp_minimum; 
        
        for(int j=i+1;j<=last;j++){
            if(array[j]>=array[maximum]){
                maximum = j;
            }
        }
        int temp_maximum = array[maximum];
        array[maximum] = array[last];
        array[last] = temp_maximum; 
        last--;
    }
    
}

int main() {
    int array[50];
    int number_of_elements;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &number_of_elements);
    printf("Enter the array elements: ");
    for(int i=0;i<number_of_elements;i++) {
        scanf("%d",&array[i]);
    }
    selection_sort(array,number_of_elements);
    printf("The Sorted array: ");
    for(int i=0;i<number_of_elements;i++){
        printf("%d ",array[i]);
    }
    return 0;
}