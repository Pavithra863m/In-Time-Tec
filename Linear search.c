#include<stdio.h>
void linear_search(int array[],int number_of_elements){
    int target;
    int count = 0;
    for(int i = 0;i<number_of_elements;i++){
        if(count==0){
            target = array[i];
        }
        else if(target == array[i]){
            count++;
        }
        else{
            count--;
        }
    }
    
    count=0;
    
    for(int i=0;i<number_of_elements;i++){
        if(target==array[i]){
            count++;
        }
    }
    
    if(count>number_of_elements/2){
        printf("The number the repeats more than n/2 times: %d\n",target);
        printf("The number times it is repeated: %d\n",count);
    }
    else{
        printf("There is no number that repeats more thsn n/2 times");
    }
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
    linear_search(array,number_of_elements);
    
}