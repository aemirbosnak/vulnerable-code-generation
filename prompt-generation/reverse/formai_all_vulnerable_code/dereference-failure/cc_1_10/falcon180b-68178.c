//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char *string;
    int length;
} String;

void init_string(String *s, char *init_str) {
    s->string = malloc(MAX_LENGTH * sizeof(char));
    s->length = strlen(init_str);
    strcpy(s->string, init_str);
}

void print_string(String *s) {
    printf("String: %s\n", s->string);
    printf("Length: %d\n", s->length);
}

void concatenate_strings(String *s1, String *s2) {
    char *new_string = malloc((s1->length + s2->length) * sizeof(char));
    strcpy(new_string, s1->string);
    strcat(new_string, s2->string);
    s1->string = new_string;
    s1->length += s2->length;
}

void reverse_string(String *s) {
    char *reverse_str = malloc((s->length + 1) * sizeof(char));
    int i, j;
    for (i = s->length - 1, j = 0; i >= 0; i--, j++) {
        reverse_str[j] = s->string[i];
    }
    reverse_str[j] = '\0';
    s->string = reverse_str;
}

int main() {
    String s1, s2, s3;
    init_string(&s1, "Hello, world!");
    init_string(&s2, "How are you?");
    printf("Before concatenation:\n");
    print_string(&s1);
    print_string(&s2);
    concatenate_strings(&s1, &s2);
    printf("After concatenation:\n");
    print_string(&s1);
    reverse_string(&s1);
    printf("After reversing:\n");
    print_string(&s1);
    return 0;
}