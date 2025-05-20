//FormAI DATASET v1.0 Category: Compression algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* compress(void* data);

struct thread_data {
    char *input;
    char *output;
};

int main(int argc, char* argv[]) {
    pthread_t threads[argc - 1];
    struct thread_data data[argc - 1];
    
    if(argc < 2) {
        printf("No files specified.\n");
        exit(EXIT_FAILURE);
    }
    
    // Create threads to compress the files concurrently
    for(int i = 1; i < argc; i++) {
        data[i-1].input = argv[i];
        data[i-1].output = malloc(strlen(argv[i]) + 5);
        strcpy(data[i-1].output, argv[i]);
        strcat(data[i-1].output, ".cmp");
        
        pthread_create(&threads[i-1], NULL, compress, &data[i-1]);
    }
    
    // Wait for threads to complete
    for(int i = 0; i < argc - 1; i++) {
        pthread_join(threads[i], NULL);
        printf("File %s was compressed to %s\n", data[i].input, data[i].output);
    }
    
    return 0;
}

void* compress(void* data) {
    struct thread_data *threadData = (struct thread_data*) data;
    
    FILE *inputFile = fopen(threadData->input, "rb");
    FILE *outputFile = fopen(threadData->output, "wb");
    
    char *buffer = malloc(1024);
    int bytesRead = 0;
    
    while((bytesRead = fread(buffer, 1, 1024, inputFile))) {
        // Compress the data using your compression algorithm here
        // ...

        fwrite(buffer, 1, bytesRead, outputFile);
    }
    
    free(buffer);
    fclose(inputFile);
    fclose(outputFile);
    pthread_exit(NULL);
}