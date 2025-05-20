//FormAI DATASET v1.0 Category: Memory management ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

void expand_memory(int **arr, int current_size, int new_size){
    int *temp = realloc(*arr, new_size*sizeof(int));
    if(temp){
        *arr = temp;
        printf("Expanding memory from %d to %d\n", current_size, new_size);
    }
    else{
        printf("Memory reallocation failed!\n");
    }
}

int main(){
    int *arr;
    int current_size = 5;
    arr = (int*)malloc(current_size*sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed!\n");
        return 0;
    }
    for(int i=0; i<current_size; i++){
        arr[i] = i+1;
    }
    printf("Current array: ");
    for(int i=0; i<current_size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    expand_memory(&arr, current_size, 10);
    for(int i=current_size; i<10; i++){
        arr[i] = i+1;
    }
    printf("Expanded array: ");
    for(int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    expand_memory(&arr, 10, 20);
    for(int i=10; i<20; i++){
        arr[i] = i+1;
    }
    printf("Further expanded array: ");
    for(int i=0; i<20; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}