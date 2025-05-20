//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_STRING_LENGTH 100
#define THREAD_COUNT 3

typedef struct {
    char input[MAX_STRING_LENGTH];
    char result[MAX_STRING_LENGTH];
} string_data;

void *reverse_string(void *data) {
    string_data *str_data = (string_data *)data;
    int n = strlen(str_data->input);
    
    for (int i = 0; i < n; i++) {
        str_data->result[i] = str_data->input[n - i - 1];
    }
    str_data->result[n] = '\0';
    pthread_exit(NULL);
}

void *to_uppercase(void *data) {
    string_data *str_data = (string_data *)data;
    
    for (int i = 0; str_data->input[i]; i++) {
        str_data->result[i] = toupper(str_data->input[i]);
    }
    str_data->result[strlen(str_data->input)] = '\0';
    pthread_exit(NULL);
}

void *concatenate_strings(void *data) {
    string_data *str_data = (string_data *)data;
    
    snprintf(str_data->result, sizeof(str_data->result), "%s %s", str_data->input, str_data->input);
    pthread_exit(NULL);
}

void print_usage() {
    printf("Usage: ./string_manipulation <input_string>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    pthread_t threads[THREAD_COUNT];
    string_data str_data;
    strncpy(str_data.input, argv[1], MAX_STRING_LENGTH);
    
    char choice;
    printf("Choose an operation:\n");
    printf("1. Reverse String\n");
    printf("2. Uppercase String\n");
    printf("3. Concatenate String with itself\n");
    printf("Enter your choice (1/2/3): ");
    
    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            pthread_create(&threads[0], NULL, reverse_string, (void *)&str_data);
            pthread_join(threads[0], NULL);
            printf("Reversed String: %s\n", str_data.result);
            break;
            
        case '2':
            pthread_create(&threads[0], NULL, to_uppercase, (void *)&str_data);
            pthread_join(threads[0], NULL);
            printf("Uppercase String: %s\n", str_data.result);
            break;
            
        case '3':
            pthread_create(&threads[0], NULL, concatenate_strings, (void *)&str_data);
            pthread_join(threads[0], NULL);
            printf("Concatenated String: %s\n", str_data.result);
            break;

        default:
            printf("Invalid choice.\n");
            pthread_exit(NULL);
    }

    return EXIT_SUCCESS;
}