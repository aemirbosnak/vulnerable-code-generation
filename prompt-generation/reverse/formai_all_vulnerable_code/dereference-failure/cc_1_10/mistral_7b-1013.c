//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024
#define NUM_STRS 5

typedef struct {
    char str[MAX_STR_LEN];
    size_t len;
} string_t;

void reverse_string(char *str, size_t len) {
    char *start = str;
    char *end = str + len - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

string_t *create_strings(int num_strs) {
    string_t *strings = calloc(num_strs, sizeof(string_t));

    for (size_t i = 0; i < num_strs; i++) {
        sprintf(strings[i].str, "String %ld", i + 1);
        strings[i].len = strlen(strings[i].str);
    }

    return strings;
}

void print_strings(string_t *strings, int num_strs) {
    for (size_t i = 0; i < num_strs; i++) {
        printf("String %ld: %.*s\n", i + 1, strings[i].len, strings[i].str);
    }
}

void reverse_strings(string_t *strings, int num_strs) {
    for (size_t i = 0; i < num_strs; i++) {
        reverse_string(strings[i].str, strings[i].len);
    }
}

int main() {
    string_t *strings;

    strings = create_strings(NUM_STRS);
    print_strings(strings, NUM_STRS);

    reverse_strings(strings, NUM_STRS);
    print_strings(strings, NUM_STRS);

    free(strings);

    return 0;
}