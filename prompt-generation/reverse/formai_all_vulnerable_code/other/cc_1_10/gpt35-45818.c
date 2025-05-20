//FormAI DATASET v1.0 Category: Database simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 20

// struct representing a record in the database
typedef struct Record{
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

// global variables
Record database[MAX_RECORDS]; // database array
int num_records = 0; // current number of records in the database
pthread_mutex_t mutex; // mutex for ensuring thread safety

// function to add a record to the database
void add_record(int id, char* name){
    pthread_mutex_lock(&mutex); // lock the mutex to ensure thread safety
    if(num_records < MAX_RECORDS){
        Record record = {id};
        strncpy(record.name, name, MAX_NAME_LENGTH);
        database[num_records] = record;
        num_records++;
    }else{
        printf("Database is full. Cannot add record.\n");
    }
    pthread_mutex_unlock(&mutex); // unlock the mutex
}

// function to print all records in the database
void print_database(){
    pthread_mutex_lock(&mutex); // lock the mutex to ensure thread safety
    printf("ID\tName\n");
    for(int i=0; i<num_records; i++){
        printf("%d\t%s\n", database[i].id, database[i].name);
    }
    pthread_mutex_unlock(&mutex); // unlock the mutex
}

// main function to simulate the distributed database in a multi-threaded program
int main(){
    // initialize the mutex
    if(pthread_mutex_init(&mutex, NULL) != 0){
        printf("Mutex initialization failed.\n");
        return -1;
    }

    // spawn multiple threads to simulate multiple clients accessing the database
    pthread_t threads[3];
    int thread_args[3][2] = {{1, "John"}, {2, "Alice"}, {3, "Bob"}};
    for(int i=0; i<3; i++){
        if(pthread_create(&threads[i], NULL, (void*)add_record, (void*)thread_args[i]) != 0){
            printf("Thread creation failed.\n");
            return -1;
        }
    }

    // wait for all threads to complete execution
    for(int i=0; i<3; i++){
        if(pthread_join(threads[i], NULL) != 0){
            printf("Thread join failed.\n");
            return -1;
        }
    }

    // print the final database state
    print_database();

    // destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}