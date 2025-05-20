//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

void reverse_words(char *str) {
    char *p, *q;
    int i, j;

    p = str;
    q = str + strlen(str) - 1;

    while (p < q) {
        i = 0;
        j = strlen(p) - 1;

        while (i < j) {
            char temp = p[i];
            p[i] = q[j];
            q[j] = temp;
            i++;
            j--;
        }

        p++;
        q--;
    }
}

int main() {
    char str[MAX_LENGTH];
    int i;

    printf("Enter a sentence: ");
    fgets(str, MAX_LENGTH, stdin);

    reverse_words(str);

    printf("Reversed sentence: %s\n", str);

    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            printf("%c", tolower(str[i]));
        } else {
            printf(" %c", str[i]);
        }
    }

    return 0;
}