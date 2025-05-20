//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_INPUT_LEN 1000

struct thread_data {
    char* input;
    char* output;
};

int is_valid_char(char c) {
    // A valid character in a URL is any alphanumeric character or one of the following: - _ . ~
    return (c > 47 && c < 58) || // numeric (0-9)
           (c > 64 && c < 91) || // upper alpha (A-Z)
           (c > 96 && c < 123) || // lower alpha (a-z)
           c == '-' || c == '_' || c == '.' || c == '~';
}

void* sanitize_url(void* arg) {
    struct thread_data* thread_args = (struct thread_data*)arg;
    char* input = thread_args->input;
    char* output = thread_args->output;
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (is_valid_char(input[i])) {
            output[j++] = input[i];
        } else if (input[i] == ' ') {
            output[j++] = '+';
        } else {
            output[j++] = '%';
            sprintf(output + j, "%02X", input[i]);
            j += 2;
        }
        if (j >= MAX_INPUT_LEN - 1) break;
    }
    output[j] = '\0';
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./url_sanitizer [URL1] [URL2] ... [URLN]\n");
        exit(1);
    }
    int num_threads = argc - 1;
    pthread_t threads[num_threads];
    struct thread_data thread_data_arr[num_threads];
    for (int i = 0; i < num_threads; i++) {
        thread_data_arr[i].input = argv[i + 1];
        thread_data_arr[i].output = malloc(MAX_INPUT_LEN);
        pthread_create(&threads[i], NULL, sanitize_url, &thread_data_arr[i]);
    }
    char* sanitized_urls[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        sanitized_urls[i] = thread_data_arr[i].output;
        printf("Sanitized URL %d: %s\n", i + 1, sanitized_urls[i]);
        free(thread_data_arr[i].output);
    }
    return 0;
}