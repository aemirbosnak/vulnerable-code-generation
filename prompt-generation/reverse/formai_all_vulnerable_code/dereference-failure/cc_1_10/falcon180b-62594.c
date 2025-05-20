//Falcon-180B DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
} String;

// Function to allocate memory for a new string
String *string_new(const char *data) {
    String *s = malloc(sizeof(String));
    if (s == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    s->data = strdup(data);
    s->size = strlen(data);
    return s;
}

// Function to free memory used by a string
void string_free(String *s) {
    if (s == NULL) {
        fprintf(stderr, "Error: Invalid pointer\n");
        exit(1);
    }
    free(s->data);
    free(s);
}

// Function to concatenate two strings
String *string_concat(String *s1, String *s2) {
    String *result = malloc(sizeof(String));
    if (result == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    result->data = malloc(s1->size + s2->size + 1);
    if (result->data == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    strcpy(result->data, s1->data);
    strcat(result->data, s2->data);
    result->size = s1->size + s2->size;
    string_free(s1);
    string_free(s2);
    return result;
}

int main() {
    String *s1 = string_new("Hello");
    String *s2 = string_new(" world");
    String *s3 = string_concat(s1, s2);
    printf("String: %s\n", s3->data);
    string_free(s3);
    return 0;
}