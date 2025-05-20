//Falcon-180B DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    size_t size;
} string_t;

string_t *string_create(const char *str) {
    size_t len = strlen(str);
    string_t *s = malloc(sizeof(string_t));
    if (s == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        exit(1);
    }
    s->data = malloc(len + 1);
    if (s->data == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        exit(1);
    }
    strcpy(s->data, str);
    s->size = len;
    return s;
}

void string_destroy(string_t *s) {
    free(s->data);
    free(s);
}

int main() {
    char input[MAX_SIZE];
    string_t *s1, *s2;

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    s1 = string_create(input);

    printf("The length of the string is %zu.\n", s1->size);

    s2 = string_create(s1->data);

    printf("The length of the string is %zu.\n", s2->size);

    string_destroy(s1);
    string_destroy(s2);

    return 0;
}