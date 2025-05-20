//Falcon-180B DATASET v1.0 Category: Sorting ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int size;
} String;

void init_string(String *s) {
    s->data = (char *)malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
    s->data[0] = '\0';
}

void append_string(String *s, const char *str) {
    int len = strlen(str);
    if (s->size + len >= MAX_SIZE) {
        printf("Error: string is too long\n");
        return;
    }
    strcat(s->data, str);
    s->size += len;
}

int compare_string(const void *a, const void *b) {
    String *s1 = (String *)a;
    String *s2 = (String *)b;
    return strcmp(s1->data, s2->data);
}

void print_string(const String *s) {
    printf("%s", s->data);
}

void free_string(String *s) {
    free(s->data);
}

int main() {
    String *strings = (String *)malloc(10 * sizeof(String));
    int num_strings = 0;

    char input[100];
    while (fgets(input, 100, stdin)!= NULL) {
        if (num_strings >= 10) {
            printf("Error: too many strings\n");
            break;
        }
        init_string(&strings[num_strings]);
        append_string(&strings[num_strings], input);
        num_strings++;
    }

    qsort(strings, num_strings, sizeof(String), compare_string);

    for (int i = 0; i < num_strings; i++) {
        print_string(&strings[i]);
        free_string(&strings[i]);
    }

    free(strings);
    return 0;
}