//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100

void print_reverse(char *str);
void print_every_other(char *str);
void print_middle(char *str);
void print_frame(char *str);
void print_zigzag(char *str);

int main() {
    char str[MAX_STR_LEN];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Original string: %s\n", str);
    print_reverse(str);
    print_every_other(str);
    print_middle(str);
    print_frame(str);
    print_zigzag(str);

    return 0;
}

void print_reverse(char *str) {
    int len = strlen(str);
    printf("Reversed string: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void print_every_other(char *str) {
    printf("Every other character: ");
    for (int i = 0; i < strlen(str); i += 2) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void print_middle(char *str) {
    int len = strlen(str);
    printf("Middle character: ");
    if (len % 2 == 0) {
        printf("%c%c", str[len / 2 - 1], str[len / 2]);
    } else {
        printf("%c", str[len / 2]);
    }
    printf("\n");
}

void print_frame(char *str) {
    int len = strlen(str);
    printf("Framed string:\n");
    for (int i = 0; i < len + 2; i++) {
        printf("*");
    }
    printf("\n* %s *\n", str);
    for (int i = 0; i < len + 2; i++) {
        printf("*");
    }
    printf("\n");
}

void print_zigzag(char *str) {
    int len = strlen(str);
    printf("Zigzag string:\n");
    for (int i = 0; i < len; i++) {
        printf("%c", str[i]);
        if (i % 2 == 0) {
            printf("\n");
        }
    }
}