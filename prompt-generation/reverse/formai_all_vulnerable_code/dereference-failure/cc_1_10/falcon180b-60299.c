//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *data;
    int size;
} String;

String *newString(int size) {
    String *s = malloc(sizeof(String));
    s->data = malloc(size * sizeof(char));
    s->size = size;
    return s;
}

void deleteString(String *s) {
    free(s->data);
    free(s);
}

void appendChar(String *s, char c) {
    if (s->size == 0) {
        s->data = malloc(1 * sizeof(char));
        s->size = 1;
    } else {
        s->data = realloc(s->data, s->size + 1);
        s->size++;
    }
    s->data[s->size - 1] = c;
}

void appendString(String *s, char *str) {
    int len = strlen(str);
    if (s->size == 0) {
        s->data = malloc(len * sizeof(char));
        s->size = len;
    } else {
        s->data = realloc(s->data, s->size + len);
        s->size += len;
    }
    memcpy(s->data + s->size - len, str, len);
}

void reverseString(String *s) {
    char *start = s->data;
    char *end = s->data + s->size - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    String *s1 = newString(MAX_SIZE);
    String *s2 = newString(MAX_SIZE);
    int n;
    scanf("%d", &n);
    char input[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        scanf("%s", input);
        appendString(s1, input);
        appendString(s2, input);
    }
    reverseString(s2);
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (s1->data[i]!= s2->data[n - i - 1]) {
            result = 1;
            break;
        }
    }
    if (result == 0) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }
    deleteString(s1);
    deleteString(s2);
    return 0;
}