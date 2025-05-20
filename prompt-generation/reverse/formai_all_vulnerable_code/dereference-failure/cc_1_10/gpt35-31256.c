//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define ARRAY_SIZE 10

// Global variables
unsigned int data[ARRAY_SIZE] = {1,2,3,4,5,6,7,8,9,10};
int even_sum = 0, odd_sum = 0; // To hold the even and odd sum of the data array

// The function that each thread runs
void *thread_func(void *ptr){
    int tid = *((int*) ptr); // thread ID
    free(ptr);

    if(tid == 0){ // Do the bitwise AND operation on the even elements of the data array
        for(int i=0; i<ARRAY_SIZE; i++){
            if(data[i] % 2 == 0){ // If even
                even_sum &= data[i]; // Bitwise AND operation
            }
        }
    } else { // Do the bitwise OR operation on the odd elements of the data array
        for(int i=0; i<ARRAY_SIZE; i++){
            if(data[i] % 2 == 1){ // If odd
                odd_sum |= data[i]; // Bitwise OR operation
            }
        }
    }

    pthread_exit(NULL); // Exit the thread
}

int main(){
    pthread_t tid[2]; // Two threads
    int *id;

    // Create the thread for the even operation
    id = malloc(sizeof(int));
    *id = 0; // Set the thread ID for even operation
    if(pthread_create(&tid[0], NULL, thread_func, id) != 0){
        printf("Error creating thread 0.\n");
        exit(1);
    }

    // Create the thread for the odd operation
    id = malloc(sizeof(int));
    *id = 1; // Set the thread ID for odd operation
    if(pthread_create(&tid[1], NULL, thread_func, id) != 0){
        printf("Error creating thread 1.\n");
        exit(1);
    }

    // Wait for the threads to finish
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    // Print the result
    printf("Even sum after bitwise AND: %d\n", even_sum);
    printf("Odd sum after bitwise OR: %d\n", odd_sum);

    return 0;
}