//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <openssl/sha.h>

#define NUM_THREADS 4
#define BUFFER_SIZE 1024

struct thread_data{
    unsigned char *input;
    unsigned char hash_output[SHA512_DIGEST_LENGTH];
    int thread_id;
};

void *hash_function(void *threadarg){
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;
    
    SHA512(my_data->input, strlen((const char*)my_data->input), my_data->hash_output);
    
    printf("Thread ID: %d, Input: %s, Output:%s\n", my_data->thread_id, my_data->input, my_data->hash_output);
    
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    pthread_t threads[NUM_THREADS];
    struct thread_data thread_data_array[NUM_THREADS];
    
    char buffer[BUFFER_SIZE];
    int rc, t;
    
    printf("Enter your input string: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    
    for(t = 0; t < NUM_THREADS; t++){
        thread_data_array[t].input = (unsigned char *)calloc(strlen(buffer), sizeof(unsigned char));
        strcpy((char*)thread_data_array[t].input, buffer);
        thread_data_array[t].thread_id = t;
        rc = pthread_create(&threads[t], NULL, hash_function, (void *)&thread_data_array[t]);
        if(rc){
            printf("ERROR code %d in creating thread %d\n", rc, t);
            exit(-1);
        }
    }
    
    for(t = 0; t < NUM_THREADS; t++){
        pthread_join(threads[t], NULL);
        free(thread_data_array[t].input);
    }
    
    pthread_exit(NULL);
}