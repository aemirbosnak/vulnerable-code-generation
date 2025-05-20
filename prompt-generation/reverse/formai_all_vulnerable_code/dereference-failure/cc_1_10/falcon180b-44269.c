//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100000

typedef struct {
    char *data;
    int size;
} String;

void init_string(String *s) {
    s->data = (char *)malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
    s->data[0] = '\0';
}

void append_string(String *s, char c) {
    if (s->size >= MAX_SIZE) {
        printf("Error: String is too long.\n");
        exit(1);
    }
    s->data[s->size++] = c;
    s->data[s->size] = '\0';
}

void print_string(String s) {
    printf("%s", s.data);
}

int main() {
    String input_string, reversed_string;

    init_string(&input_string);
    init_string(&reversed_string);

    char c;
    while ((c = getchar())!= '\n') {
        if (!isalpha(c)) {
            printf("Error: Input must contain only letters.\n");
            exit(1);
        }
        append_string(&input_string, tolower(c));
    }

    int i, j;
    for (i = 0, j = input_string.size - 1; i < j; i++, j--) {
        char temp = input_string.data[i];
        input_string.data[i] = input_string.data[j];
        input_string.data[j] = temp;
    }

    print_string(input_string);

    return 0;
}