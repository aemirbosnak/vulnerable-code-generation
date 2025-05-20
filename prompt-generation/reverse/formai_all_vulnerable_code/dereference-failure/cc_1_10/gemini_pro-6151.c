//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main(int argc, char *argv[]) {
    char *str1, *str2;
    int len1, len2;

    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    len1 = strlen(argv[1]);
    len2 = strlen(argv[2]);

    if (len1 != len2) {
        printf("Strings must be of equal length\n");
        return EXIT_FAILURE;
    }

    str1 = malloc(len1 + 1);
    str2 = malloc(len2 + 1);

    if (str1 == NULL || str2 == NULL) {
        printf("Malloc failed\n");
        return EXIT_FAILURE;
    }

    strcpy(str1, argv[1]);
    strcpy(str2, argv[2]);

    int i, j;
    char temp;

    for (i = 0, j = len1 - 1; i < len1 / 2; i++, j--) {
        temp = str1[i];
        str1[i] = str2[i];
        str2[i] = temp;

        temp = str1[j];
        str1[j] = str2[j];
        str2[j] = temp;
    }

    printf("Swapped strings: %s, %s\n", str1, str2);

    free(str1);
    free(str2);

    return EXIT_SUCCESS;
}