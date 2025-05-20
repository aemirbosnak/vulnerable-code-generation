//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SWAP(type, x, y) do { type temp = (x); (x) = (y); (y) = temp; } while (0)

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[100];
    char text[10000];
    int len;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    fgets(text, sizeof(text), fp);
    len = strlen(text);

    // Replace all lowercase vowels with 'x'
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i]) && strchr("aeiouAEIOU", text[i])) {
            text[i] = 'x';
        }
    }

    // Capitalize the first letter
    if (len > 0 && isalpha(text[0])) {
        text[0] = toupper(text[0]);
    }

    // Reverse the string
    for (int i = 0, j = len - 1; i < len / 2; i++, j--) {
        SWAP(char, text[i], text[j]);
    }

    printf("Input: %s\n", text);

    fclose(fp);
    return 0;
}