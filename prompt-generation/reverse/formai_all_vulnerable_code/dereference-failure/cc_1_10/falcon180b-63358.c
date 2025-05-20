//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *str;
    int size;
} String;

void init_string(String *s) {
    s->str = (char *)malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
    s->str[0] = '\0';
}

void append_string(String *s, char c) {
    s->str = (char *)realloc(s->str, s->size + 2);
    s->str[s->size] = c;
    s->str[s->size + 1] = '\0';
    s->size++;
}

void print_string(String s) {
    printf("%s\n", s.str);
}

int main() {
    String s1, s2;

    init_string(&s1);
    init_string(&s2);

    append_string(&s1, 'a');
    append_string(&s1, 'b');
    append_string(&s1, 'c');

    append_string(&s2, 'd');
    append_string(&s2, 'e');
    append_string(&s2, 'f');

    String result = {0};

    int carry = 0;
    int i = s1.size - 1;
    int j = s2.size - 1;
    int k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) {
            sum += s1.str[i] - '0';
            i--;
        }

        if (j >= 0) {
            sum += s2.str[j] - '0';
            j--;
        }

        result.str[k] = (char)(sum % 10) + '0';
        carry = sum / 10;
        k++;
    }

    result.str[k] = '\0';
    result.size = k;

    print_string(result);

    return 0;
}