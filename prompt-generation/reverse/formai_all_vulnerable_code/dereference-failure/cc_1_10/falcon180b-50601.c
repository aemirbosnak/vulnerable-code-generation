//Falcon-180B DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *str;
    int size;
} String;

String create_string(const char *init_str) {
    String str;
    str.str = malloc(MAX_SIZE * sizeof(char));
    str.size = strlen(init_str);
    strncpy(str.str, init_str, str.size);
    str.str[str.size] = '\0';
    return str;
}

void append_string(String *str, const char *to_append) {
    int new_size = str->size + strlen(to_append);
    str->str = realloc(str->str, new_size * sizeof(char));
    strcat(str->str, to_append);
    str->size = new_size;
}

void delete_string(String *str) {
    free(str->str);
    str->str = NULL;
    str->size = 0;
}

int main() {
    String str1 = create_string("Hello, world!");
    printf("str1: %s\n", str1.str);

    append_string(&str1, " This is a test.");
    printf("str1: %s\n", str1.str);

    String str2 = create_string("Another string");
    printf("str2: %s\n", str2.str);

    delete_string(&str2);
    printf("str2: %s\n", str2.str);

    delete_string(&str1);
    printf("str1: %s\n", str1.str);

    return 0;
}