//Falcon-180B DATASET v1.0 Category: Recursive ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *str;
    int len;
} String;

void init_string(String *s) {
    s->str = (char *) malloc(MAX_SIZE * sizeof(char));
    s->len = 0;
}

void free_string(String *s) {
    free(s->str);
}

void push_char(String *s, char c) {
    if (s->len >= MAX_SIZE) {
        fprintf(stderr, "Error: string is full!\n");
        exit(1);
    }
    s->str[s->len++] = c;
}

void pop_char(String *s) {
    if (s->len <= 0) {
        fprintf(stderr, "Error: string is empty!\n");
        exit(1);
    }
    s->len--;
}

void print_string(String *s) {
    printf("%s", s->str);
}

void reverse_string(String *s) {
    int i, j;
    char c;
    for (i = 0, j = s->len - 1; i < j; i++, j--) {
        c = s->str[i];
        s->str[i] = s->str[j];
        s->str[j] = c;
    }
}

int main() {
    String s;
    init_string(&s);

    int choice, len;
    char input[MAX_SIZE];

    do {
        printf("Enter your choice:\n");
        printf("1. Push a character\n");
        printf("2. Pop a character\n");
        printf("3. Print the string\n");
        printf("4. Reverse the string\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a character: ");
            scanf(" %c", &input[0]);
            push_char(&s, input[0]);
            break;
        case 2:
            pop_char(&s);
            break;
        case 3:
            print_string(&s);
            break;
        case 4:
            reverse_string(&s);
            break;
        case 5:
            free_string(&s);
            exit(0);
        default:
            fprintf(stderr, "Error: invalid choice!\n");
        }

        printf("\n");
    } while (1);

    return 0;
}