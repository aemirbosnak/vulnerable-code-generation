//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_STRING_LENGTH 1024
#define THREAD_COUNT 4

typedef struct {
    char *string_part;
    int part_number;
} StringPart;

void *manipulate_string(void *arg) {
    StringPart *part = (StringPart *)arg;
    printf("Thread %d received string part: '%s'\n", part->part_number, part->string_part);

    // Convert the string to uppercase
    for (int i = 0; part->string_part[i]; i++) {
        part->string_part[i] = toupper(part->string_part[i]);
    }

    printf("Thread %d transformed string part to: '%s'\n", part->part_number, part->string_part);
    return NULL;
}

void distribute_string(const char *input_string) {
    int length = strlen(input_string);
    int part_length = length / THREAD_COUNT;
    
    pthread_t threads[THREAD_COUNT];
    StringPart string_parts[THREAD_COUNT];

    // Divide the string into parts and create threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        string_parts[i].part_number = i;

        // Handling the last part to include any remaining characters
        if (i == THREAD_COUNT - 1) {
            string_parts[i].string_part = malloc(length - i * part_length + 1);
            strncpy(string_parts[i].string_part, input_string + i * part_length, length - i * part_length);
            string_parts[i].string_part[length - i * part_length] = '\0'; // null-terminate
        } else {
            string_parts[i].string_part = malloc(part_length + 1);
            strncpy(string_parts[i].string_part, input_string + i * part_length, part_length);
            string_parts[i].string_part[part_length] = '\0'; // null-terminate
        }

        pthread_create(&threads[i], NULL, manipulate_string, (void *)&string_parts[i]);
    }

    // Join threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
        free(string_parts[i].string_part); // Free the allocated memory
    }
}

int main() {
    char input[MAX_STRING_LENGTH];

    printf("Enter a string to manipulate (max length %d): ", MAX_STRING_LENGTH - 1);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character

    distribute_string(input);

    return 0;
}