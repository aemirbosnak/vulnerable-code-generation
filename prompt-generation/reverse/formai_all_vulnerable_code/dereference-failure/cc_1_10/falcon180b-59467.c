//Falcon-180B DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#define MAX_SIZE 10000

typedef struct {
    int size;
    int capacity;
    char *data;
} String;

void init_string(String *s) {
    s->size = 0;
    s->capacity = MAX_SIZE;
    s->data = (char *)malloc(s->capacity * sizeof(char));
    if (s->data == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    s->data[0] = '\0';
}

void destroy_string(String *s) {
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
}

void resize_string(String *s) {
    s->capacity *= 2;
    s->data = (char *)realloc(s->data, s->capacity * sizeof(char));
    if (s->data == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    s->data[s->size] = '\0';
}

void concat_string(String *s1, const char *s2) {
    int len = strlen(s2);
    int new_size = s1->size + len;
    if (new_size >= s1->capacity) {
        resize_string(s1);
    }
    strcat(s1->data, s2);
    s1->size = new_size;
}

void reverse_string(String *s) {
    char *start = s->data;
    char *end = start + s->size - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    String s1, s2;
    init_string(&s1);
    init_string(&s2);

    concat_string(&s1, "Hello, ");
    concat_string(&s1, "world!");

    printf("Original string: %s\n", s1.data);

    reverse_string(&s1);

    printf("Reversed string: %s\n", s1.data);

    destroy_string(&s1);
    destroy_string(&s2);

    return 0;
}