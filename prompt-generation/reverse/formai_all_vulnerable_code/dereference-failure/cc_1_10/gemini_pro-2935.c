//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int length;
    int capacity;
} String;

String string_new(const char *str) {
    String string;
    string.length = strlen(str);
    string.capacity = string.length + 1;
    string.data = malloc(string.capacity);
    strcpy(string.data, str);
    return string;
}

void string_free(String *string) {
    free(string->data);
    string->data = NULL;
    string->length = 0;
    string->capacity = 0;
}

String string_append(String *string, const char *str) {
    int new_length = string->length + strlen(str);
    if (new_length > string->capacity) {
        string->capacity *= 2;
        string->data = realloc(string->data, string->capacity);
    }
    strcpy(string->data + string->length, str);
    string->length = new_length;
    return *string;
}

String string_replace(String *string, const char *old, const char *new) {
    int old_length = strlen(old);
    int new_length = strlen(new);
    int offset = 0;
    while ((offset = strstr(string->data + offset, old) - string->data) >= 0) {
        string->length += new_length - old_length;
        if (string->length > string->capacity) {
            string->capacity *= 2;
            string->data = realloc(string->data, string->capacity);
        }
        memmove(string->data + offset + new_length, string->data + offset + old_length, string->length - offset - new_length + 1);
        memcpy(string->data + offset, new, new_length);
        offset += new_length;
    }
    return *string;
}

int main() {
    String string = string_new("Hello world!");
    string = string_append(&string, " This is a test.");
    string = string_replace(&string, "world", "universe");
    printf("%s\n", string.data);
    string_free(&string);
    return 0;
}