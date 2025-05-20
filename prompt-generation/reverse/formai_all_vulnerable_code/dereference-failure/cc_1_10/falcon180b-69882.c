//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

String *string_create(const char *str) {
    String *s = (String *)malloc(sizeof(String));
    s->data = strdup(str);
    s->size = strlen(str);
    return s;
}

String *string_concat(String *s1, String *s2) {
    String *result = (String *)malloc(sizeof(String));
    result->data = (char *)malloc((s1->size + s2->size + 1) * sizeof(char));
    strcpy(result->data, s1->data);
    strcat(result->data, s2->data);
    result->size = s1->size + s2->size;
    free(s1->data);
    free(s2->data);
    free(s1);
    free(s2);
    return result;
}

void string_print(String *s) {
    printf("%s (%d)\n", s->data, s->size);
}

void string_destroy(String *s) {
    free(s->data);
    free(s);
}

int main() {
    String *s1 = string_create("Hello");
    String *s2 = string_create("World");
    String *s3 = string_concat(s1, s2);
    string_print(s1);
    string_print(s2);
    string_print(s3);
    string_destroy(s1);
    string_destroy(s2);
    string_destroy(s3);
    return 0;
}