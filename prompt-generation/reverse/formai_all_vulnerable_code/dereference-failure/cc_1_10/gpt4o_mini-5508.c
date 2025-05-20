//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *json_string;
    char *key;
    char *value;
} ParseTask;

void *parse_json(void *arg) {
    ParseTask *task = (ParseTask *)arg;
    char *json = task->json_string;

    char *key_start = strstr(json, task->key);
    if (key_start) {
        key_start += strlen(task->key) + 2; // Skip over the key and the quote
        char *value_start = key_start;
        while (*value_start != '"' && *value_start != '\0') {
            value_start++;
        }
        
        if (*value_start == '"') {
            *value_start = '\0'; // Terminate the string at the end of the value
            task->value = strdup(key_start); // Copy the value
            *value_start = '"'; // Restore the original string
            printf("Parsed: %s = %s\n", task->key, task->value);
        } else {
            printf("Value for key '%s' not found.\n", task->key);
        }
    } else {
        printf("Key '%s' not found in JSON.\n", task->key);
    }
    
    return NULL;
}

void free_parse_task(ParseTask *task) {
    free(task->value);
    free(task->json_string);
    free(task->key);
    free(task);
}

int main() {
    char *json_data = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";
    
    char *keys[] = {"name", "age", "city"};
    int num_keys = sizeof(keys) / sizeof(keys[0]);
    pthread_t threads[num_keys];
    
    for (int i = 0; i < num_keys; i++) {
        ParseTask *task = malloc(sizeof(ParseTask));
        task->json_string = strdup(json_data);
        task->key = strdup(keys[i]);
        task->value = NULL;

        // Create a new thread to parse the key in the JSON data
        if (pthread_create(&threads[i], NULL, parse_json, task) != 0) {
            fprintf(stderr, "Error creating thread for key '%s'\n", keys[i]);
            free_parse_task(task);
            continue;
        }

        // Sleep for a short duration to simulate the asynchronous nature
        usleep(100);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_keys; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up the resources
    printf("All parsing completed.\n");
    
    return 0;
}