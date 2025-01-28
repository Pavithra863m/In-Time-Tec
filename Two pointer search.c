#include<stdio.h>
int maxsum_subarray(int array[],int number_of_elements,int target){
    int sum;
    int start,end;
    int maximum_count = 0;
    int start_index,end_index;
    
    for(int i = 0; i < number_of_elements;i++){
        for(int j = i+1; j < number_of_elements;j++){
            start = i;
            end =j;
            sum=0;
            int count = 0;
            for(int k = start; k <= end; k++){
                sum += array[k];
                count++;
            }
            if(maximum_count<count && sum<=target){
                maximum_count = count;
                start_index = start;
                end_index = end;
            }
        }        
    }
    printf("The longest subarray with sum lesser than or equal to the target: ");
    printf("[");
    for(int i=start_index;i<=end_index;i++){
        printf("%d ",array[i]);
    }
    printf("]");
}
int main(){
    int array[50];
    int number_of_elements;
    printf("Enter the number of elements: ");
    scanf("%d",&number_of_elements);
    printf("Enter the Array: ");
    for(int i = 0;i<number_of_elements;i++){
        scanf("%d",&array[i]);
    }
    int target;
    printf("Enter thr target sum: ");
    scanf("%d",&target);
    maxsum_subarray(array,number_of_elements,target);
    
}