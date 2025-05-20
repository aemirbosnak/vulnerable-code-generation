//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} string_t;

string_t *create_string(char *data, int size) {
    string_t *s = malloc(sizeof(string_t));
    s->data = malloc(size * sizeof(char));
    s->size = size;
    strcpy(s->data, data);
    return s;
}

void free_string(string_t *s) {
    free(s->data);
    free(s);
}

string_t *concat_strings(string_t *s1, string_t *s2) {
    int size = s1->size + s2->size;
    char *data = malloc(size * sizeof(char));
    strcpy(data, s1->data);
    strcat(data, s2->data);
    free_string(s1);
    free_string(s2);
    string_t *result = create_string(data, size);
    return result;
}

string_t *copy_string(string_t *s) {
    string_t *result = create_string(s->data, s->size);
    return result;
}

bool compare_strings(string_t *s1, string_t *s2) {
    return strcmp(s1->data, s2->data) == 0;
}

int main() {
    string_t *s1 = create_string("Hello", 5);
    string_t *s2 = create_string("World", 5);
    string_t *s3 = concat_strings(s1, s2);
    string_t *s4 = copy_string(s3);
    if (compare_strings(s1, s4)) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }
    free_string(s1);
    free_string(s2);
    free_string(s3);
    free_string(s4);
    return 0;
}