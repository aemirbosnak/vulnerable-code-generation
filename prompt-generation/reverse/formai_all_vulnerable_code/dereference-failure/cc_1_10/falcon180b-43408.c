//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    char *data;
    int size;
} String;

void init(String *s) {
    s->data = (char *)malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
}

void append(String *s, char c) {
    if (s->size >= MAX_SIZE) {
        printf("Error: String is full.\n");
        exit(1);
    }
    s->data[s->size] = c;
    s->size++;
}

void print(String s) {
    printf("%s", s.data);
}

int search(String s, char c) {
    int i;
    for (i = 0; i < s.size; i++) {
        if (s.data[i] == c) {
            return i;
        }
    }
    return -1;
}

int main() {
    String s;
    init(&s);
    char input[100];
    int n;

    printf("Enter a string: ");
    scanf("%s", input);
    n = strlen(input);

    printf("Enter a character to search for: ");
    scanf(" %c", &input[n]);

    append(&s, input[n]);
    int index = search(s, input[n]);

    if (index == -1) {
        printf("Character not found.\n");
    } else {
        printf("Character found at position %d.\n", index);
    }

    return 0;
}