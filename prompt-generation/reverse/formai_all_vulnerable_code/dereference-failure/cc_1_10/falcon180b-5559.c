//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

typedef struct {
    char *string;
    int length;
} String;

void init(String *s) {
    s->string = (char *)malloc(MAX_LENGTH * sizeof(char));
    s->length = 0;
    s->string[0] = '\0';
}

void append(String *s, char c) {
    if (s->length >= MAX_LENGTH) {
        printf("Error: String is too long.\n");
        return;
    }
    s->string[s->length++] = c;
    s->string[s->length] = '\0';
}

void print(String s) {
    printf("%s\n", s.string);
}

int main() {
    String s1, s2;
    init(&s1);
    init(&s2);

    append(&s1, 'H');
    append(&s1, 'e');
    append(&s1, 'l');
    append(&s1, 'l');
    append(&s1, 'o');

    append(&s2, 'W');
    append(&s2, 'o');
    append(&s2, 'r');
    append(&s2, 'l');
    append(&s2, 'd');

    String s3;
    init(&s3);

    int length = strlen(s1.string) + strlen(s2.string);
    s3.string = (char *)malloc(length * sizeof(char));
    s3.length = 0;

    for (int i = 0; i < strlen(s1.string); i++) {
        append(&s3, s1.string[i]);
    }

    for (int i = 0; i < strlen(s2.string); i++) {
        append(&s3, s2.string[i]);
    }

    print(s3);

    free(s1.string);
    free(s2.string);
    free(s3.string);

    return 0;
}