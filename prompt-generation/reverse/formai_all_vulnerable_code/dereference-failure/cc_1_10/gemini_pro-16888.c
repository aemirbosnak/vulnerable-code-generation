//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    char *buf1, *buf2;
    size_t len1, len2;
    int i;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    buf1 = strdup(argv[1]);
    if (buf1 == NULL) {
        perror("strdup");
        return EXIT_FAILURE;
    }

    buf2 = strdup(argv[2]);
    if (buf2 == NULL) {
        perror("strdup");
        free(buf1);
        return EXIT_FAILURE;
    }

    len1 = strlen(buf1);
    len2 = strlen(buf2);

    if (len1 > BUFSIZE || len2 > BUFSIZE) {
        fprintf(stderr, "Strings too long\n");
        free(buf1);
        free(buf2);
        return EXIT_FAILURE;
    }

    /* Concatenate the strings */
    for (i = 0; i < len2; i++) {
        buf1[len1 + i] = buf2[i];
    }
    buf1[len1 + len2] = '\0';

    printf("Concatenated string: %s\n", buf1);

    /* Reverse the string */
    for (i = 0; i < len1 + len2 / 2; i++) {
        char tmp = buf1[i];
        buf1[i] = buf1[len1 + len2 - i - 1];
        buf1[len1 + len2 - i - 1] = tmp;
    }

    printf("Reversed string: %s\n", buf1);

    free(buf1);
    free(buf2);

    return EXIT_SUCCESS;
}