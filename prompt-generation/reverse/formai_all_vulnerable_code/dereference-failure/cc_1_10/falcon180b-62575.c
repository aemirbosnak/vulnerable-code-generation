//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

void init(String *str) {
    str->data = (char *)malloc(MAX_SIZE * sizeof(char));
    str->size = 0;
}

void append(String *str, char ch) {
    str->data[str->size++] = ch;
    str->data[str->size] = '\0';
}

void print(String str) {
    printf("%s", str.data);
}

int main() {
    String text, pattern;
    char ch;

    init(&text);
    init(&pattern);

    printf("Enter the text: ");
    while ((ch = getchar())!= '\n') {
        append(&text, ch);
    }

    printf("Enter the pattern: ");
    while ((ch = getchar())!= '\n') {
        append(&pattern, ch);
    }

    int n = text.size, m = pattern.size, i = 0, j = 0;
    while (i < n) {
        if (text.data[i] == pattern.data[j]) {
            i++, j++;
        } else {
            j = 0;
        }
    }

    if (j == m) {
        printf("Pattern found at position %d\n", i - m);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}