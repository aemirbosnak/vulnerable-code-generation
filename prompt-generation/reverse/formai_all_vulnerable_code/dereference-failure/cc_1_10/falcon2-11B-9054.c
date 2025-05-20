//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define NUM_THREADS 4

// Define a struct for the thread data
typedef struct {
    char buffer[BUFFER_SIZE];
    int file_handle;
} thread_data;

// Function to write to a file
void* write_to_file(void* data) {
    thread_data* tdata = (thread_data*)data;

    while (1) {
        // Generate some random data
        char* data = (char*)malloc(BUFFER_SIZE);
        for (int i = 0; i < BUFFER_SIZE; i++) {
            data[i] = (char)rand() % 256;
        }

        // Write the data to the file
        int bytes_written = write(tdata->file_handle, data, BUFFER_SIZE);
        if (bytes_written < 0) {
            perror("write");
            exit(1);
        }

        // Sleep for 1 second
        sleep(1);
    }
}

// Function to create a file
void* create_file(void* data) {
    char* filename = (char*)data;

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }

    // Spawn a thread to write to the file
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, write_to_file, (void*)filename);
    pthread_detach(thread_id);

    fclose(file);
}

int main() {
    // Create the file
    char* filename = "backup.txt";
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, create_file, (void*)filename);
    pthread_detach(thread_id);

    // Wait for the thread to finish
    pthread_join(thread_id, NULL);

    // Check if the file was created
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }

    // Read some data from the file
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* data = (char*)malloc(file_size + 1);
    fread(data, sizeof(char), file_size, file);
    data[file_size] = '\0';

    printf("File content: %s\n", data);

    // Clean up
    free(data);
    fclose(file);

    return 0;
}