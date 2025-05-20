//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char *reverse(char *str) {
    int len = strlen(str);
    char *rev = malloc(len + 1);
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        rev[i] = tolower(str[j]);
        rev[j] = tolower(str[i]);
    }

    rev[i] = '\0';

    return rev;
}

int isPalindrome(char *str) {
    int len = strlen(str);
    char *rev = reverse(str);

    if (strcmp(str, rev) == 0)
        return 1;

    free(rev);

    return 0;
}

void generatePalindromes(char *str, int start, int end, FILE *fp) {
    if (start > end) {
        fprintf(fp, "%s\n", str);
        return;
    }

    for (int i = start; i <= end; i++) {
        str[start] = i + 'a';
        generatePalindromes(str, start + 1, end, fp);
    }
}

int main() {
    char str[MAX];
    FILE *fp;

    printf("Enter a string: ");
    scanf("%s", str);

    fp = fopen("palindromes.txt", "w");

    if (isPalindrome(str))
        fprintf(fp, "%s is a palindrome.\n", str);
    else
        generatePalindromes(str, 0, strlen(str) - 1, fp);

    fclose(fp);

    return 0;
}