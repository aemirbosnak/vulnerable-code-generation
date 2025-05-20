//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

String* string_create() {
    String *s = (String*)malloc(sizeof(String));
    s->data = (char*)malloc(MAX_SIZE);
    s->size = 0;
    return s;
}

void string_destroy(String *s) {
    free(s->data);
    free(s);
}

void string_append(String *s, const char *c) {
    int len = strlen(c);
    if (s->size + len >= MAX_SIZE) {
        printf("Error: string overflow\n");
        return;
    }
    strncat(s->data, c, len);
    s->size += len;
}

void string_print(const String *s) {
    printf("%s", s->data);
}

int main() {
    String *s1 = string_create();
    String *s2 = string_create();

    string_append(s1, "Hello");
    string_append(s1, ", ");
    string_append(s1, "world!");

    string_append(s2, "The ");
    string_append(s2, "quick ");
    string_append(s2, "brown ");
    string_append(s2, "fox ");
    string_append(s2, "jumps ");
    string_append(s2, "over ");
    string_append(s2, "the ");
    string_append(s2, "lazy ");
    string_append(s2, "dog.");

    string_print(s1);
    printf("\n");
    string_print(s2);

    string_destroy(s1);
    string_destroy(s2);

    return 0;
}