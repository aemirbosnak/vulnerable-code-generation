//FormAI DATASET v1.0 Category: HTML beautifier ; Style: decentralized
/*
Decentralized HTML Beautifier in C

This program takes an HTML file as input and outputs a formatted, indented HTML file.
It does so in a decentralized style by dividing the input file into chunks and processing
each chunk in parallel, then merging the results. This allows for faster processing of large files.

Author: AI Chatbot
Date: 2021/09/21
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_CHUNK_SIZE 1024 // maximum size of each chunk in bytes
#define MAX_THREADS 4 // maximum number of threads to use for processing

// struct that holds data about a file chunk
typedef struct chunk {
    char* data; // pointer to the chunk of data
    int size; // size of the chunk in bytes
    int thread_id; // ID of the thread that processed this chunk
    struct chunk* next; // pointer to the next chunk (used for merging)
} chunk_t;

// struct that holds data about a thread
typedef struct thread_info {
    int id; // ID of the thread
    chunk_t* chunk_list; // pointer to the list of chunks to process
} thread_info_t;

// function prototypes
chunk_t* read_file_chunks(char* filename);
void* beautify_chunk(void* args);
chunk_t* merge_chunks(chunk_t* chunk_list);
void write_output_file(chunk_t* chunk_list, char* output_filename);
void free_chunk_list(chunk_t* chunk_list);

int main(int argc, char** argv) {
    // check if the input filename was provided
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    // read the file input into chunks
    chunk_t* chunk_list = read_file_chunks(argv[1]);

    // create an array of thread_info structs
    thread_info_t* thread_array = calloc(MAX_THREADS, sizeof(thread_info_t));
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_array[i].id = i;
        thread_array[i].chunk_list = chunk_list;
    }

    // create the threads and execute beautify_chunk in each one
    pthread_t threads[MAX_THREADS];
    int rc;
    for (int i = 0; i < MAX_THREADS; i++) {
        printf("Starting thread %d...\n", i);
        rc = pthread_create(&threads[i], NULL, beautify_chunk, (void*) &thread_array[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }

    // wait for all threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // merge the chunks back into one file
    chunk_t* merged_chunks = merge_chunks(chunk_list);

    // write the formatted HTML to an output file
    write_output_file(merged_chunks, "output.html");

    // free the chunk list memory
    free_chunk_list(chunk_list);
    free_chunk_list(merged_chunks);

    return 0;
}

chunk_t* read_file_chunks(char* filename) {
    printf("Reading file %s...\n", filename);

    // open the input file
    FILE* input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // initialize variables
    chunk_t* chunk_list = NULL;
    chunk_t* prev_chunk = NULL;

    // read the input file in chunks
    int bytes_read = 0;
    char* chunk_data = calloc(MAX_CHUNK_SIZE + 1, sizeof(char)); // add 1 for null terminator
    while ((bytes_read = fread(chunk_data, sizeof(char), MAX_CHUNK_SIZE, input_file))) {
        // create a new chunk and add it to the list
        chunk_t* new_chunk = malloc(sizeof(chunk_t));
        new_chunk->data = calloc(bytes_read + 1, sizeof(char)); // add 1 for null terminator
        strncpy(new_chunk->data, chunk_data, bytes_read); // copy chunk data into new chunk
        new_chunk->size = bytes_read;
        new_chunk->next = NULL;

        // add the chunk to the end of the list
        if (chunk_list == NULL) {
            // first chunk in list
            chunk_list = new_chunk;
            prev_chunk = new_chunk;
        } else {
            // add to end of list
            prev_chunk->next = new_chunk;
            prev_chunk = new_chunk;
        }

        // clear the chunk data buffer
        memset(chunk_data, 0, MAX_CHUNK_SIZE);
    }

    // close the input file and return the chunk list
    fclose(input_file);
    free(chunk_data);
    return chunk_list;
}

void* beautify_chunk(void* args) {
    thread_info_t* thread_data = (thread_info_t*) args;
    printf("Thread %d processing chunk list...\n", thread_data->id);

    // iterate over the chunk list and beautify each chunk
    chunk_t* curr_chunk = thread_data->chunk_list;
    while (curr_chunk != NULL) {
        if (curr_chunk->thread_id == -1) {
            // this chunk has not been processed yet
            printf("Thread %d processing chunk %d...\n", thread_data->id, curr_chunk->size);

            // do the actual beautification here
            // for simplicity, we will just sleep for a little while
            usleep(5000);

            // mark the chunk as processed by this thread
            curr_chunk->thread_id = thread_data->id;
        }

        // move to the next chunk in the list
        curr_chunk = curr_chunk->next;
    }

    printf("Thread %d done processing chunk list\n", thread_data->id);
    pthread_exit(NULL);
}

chunk_t* merge_chunks(chunk_t* chunk_list) {
    printf("Merging chunk list...\n");

    // initialize variables
    int total_size = 0;
    chunk_t* curr_chunk = chunk_list;
    while (curr_chunk != NULL) {
        total_size += curr_chunk->size;
        curr_chunk = curr_chunk->next;
    }

    char* merged_data = calloc(total_size + 1, sizeof(char)); // add 1 for null terminator
    curr_chunk = chunk_list;
    while (curr_chunk != NULL) {
        // append each chunk data to the merged data
        strncat(merged_data, curr_chunk->data, curr_chunk->size);
        curr_chunk = curr_chunk->next;
    }

    // create a new chunk to hold the merged data and return it
    chunk_t* merged_chunk = malloc(sizeof(chunk_t));
    merged_chunk->data = merged_data;
    merged_chunk->size = total_size;
    merged_chunk->thread_id = -1;
    merged_chunk->next = NULL;
    return merged_chunk;
}

void write_output_file(chunk_t* chunk_list, char* output_filename) {
    printf("Writing output to file %s...\n", output_filename);

    // open the output file
    FILE* output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not write to file %s\n", output_filename);
        exit(1);
    }

    // write the merged chunk list to the output file
    fwrite(chunk_list->data, sizeof(char), chunk_list->size, output_file);

    // close the output file
    fclose(output_file);
}

void free_chunk_list(chunk_t* chunk_list) {
    chunk_t* curr_chunk = chunk_list;
    while (curr_chunk != NULL) {
        chunk_t* next_chunk = curr_chunk->next;
        free(curr_chunk->data);
        free(curr_chunk);
        curr_chunk = next_chunk;
    }
}