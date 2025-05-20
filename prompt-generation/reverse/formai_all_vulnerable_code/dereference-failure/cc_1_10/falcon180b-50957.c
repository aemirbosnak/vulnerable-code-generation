//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *data;
    int size;
} String;

void init_string(String *s) {
    s->data = (char *) malloc(MAX_SIZE);
    s->size = 0;
}

void append_string(String *s, char *str) {
    int len = strlen(str);
    if (s->size + len >= MAX_SIZE) {
        printf("String is too long!\n");
        return;
    }
    strcat(s->data, str);
    s->size += len;
}

void concat_strings(String *dest, String *src) {
    int len = strlen(src->data);
    if (dest->size + len >= MAX_SIZE) {
        printf("String is too long!\n");
        return;
    }
    strcat(dest->data, src->data);
    dest->size += len;
}

void print_string(String *s) {
    printf("%s\n", s->data);
}

int main() {
    String s1, s2, s3;

    init_string(&s1);
    init_string(&s2);
    init_string(&s3);

    append_string(&s1, "Hello");
    append_string(&s1, " ");
    append_string(&s1, "world");

    append_string(&s2, "C");
    append_string(&s2, " is a programming language");

    concat_strings(&s3, &s1);
    concat_strings(&s3, &s2);

    print_string(&s1);
    print_string(&s2);
    print_string(&s3);

    free(s1.data);
    free(s2.data);
    free(s3.data);

    return 0;
}