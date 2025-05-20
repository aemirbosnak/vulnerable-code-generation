//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

typedef struct {
    char *str;
    int len;
} string_t;

void init_string(string_t *s) {
    s->str = (char *)malloc(MAX_LENGTH);
    s->len = 0;
    s->str[0] = '\0';
}

void append_string(string_t *s, char ch) {
    if (s->len >= MAX_LENGTH - 1) {
        printf("Error: String is full.\n");
        return;
    }
    s->str[s->len++] = ch;
    s->str[s->len] = '\0';
}

void print_string(string_t s) {
    printf("%s", s.str);
}

int main() {
    string_t s1, s2;
    init_string(&s1);
    init_string(&s2);

    append_string(&s1, 'H');
    append_string(&s1, 'e');
    append_string(&s1, 'l');
    append_string(&s1, 'l');
    append_string(&s1, 'o');
    printf("s1: ");
    print_string(s1);

    append_string(&s2, 'W');
    append_string(&s2, 'o');
    append_string(&s2, 'r');
    append_string(&s2, 'l');
    append_string(&s2, 'd');
    printf("\ns2: ");
    print_string(s2);

    string_t s3;
    init_string(&s3);

    strcat(s3.str, s1.str);
    strcat(s3.str, s2.str);
    printf("\ns3: ");
    print_string(s3);

    return 0;
}