//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_LEN 100

int main(int argc, char *argv[]) {
    char str[MAX_LEN];
    char *src, *dst;
    char delimiter[] = ", ";
    int len, i;

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    strcpy(str, argv[1]);

    printf("Original String: %s\n", str);

    // Surprise 1: Remove all whitespaces
    for (src = str, i = 0; *src; src++, i++) {
        if (isspace(*src))
            continue;
        str[i] = *src;
    }
    str[i] = '\0';

    // Surprise 2: Randomly shuffle characters
    srand(time(NULL));
    for (i = 0; i < strlen(str); i++) {
        int j = rand() % strlen(str);
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Surprise 3: Reverse the string
    len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    // Surprise 4: Split the string using a delimiter
    src = strtok(str, delimiter);
    dst = str;
    while (src != NULL) {
        strcat(dst, src);
        src = strtok(NULL, delimiter);
        if (src != NULL)
            strcat(dst, delimiter);
    }

    printf("Surprised String: %s\n", str);
    printf("Reconstructed String: %s\n", dst);

    return 0;
}