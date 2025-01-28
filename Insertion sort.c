#include<stdio.h>
void insertion_sort(int *array,int number_of_elements){
    int key;
    for(int i = 1;i<number_of_elements;i++) {
        key = array[i];
        int j = i - 1;
        for(int k=0;k<number_of_elements;k++){
            printf("%d ",array[k]);
        }
        printf("\n");
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
            for(int k=0;k<number_of_elements;k++){
                printf("%d ",array[k]);
            }
            printf("\n");
        }
        array[j + 1] = key;
        for(int k=0;k<number_of_elements;k++){
            printf("%d ",array[k]);
        }
        printf("\n");
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
    printf("Insertion sort:\n");
    insertion_sort(array,number_of_elements);
    printf("The Final Sorted array: ");
    for(int i=0;i<number_of_elements;i++){
        printf("%d ",array[i]);
    }
    return 0;
}