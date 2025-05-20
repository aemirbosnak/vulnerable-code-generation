//FormAI DATASET v1.0 Category: Memory management ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

#define MAX_ALLOCATIONS 10 // maximum number of allocations

int main(){
    int allocation_count = 0; // initialize allocation count
    int *pointers[MAX_ALLOCATIONS]; // array to store pointers to allocated memory
    
    printf("Welcome to Memory Allocator!\n");
    while(allocation_count < MAX_ALLOCATIONS){ // loop until maximum allocations are reached
        printf("Enter number of integers to allocate: ");
        int allocation_size;
        scanf("%d", &allocation_size); // get allocation size from user

        // allocate memory and store pointer in pointers array
        int *ptr = (int*) malloc(sizeof(int) * allocation_size);
        if(ptr == NULL){ // check if allocation was successful
            printf("Memory allocation failed!\n");
            break; // exit if allocation failed
        }
        pointers[allocation_count] = ptr; // store pointer in array
        allocation_count++; // increment allocation count

        // print confirmation message
        printf("Allocated %d integers (%d bytes) at address %p\n", allocation_size, allocation_size * sizeof(int), ptr);

        // prompt user to fill allocated memory with values
        printf("Enter integers to fill allocated memory (separated by spaces): ");
        for(int i=0; i<allocation_size; i++){
            int num;
            scanf("%d", &num);
            *(ptr + i) = num; // fill memory with user input
        }

        // prompt user to deallocate memory
        printf("Deallocate memory? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if(choice == 'y' || choice == 'Y'){ // deallocate memory and remove pointer from array
            free(ptr);
            printf("Memory deallocated at address %p\n", ptr);
            pointers[allocation_count-1] = NULL;
            allocation_count--;
        }
    }

    // free remaining allocated memory
    for(int i=0; i<MAX_ALLOCATIONS; i++){
        if(pointers[i] != NULL){
            free(pointers[i]);
            printf("Memory deallocated at address %p\n", pointers[i]);
        }
    }
    printf("Exiting Memory Allocator!");
    return 0; // exit program
}