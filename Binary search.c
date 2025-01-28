#include<stdio.h>
void sort(int *array,int number_of_elements) {
    for(int i = 0;i<number_of_elements-1;i++) {
        for(int j=0;j<number_of_elements-i-1;j++) {
            if(array[j]>array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
int binary_search(int array[], int low, int high, int target){
    
    while(high>=low){
        int middle = low +(high - low)/2;
    
        if(target == array[middle]){
            return middle;
        }
        else if(target>array[middle]){
            low = middle+1;
        }
        else{
            high = middle-1;
        }
    }
    return -1;
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
    
    sort(array,number_of_elements);
    
    int target;
    printf("Enter the target value: ");
    scanf("%d",&target);
    
    int index = binary_search(array,0,number_of_elements-1,target);
    
    if(index == -1) {
        printf("Target not found\n");
    }
    else {
        if (index + 1 < number_of_elements){
            printf("The value just greater than the target value: %d\n", array[index + 1]);
            printf("The index of the value (0-Based index): %d\n", index + 1);
        } else {
            printf("The target value is the largest element there is no greater value found.\n");
        }
    }
    
    
    return 0;
}