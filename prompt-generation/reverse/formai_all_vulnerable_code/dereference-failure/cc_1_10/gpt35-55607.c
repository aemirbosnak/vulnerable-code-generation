//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LINE_LENGTH 1024

// struct to hold thread information 
typedef struct {
    int start_index;
    int end_index;
    char** lines;
    int* count;
} ThreadArgs;

// thread function to count words in a given range of lines
void* count_words(void* args) {
    ThreadArgs* thread_args = (ThreadArgs*) args;
    int count = 0;
    for (int i = thread_args->start_index; i <= thread_args->end_index; i++) {
        char* line = thread_args->lines[i];
        int in_word = 0;
        for (int j = 0; j < MAX_LINE_LENGTH && line[j] != '\0'; j++) {
            if ((line[j] >= 'a' && line[j] <= 'z') || (line[j] >= 'A' && line[j] <= 'Z')) {
                if (!in_word) {
                    in_word = 1;
                    count++;
                }
            } else {
                in_word = 0;
            }
        }
    }
    // update shared count variable in a thread-safe way using a mutex
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex);
    *(thread_args->count) += count;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(int argc, char** argv) {
    // read input file name from command line argument
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return 1;
    }

    // read file line by line into an array of strings
    char** lines = (char**) malloc(sizeof(char*) * MAX_LINE_LENGTH);
    int line_count = 0;
    while (!feof(file)) {
        char* line = (char*) malloc(sizeof(char) * MAX_LINE_LENGTH);
        if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
            free(line);
            break;
        }
        lines[line_count] = line;
        line_count++;
    }
    fclose(file);

    // initialize thread arguments and thread variables
    int num_threads = 4;
    int count = 0;
    pthread_t* thread_ids = (pthread_t*) malloc(sizeof(pthread_t) * num_threads);
    ThreadArgs* thread_args = (ThreadArgs*) malloc(sizeof(ThreadArgs) * num_threads);

    // spread threads to each line of the file
    int lines_per_thread = line_count / num_threads;
    int lines_to_split = line_count % num_threads;
    int current_line = 0;
    for (int i = 0; i < num_threads; i++) {
        // calculate start and end indexes for this thread
        thread_args[i].start_index = current_line;
        thread_args[i].end_index = current_line + lines_per_thread - 1;
        if (lines_to_split > 0) {
            // distribute remaining lines to threads, one line per thread
            thread_args[i].end_index++;
            lines_to_split--;
        }
        // assign lines and count to thread struct
        thread_args[i].lines = lines;
        thread_args[i].count = &count;
        // create thread
        pthread_create(&thread_ids[i], NULL, count_words, (void*) &thread_args[i]);
        // move to next line index for next thread
        current_line = thread_args[i].end_index + 1;
    }

    // wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    // print total word count
    printf("Total word count: %d\n", count);

    // free allocated memory
    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
    free(lines);
    free(thread_ids);
    free(thread_args);
    return 0;
}