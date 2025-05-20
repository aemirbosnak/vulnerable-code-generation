//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    int is_palindrome;
    char str[MAX_SIZE];
} Palindrome;

void str_reverse(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int is_palindrome(char *str) {
    int len = strlen(str);
    if (len <= 1)
        return 1;

    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    Palindrome pal1 = {0};
    Palindrome pal2 = {0};

    strcpy(pal1.str, argv[1]);
    strcpy(pal2.str, argv[2]);

    printf("Checking if '%s' is a palindrome... ", argv[1]);
    if (is_palindrome(pal1.str))
        printf("Yes\n");
    else
        printf("No\n");

    str_reverse(pal2.str, 0, strlen(pal2.str) - 1);

    printf("Checking if reversed '%s' is equal to '%s'... ", pal2.str, argv[2]);
    if (strcmp(pal1.str, pal2.str) == 0)
        printf("Yes\n");
    else
        printf("No\n");

    if (is_palindrome(pal2.str)) {
        printf("'%s' is a palindrome\n", argv[2]);
    } else {
        printf("'%s' is not a palindrome\n", argv[2]);
    }

    return 0;
}