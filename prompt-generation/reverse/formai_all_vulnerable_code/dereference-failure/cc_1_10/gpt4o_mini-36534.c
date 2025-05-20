//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 4
#define BUFFER_SIZE 256

typedef struct {
    char **data;
    size_t size;
    size_t capacity; 
} StringArray;

StringArray* create_string_array() {
    StringArray *arr = malloc(sizeof(StringArray));
    arr->data = malloc(INITIAL_CAPACITY * sizeof(char *));
    arr->size = 0;
    arr->capacity = INITIAL_CAPACITY;
    return arr;
}

void free_string_array(StringArray *arr) {
    for (size_t i = 0; i < arr->size; ++i) {
        free(arr->data[i]);
    }
    free(arr->data);
    free(arr);
}

void resize_string_array(StringArray *arr) {
    size_t new_capacity = arr->capacity * 2;
    arr->data = realloc(arr->data, new_capacity * sizeof(char *));
    arr->capacity = new_capacity;
}

void add_string(StringArray *arr, const char *str) {
    if (arr->size >= arr->capacity) {
        resize_string_array(arr);
    }
    arr->data[arr->size] = malloc(strlen(str) + 1);
    strcpy(arr->data[arr->size], str);
    arr->size++;
}

void remove_string(StringArray *arr, const char *str) {
    for (size_t i = 0; i < arr->size; ++i) {
        if (strcmp(arr->data[i], str) == 0) {
            free(arr->data[i]);
            arr->data[i] = arr->data[arr->size - 1];
            arr->size--;
            return; 
        }
    }
}

void display_strings(const StringArray *arr) {
    for (size_t i = 0; i < arr->size; ++i) {
        printf("%s\n", arr->data[i]);
    }
}

int main() {
    StringArray *my_strings = create_string_array();
    char buffer[BUFFER_SIZE];
    
    while (1) {
        printf("Enter a string (or type 'exit' to quit, 'remove [string]' to remove): ");
        if (!fgets(buffer, BUFFER_SIZE, stdin)) {
            break; 
        }
        
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline
        
        if (strcmp(buffer, "exit") == 0) {
            break;
        } else if (strncmp(buffer, "remove ", 7) == 0) {
            remove_string(my_strings, buffer + 7);
        } else {
            add_string(my_strings, buffer);
        }

        printf("Current strings:\n");
        display_strings(my_strings);
    }

    free_string_array(my_strings);
    return 0;
}