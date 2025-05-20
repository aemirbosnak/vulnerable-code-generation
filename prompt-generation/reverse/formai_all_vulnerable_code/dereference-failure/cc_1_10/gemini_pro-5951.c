//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *string;
    int length;
} String;

String *new_string(const char *str) {
    String *s = malloc(sizeof(String));
    s->string = strdup(str);
    s->length = strlen(str);
    return s;
}

void free_string(String *s) {
    free(s->string);
    free(s);
}

String *concatenate(const String *s1, const String *s2) {
    String *s = malloc(sizeof(String));
    s->length = s1->length + s2->length;
    s->string = malloc(s->length + 1);
    strcpy(s->string, s1->string);
    strcat(s->string, s2->string);
    return s;
}

String *substring(const String *s, int start, int end) {
    if (start < 0 || start >= s->length || end < 0 || end > s->length) {
        return NULL;
    }
    String *substring = malloc(sizeof(String));
    substring->length = end - start;
    substring->string = malloc(substring->length + 1);
    strncpy(substring->string, s->string + start, substring->length);
    substring->string[substring->length] = '\0';
    return substring;
}

int compare(const String *s1, const String *s2) {
    return strcmp(s1->string, s2->string);
}

int main() {
    String *s1 = new_string("Hello");
    String *s2 = new_string("World");
    String *s3 = concatenate(s1, s2);
    printf("%s\n", s3->string); // HelloWorld
    String *s4 = substring(s3, 6, 10);
    printf("%s\n", s4->string); // World
    int result = compare(s1, s2);
    printf("%d\n", result); // -1
    free_string(s1);
    free_string(s2);
    free_string(s3);
    free_string(s4);
    return 0;
}