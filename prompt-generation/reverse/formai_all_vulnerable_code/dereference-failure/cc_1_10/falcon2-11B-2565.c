//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int base;
    char *table;
    char *message;
} Message;

void shift_right(Message *m, int n) {
    int i;
    for (i = 0; i < m->base; i++) {
        char c = m->message[i];
        if (c >= '0' && c <= '9') {
            c = c + 'A' - '0';
        } else if (c >= 'a' && c <= 'f') {
            c = c + 'A' - 'a';
        }
        m->message[i] = c;
    }
    m->message[i] = '\0';
}

void shift_left(Message *m, int n) {
    int i;
    for (i = 0; i < m->base; i++) {
        char c = m->message[i];
        if (c >= '0' && c <= '9') {
            c = c - 'A' + '0';
        } else if (c >= 'a' && c <= 'f') {
            c = c - 'A' + 'a';
        }
        m->message[i] = c;
    }
    m->message[i] = '\0';
}

int main() {
    Message m;
    m.base = 16;
    m.table = "0123456789abcdef";
    m.message = "hello";

    printf("Before conversion:\n%s\n\n", m.message);

    shift_right(&m, 2);
    printf("Shifted right:\n%s\n\n", m.message);

    shift_left(&m, 2);
    printf("Shifted left:\n%s\n\n", m.message);

    return 0;
}