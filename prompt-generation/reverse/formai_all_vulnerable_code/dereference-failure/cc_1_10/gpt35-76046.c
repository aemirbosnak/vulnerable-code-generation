//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_FILENAME_LENGTH 50
#define MAX_WATERMARK_LENGTH 20

struct thread_data {
    char filename[MAX_FILENAME_LENGTH];
    char watermark[MAX_WATERMARK_LENGTH];
};

void *watermark_thread(void *thread_arg) {
    struct thread_data *thread_data = (struct thread_data *) thread_arg;
    
    // Read file
    FILE *file = fopen(thread_data->filename, "r");
    if (!file) {
        printf("Error opening file %s\n", thread_data->filename);
        pthread_exit(NULL);
    }
    
    // Determine file size
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);
    
    // Allocate memory for file contents
    char *file_contents = malloc(sizeof(char) * filesize);
    if (!file_contents) {
        printf("Error allocating memory for file contents\n");
        fclose(file);
        pthread_exit(NULL);
    }
    
    // Read file contents
    if (fread(file_contents, sizeof(char), filesize, file) != filesize) {
        printf("Error reading file %s\n", thread_data->filename);
        free(file_contents);
        fclose(file);
        pthread_exit(NULL);
    }
    
    // Close file
    fclose(file);
    
    // Add watermark to file contents
    int watermark_length = strlen(thread_data->watermark);
    for (int i = 0; i < filesize; i++) {
        if (i % MAX_THREADS == thread_data->watermark[0] % MAX_THREADS) {
            for (int j = 0; j < watermark_length; j++) {
                file_contents[i+j] ^= thread_data->watermark[j];
            }
        }
    }
    
    // Write modified file contents back to file
    file = fopen(thread_data->filename, "w");
    if (!file) {
        printf("Error opening file %s for writing\n", thread_data->filename);
        free(file_contents);
        pthread_exit(NULL);
    }
    
    if (fwrite(file_contents, sizeof(char), filesize, file) != filesize) {
        printf("Error writing modified file back to disk\n");
    }
    
    // Close file and free memory
    fclose(file);
    free(file_contents);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    pthread_t threads[MAX_THREADS];
    struct thread_data thread_data[MAX_THREADS];
    
    if (argc != 3) {
        printf("Usage: ./watermark inputfile watermark\n");
        return 1;
    }
    
    char *filename = argv[1];
    char *watermark = argv[2];
    
    if (strlen(watermark) > MAX_WATERMARK_LENGTH) {
        printf("Error: watermark too long (max length %d)\n", MAX_WATERMARK_LENGTH);
        return 1;
    }
    
    // Create threads
    for (int i = 0; i < MAX_THREADS; i++) {
        strncpy(thread_data[i].filename, filename, MAX_FILENAME_LENGTH);
        strncpy(thread_data[i].watermark, watermark, MAX_WATERMARK_LENGTH);
        thread_data[i].watermark[0] = i; // Set the first byte to the thread number
        
        if (pthread_create(&threads[i], NULL, watermark_thread, &thread_data[i]) != 0) {
            printf("Error creating thread %d\n", i);
            return 1;
        }
    }
    
    // Wait for threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Error joining thread %d\n", i);
        }
    }
    
    return 0;
}