//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

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
        printf("String is full.\n");
        return;
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

    printf("Enter a string: ");
    char c;
    while ((c = getchar())!= '\n') {
        if (isalpha(c)) {
            append_string(&input_string, tolower(c));
        }
    }

    int i = input_string.size - 1;
    while (i >= 0) {
        append_string(&reversed_string, input_string.data[i]);
        i--;
    }

    printf("Reversed string: ");
    print_string(reversed_string);

    return 0;
}