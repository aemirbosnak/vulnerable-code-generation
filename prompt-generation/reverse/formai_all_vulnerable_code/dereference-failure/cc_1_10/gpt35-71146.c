//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define THREAD_COUNT 4
#define MAX_WORD_LENGTH 1000

char* buffer;
int buffer_len;
int word_count[THREAD_COUNT];

void* count_words(void* arg) {
    int thread_num = *(int*) arg;
    int start_index = thread_num * (buffer_len / THREAD_COUNT);
    int end_index = (thread_num + 1) * (buffer_len / THREAD_COUNT);
    if (thread_num == THREAD_COUNT - 1) {
        end_index = buffer_len;
    }

    char word[MAX_WORD_LENGTH];
    int word_len = 0;
    for (int i = start_index; i < end_index; i++) {
        if (buffer[i] == ' ' || buffer[i] == '\n') {
            word[word_len] = '\0';
            if (word_len > 0) {
                word_count[thread_num]++;
            }
            word_len = 0;
        } else {
            word[word_len++] = buffer[i];
        }
    }

    pthread_exit(NULL);
}

int main() {
    FILE* fp = fopen("input.txt", "r");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    buffer_len = ftell(fp);
    rewind(fp);

    buffer = malloc(buffer_len * sizeof(char));
    if (!buffer) {
        perror("Error allocating memory");
        exit(1);
    }

    fread(buffer, buffer_len, 1, fp);
    fclose(fp);

    pthread_t threads[THREAD_COUNT];
    int thread_nums[THREAD_COUNT];
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_nums[i] = i;
        pthread_create(&threads[i], NULL, count_words, &thread_nums[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    int total_words = 0;
    for (int i = 0; i < THREAD_COUNT; i++) {
        total_words += word_count[i];
    }

    printf("Total Words: %d\n", total_words);

    free(buffer);

    return 0;
}