//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    char *data;
    int size;
} String;

void init_string(String *s) {
    s->data = malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
}

void append_string(String *s, char c) {
    s->data[s->size++] = c;
}

void reverse_string(String *s) {
    int start = 0;
    int end = s->size - 1;
    char temp;

    while (start < end) {
        temp = s->data[start];
        s->data[start] = s->data[end];
        s->data[end] = temp;
        start++;
        end--;
    }
}

int main() {
    String s1, s2;
    init_string(&s1);
    init_string(&s2);

    append_string(&s1, 'h');
    append_string(&s1, 'e');
    append_string(&s1, 'l');
    append_string(&s1, 'l');
    append_string(&s1, 'o');
    append_string(&s1, '\0');

    append_string(&s2, 'w');
    append_string(&s2, 'o');
    append_string(&s2, 'r');
    append_string(&s2, 'l');
    append_string(&s2, 'd');
    append_string(&s2, '\0');

    printf("Before reversal:\n");
    printf("s1 = %s\n", s1.data);
    printf("s2 = %s\n", s2.data);

    reverse_string(&s1);
    reverse_string(&s2);

    printf("After reversal:\n");
    printf("s1 = %s\n", s1.data);
    printf("s2 = %s\n", s2.data);

    return 0;
}