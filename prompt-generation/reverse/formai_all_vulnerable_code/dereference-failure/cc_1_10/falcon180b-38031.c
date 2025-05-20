//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024 * 1024 // 1 MB

typedef struct {
    char* buffer;
    size_t length;
    size_t capacity;
} String;

String* string_create() {
    String* result = malloc(sizeof(String));
    result->buffer = calloc(MAX_STRING_LENGTH, sizeof(char));
    result->length = 0;
    result->capacity = MAX_STRING_LENGTH;
    return result;
}

void string_destroy(String* str) {
    free(str->buffer);
    free(str);
}

void string_append(String* str, const char* data, size_t len) {
    if (str->length + len >= str->capacity) {
        str->capacity *= 2;
        str->buffer = realloc(str->buffer, str->capacity);
    }
    memcpy(str->buffer + str->length, data, len);
    str->length += len;
}

void string_clear(String* str) {
    str->length = 0;
}

char* string_data(String* str) {
    return str->buffer;
}

size_t string_length(String* str) {
    return str->length;
}

// HTML beautifier
String* html_beautify(const char* input) {
    String* result = string_create();
    const char* start = input;
    char* end;
    while ((end = strchr(start, '<'))!= NULL) {
        string_append(result, start, end - start);
        start = end + 1;
        while (*start!= '>') {
            if (start - input >= MAX_STRING_LENGTH) {
                printf("Error: Tag name too long.\n");
                string_destroy(result);
                return NULL;
            }
            start++;
        }
        string_append(result, " ", 1);
        start++;
    }
    string_append(result, start, strlen(start));
    return result;
}

int main() {
    const char* input = "<html><head><title>Hello, world!</title></head><body><p>This is a <b>test</b>.</p></body></html>";
    String* result = html_beautify(input);
    if (result!= NULL) {
        printf("%s\n", string_data(result));
        string_destroy(result);
    }
    return 0;
}