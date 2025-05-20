//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

typedef struct {
    char* str;
    int len;
} String;

String* string_create(char* str) {
    String* s = (String*)malloc(sizeof(String));
    s->str = (char*)malloc(strlen(str) + 1);
    strcpy(s->str, str);
    s->len = strlen(str);
    return s;
}

int string_compare(String* s1, String* s2) {
    return strcmp(s1->str, s2->str);
}

void string_free(String* s) {
    free(s->str);
    free(s);
}

void string_print(String* s) {
    printf("%s\n", s->str);
}

int main() {
    char input[MAX_STR_LEN];
    String* strings = NULL;
    int num_strings = 0;

    while (fgets(input, MAX_STR_LEN, stdin)!= NULL) {
        String* s = string_create(input);
        strings = (String*)realloc(strings, sizeof(String) * ++num_strings);
        strings[num_strings - 1] = *s;
        string_free(s);
    }

    qsort(strings, num_strings, sizeof(String), string_compare);

    for (int i = 0; i < num_strings; ++i) {
        string_print(strings + i);
    }

    free(strings);
    return 0;
}