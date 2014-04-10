#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
void printArray(int *, int);
void quickSort(int *, int, int);

int main(int argc, char** argv) {

    int numbers[SIZE] = {66,2,9,45,6,4,31,6,5,2,5,8,7,6,7};
    
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

