//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t size;
    char* str;
} String;

String* create_string(const size_t size) {
    String* str = (String*) calloc(1, sizeof(String));
    if (str == NULL) {
        fprintf(stderr, "Out of memory\n");
        return NULL;
    }
    str->str = malloc(size * sizeof(char));
    if (str->str == NULL) {
        free(str);
        fprintf(stderr, "Out of memory\n");
        return NULL;
    }
    str->size = size;
    return str;
}

void destroy_string(String* str) {
    free(str->str);
    free(str);
}

String* concat_strings(String* a, String* b) {
    if (a->size + b->size + 1 > a->size) {
        a->str = realloc(a->str, (a->size + b->size + 1) * sizeof(char));
        if (a->str == NULL) {
            fprintf(stderr, "Out of memory\n");
            return NULL;
        }
    }
    strcpy(a->str + a->size, b->str);
    a->size += b->size;
    destroy_string(b);
    return a;
}

int main() {
    const size_t size_a = 5, size_b = 10;
    String* str_a = create_string(size_a);
    String* str_b = create_string(size_b);

    if (str_a != NULL && str_b != NULL) {
        strcpy(str_a->str, "Hello");
        strcpy(str_b->str, "World");

        printf("Before concatenation:\n");
        printf("String A: %s\n", str_a->str);
        printf("String B: %s\n", str_b->str);

        String* str_c = concat_strings(str_a, str_b);

        printf("After concatenation:\n");
        printf("String A: %s\n", str_a->str);
        printf("String B: %s\n", str_b->str);
        printf("Concatenated String: %s\n", str_c->str);

        destroy_string(str_c);
        destroy_string(str_b);
        destroy_string(str_a);
    }

    return EXIT_SUCCESS;
}