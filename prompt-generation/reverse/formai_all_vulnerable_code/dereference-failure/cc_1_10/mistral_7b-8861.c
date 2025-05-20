//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Palindrome {
    int len;
    char *str;
} Palindrome;

Palindrome *create_palindrome(char *str);
int is_palindrome(Palindrome *p);
void destroy_palindrome(Palindrome *p);

int main() {
    char input[101];
    Palindrome *p;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    p = create_palindrome(input);

    if (is_palindrome(p))
        printf("The given string is a palindrome.\n");
    else
        printf("The given string is not a palindrome.\n");

    destroy_palindrome(p);

    return 0;
}

Palindrome *create_palindrome(char *str) {
    Palindrome *p = (Palindrome *)malloc(sizeof(Palindrome));

    p->len = strlen(str);
    p->str = (char *)malloc((p->len + 1) * sizeof(char));
    strcpy(p->str, str);

    return p;
}

void destroy_palindrome(Palindrome *p) {
    free(p->str);
    free(p);
}

int is_palindrome(Palindrome *p) {
    int i, flag = 1;

    for (i = 0; i < p->len / 2; i++) {
        if (tolower(p->str[i]) != tolower(p->str[p->len - i - 1])) {
            flag = 0;
            break;
        }
    }

    return flag;
}