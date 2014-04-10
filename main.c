#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
void printArray(int *, int);
void quickSort(int *, int, int);

int main(int argc, char** argv) {

    int i, j;
    int k = 0;
    
    int numbers[SIZE] = {66,2,9,45,6,4,31,6,5,2,5,8,7,6,7};
    int new[SIZE];
    int counter[SIZE];
    
    
    new[0] = numbers[0];
    counter[0] = 1;
    printf("\tk\tnum\tnew\tcount\n");
    
    for(i = 1; i < SIZE; i++){
        j = 0;
        while((j <= k) && (numbers[i] != new[j])){
            j++;
        }
        if(j > k){
            k++;
            new[k] = numbers[i];
            counter[k] = 1;
            //printf("\t%d\t%d\t%d\t%d\n", k, numbers[i], new[k], counter[k]);
        }else{
            counter[j]++;
            //printf("\t%d\n", counter[k]);
        }
    }
    
    printArray(numbers,SIZE);
    printArray(new,k + 1);
    printArray(counter,k + 1);
    
    
    quickSort(numbers, 0, SIZE - 1);
    printArray(numbers, SIZE);
    return (EXIT_SUCCESS);
}

void printArray(int *array, int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void quickSort(int *numbers, int left, int right){
    int i = left;
    int j = right;
    int k = (i + j) / 2;
    int temp;
    
    int pivot = numbers[k];
    
    while(i < j){
        while(numbers[i] < pivot){
            i++;
        }
        while(numbers[j] > pivot){
            j--;
        }
        if(j >= i){
            temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
            i++;
            j--;
        }
    }
    
    if(i < right){
        quickSort(numbers, i, right);
    }
    if(left < j){
        quickSort(numbers, left, j);
    }
}

