//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 100

typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} DynamicString;

DynamicString* create_dynamic_string() {
    DynamicString *ds = (DynamicString*) malloc(sizeof(DynamicString));
    ds->data = (char*) malloc(INITIAL_CAPACITY * sizeof(char));
    ds->length = 0;
    ds->capacity = INITIAL_CAPACITY;
    return ds;
}

void free_dynamic_string(DynamicString* ds) {
    free(ds->data);
    free(ds);
}

void resize_dynamic_string(DynamicString* ds, size_t new_capacity) {
    if(new_capacity > ds->capacity) {
        ds->data = (char*) realloc(ds->data, new_capacity * sizeof(char));
        ds->capacity = new_capacity;
    }
}

void append_to_dynamic_string(DynamicString* ds, const char* str) {
    size_t str_length = strlen(str);
    while(ds->length + str_length >= ds->capacity) {
        resize_dynamic_string(ds, ds->capacity * 2);
    }
    strcpy(ds->data + ds->length, str);
    ds->length += str_length;
}

void insert_into_dynamic_string(DynamicString* ds, const char* str, size_t position) {
    if(position > ds->length) {
        printf("Insertion position out of bounds.\n");
        return;
    }
    size_t str_length = strlen(str);
    while(ds->length + str_length >= ds->capacity) {
        resize_dynamic_string(ds, ds->capacity * 2);
    }
    memmove(ds->data + position + str_length, ds->data + position, ds->length - position + 1);
    memcpy(ds->data + position, str, str_length);
    ds->length += str_length;
}

void erase_from_dynamic_string(DynamicString* ds, size_t position, size_t num) {
    if(position >= ds->length) {
        printf("Erase position out of bounds.\n");
        return;
    }
    if(position + num > ds->length) {
        num = ds->length - position;
    }
    memmove(ds->data + position, ds->data + position + num, ds->length - position - num + 1);
    ds->length -= num;
}

void print_dynamic_string(DynamicString* ds) {
    printf("Dynamic String: %s\n", ds->data);
}

void replace_in_dynamic_string(DynamicString* ds, const char* old, const char* new) {
    size_t old_length = strlen(old);
    size_t new_length = strlen(new);
    char *pos = strstr(ds->data, old);
    while(pos) {
        size_t index = pos - ds->data;
        if(new_length != old_length) {
            if(new_length > old_length) {
                resize_dynamic_string(ds, ds->capacity + (new_length - old_length));
            }
            memmove(ds->data + index + new_length, ds->data + index + old_length, ds->length - index - old_length + 1);
        }
        memcpy(ds->data + index, new, new_length);
        ds->length += (new_length - old_length);
        pos = strstr(ds->data + index + new_length, old);
    }
}

int main() {
    DynamicString *dynamicString = create_dynamic_string();
    append_to_dynamic_string(dynamicString, "Hello, World! ");
    print_dynamic_string(dynamicString);

    append_to_dynamic_string(dynamicString, "Welcome to C programming. ");
    print_dynamic_string(dynamicString);

    insert_into_dynamic_string(dynamicString, "It's a powerful language. ", 18);
    print_dynamic_string(dynamicString);

    replace_in_dynamic_string(dynamicString, "powerful", "versatile");
    print_dynamic_string(dynamicString);

    erase_from_dynamic_string(dynamicString, 12, 5);
    print_dynamic_string(dynamicString);

    replace_in_dynamic_string(dynamicString, "C programming", "C programming language");
    print_dynamic_string(dynamicString);

    free_dynamic_string(dynamicString);
    return 0;
}