#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int median(int *array,int low,int high){
    int mid = low + (high-low)/2;
    int first = array[low];
    int middle = array[mid];
    int last =array[high];
    
    if(first>middle){
        swap(&first,&middle);
    }
    if(middle>last){
        swap(&middle,&last);
    }
    if(first>middle){
        swap(&first,&middle);
    }
    return middle;
}
int partition(int *array,int low,int high){
    int pivot = median(array,low,high);
    
    int pivotIndex = low;
    for (int i = low; i <= high; i++) {
        if (array[i] == pivot) {
            pivotIndex = i;
            break;
        }
    }
    
    swap(&array[pivotIndex], &array[high]); 
    
    int i=low-1;
    for(int j=low;j<high;j++){
        if(array[j]<=pivot){
            i++;
            swap(&array[i],&array[j]);
        }
    }
    
    swap(&array[i+1],&array[high]);
    return i+1;
}
int quick_sort(int *array,int low,int high){
    if(low<high){
        int pivot_index = partition(array,low,high);
        quick_sort(array,low,pivot_index-1);
        quick_sort(array,pivot_index+1,high);
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
    
    quick_sort(array,0,number_of_elements-1);
    printf("The sorted array: ");
    for(int i=0;i<number_of_elements;i++){
        printf("%d ",array[i]);
    }
    return 0;
}