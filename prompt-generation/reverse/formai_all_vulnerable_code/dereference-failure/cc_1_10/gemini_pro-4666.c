//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Alien Languange Syntax
#define ALIEN_START "<ALIEN>"
#define ALIEN_END   "</ALIEN>"
#define ALIEN_SEP    ":"

// Thread Data Structure
typedef struct thread_data {
    char *alien_text;
    char *human_text;
    int index;
} thread_data;

// Alien to Human Translation Function
void *alien_to_human(void *arg) {
    // Get thread data
    thread_data *data = (thread_data *)arg;
    char *alien_text = data->alien_text;
    char *human_text = data->human_text;
    int index = data->index;

    // Parse alien text
    char *start = strstr(alien_text, ALIEN_START);
    char *end = strstr(start, ALIEN_END);
    if (start == NULL || end == NULL) {
        return NULL;
    }

    // Extract alien word
    char alien_word[256] = {0};
    strncpy(alien_word, start + strlen(ALIEN_START), end - start - strlen(ALIEN_START));

    // Convert alien word to human word
    char human_word[256] = {0};
    // Your translation logic here...
    sprintf(human_word, "Hello");

    // Append human word to human text
    sprintf(human_text + index * 256, "%s", human_word);

    return NULL;
}

int main() {
    // Initialize alien text
    char alien_text[] = "<ALIEN>XEYRX<ALIEN> <ALIEN>ROFXOY<ALIEN>";

    // Allocate memory for human text
    char *human_text = malloc(1024);
    memset(human_text, 0, 1024);

    // Create thread pool
    int num_threads = 2;
    pthread_t threads[num_threads];
    thread_data data[num_threads];

    // Split alien text into multiple chunks
    int chunk_size = strlen(alien_text) / num_threads;
    int index = 0;
    for (int i = 0; i < num_threads; i++) {
        data[i].alien_text = &alien_text[index];
        data[i].human_text = human_text;
        data[i].index = i;
        index += chunk_size;
    }

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, alien_to_human, &data[i]);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print human text
    printf("%s\n", human_text);

    // Free memory
    free(human_text);

    return 0;
}