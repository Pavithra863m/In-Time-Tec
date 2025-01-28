#include<stdio.h>
int bubble_sort(int *array,int number_of_elements) {
    int swapcount = 0;
    for(int i = 0;i<number_of_elements-1;i++) {
        for(int j=0;j<number_of_elements-i-1;j++) {
            if(array[j]>array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapcount++;
            }
        }
    }
    return swapcount;
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
    
    int swapcount = bubble_sort(array,number_of_elements);
    printf("The sorted array: ");
    for(int i=0;i<number_of_elements;i++){
        printf("%d ",array[i]);
    }
    printf("\nThe number of swaps used for sorting: %d",swapcount);
    return 0;
}