#include<stdio.h>
#include<stdlib.h>
void merge(int *array,int low,int middle,int high){
    int n1 = middle - low +1;
    int n2 = high - middle;
    
    int left[n1];
    int right[n2];
    
    for(int i=0;i<n1;i++){
        left[i] = array[low+i];
    }
    for(int j=0;j<n2;j++){
        right[j] = array[middle + 1 + j];
    }
    
    int i = 0, j = 0, k = low;
    while(i<n1&&j<n2){
        if(left[i]<=right[j]){
            array[k] = left[i];
            i++;
        } 
        else{
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        array[k] = left[i];
        i++;
        k++;
    }

    while(j < n2){
        array[k] = right[j];
        j++;
        k++;
    }
}
void merge_sort(int *array,int low,int high){
    if(low<high){
        int middle = low + (high-low)/2;
        
        merge_sort(array,low,middle);
        merge_sort(array,middle+1,high);
        
        merge(array,low,middle,high);
    }
}
void merge_sorted_arrays(int *array1,int *array2,int number_of_elements1,int number_of_elements2){
    int i = number_of_elements1 - 1;
    int j = number_of_elements2 - 1;
    int k = number_of_elements1+number_of_elements2-1;
    while(i>=0&&j>=0){
        if(array1[i]>array2[j]){
            array1[k] = array1[i];
            k--;
            i--;
        }
        else{
            array1[k] = array2[j];
            k--;
            j--;
        }
    }
    while(j>=0){
        array1[k] = array2[j];
        k--;
        j--;
    }
}
int main() {

    int number_of_elements1;
    int number_of_elements2;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &number_of_elements1);
    int *array1 = (int*)malloc(number_of_elements1*sizeof(int));
    printf("Enter the array1 elements: ");
    for(int i=0;i<number_of_elements1;i++) {
        scanf("%d",&array1[i]);
    }
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &number_of_elements2);
    int *array2 = (int*)malloc(number_of_elements2*sizeof(int));
    printf("Enter the array2 elements: ");
    for(int i=0;i<number_of_elements2;i++) {
        scanf("%d",&array2[i]);
    }
    
    merge_sort(array1,0,number_of_elements1-1);
    merge_sort(array2,0,number_of_elements2-1);
    
    array1 = (int*)realloc(array1,(number_of_elements1+number_of_elements2)*sizeof(int));
    
    merge_sorted_arrays(array1,array2,number_of_elements1,number_of_elements2);
    int number_of_elements=number_of_elements1+number_of_elements2;
    printf("The merged sorted array: ");
    for(int i=0;i<number_of_elements;i++){
        printf("%d ",array1[i]);
    }
    return 0;
}