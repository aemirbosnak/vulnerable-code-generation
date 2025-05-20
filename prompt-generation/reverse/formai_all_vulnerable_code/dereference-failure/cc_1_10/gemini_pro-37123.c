//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using LZW algorithm
char *compress(char *str) {
    int dictSize = 256;
    char *dict[dictSize];
    for (int i = 0; i < dictSize; i++) {
        dict[i] = malloc(2);
        dict[i][0] = i;
        dict[i][1] = '\0';
    }

    int code = dictSize;
    char *result = malloc(strlen(str) + 1);
    result[0] = '\0';

    char *w = malloc(strlen(str) + 1);
    w[0] = '\0';

    for (int i = 0; i < strlen(str); i++) {
        char *wc = malloc(strlen(w) + 2);
        wc[0] = '\0';
        strcat(wc, w);
        strcat(wc, &str[i]);

        int j = 0;
        while (j < code && strcmp(dict[j], wc) != 0) {
            j++;
        }

        if (j < code) {
            char *codeStr = malloc(10);
            sprintf(codeStr, "%d", j);
            strcat(result, codeStr);
        } else {
            char *codeStr = malloc(10);
            sprintf(codeStr, "%d", code);
            strcat(result, codeStr);
            dict[code] = malloc(strlen(wc) + 1);
            strcpy(dict[code], wc);
            code++;
        }

        strcpy(w, wc);
    }

    for (int i = 0; i < dictSize; i++) {
        free(dict[i]);
    }
    free(w);

    return result;
}

// Function to decompress a string using LZW algorithm
char *decompress(char *str) {
    int dictSize = 256;
    char *dict[dictSize];
    for (int i = 0; i < dictSize; i++) {
        dict[i] = malloc(2);
        dict[i][0] = i;
        dict[i][1] = '\0';
    }

    int code = dictSize;
    char *result = malloc(strlen(str) + 1);
    result[0] = '\0';

    char *w = malloc(strlen(str) + 1);
    w[0] = '\0';

    for (int i = 0; i < strlen(str); i++) {
        int codeInt = atoi(&str[i]);
        char *codeStr = malloc(10);
        sprintf(codeStr, "%d", codeInt);

        int j = 0;
        while (j < code && strcmp(dict[j], codeStr) != 0) {
            j++;
        }

        if (j < code) {
            strcat(result, dict[j]);
            char *wc = malloc(strlen(w) + strlen(dict[j]) + 1);
            wc[0] = '\0';
            strcat(wc, w);
            strcat(wc, dict[j]);
            dict[code] = malloc(strlen(wc) + 1);
            strcpy(dict[code], wc);
            code++;
        } else {
            char *wc = malloc(strlen(w) + 2);
            wc[0] = '\0';
            strcat(wc, w);
            strcat(wc, w);
            dict[code] = malloc(strlen(wc) + 1);
            strcpy(dict[code], wc);
            code++;
        }

        strcpy(w, dict[codeInt]);
    }

    for (int i = 0; i < dictSize; i++) {
        free(dict[i]);
    }
    free(w);

    return result;
}

int main() {
    char *str = "TOBEORNOTTOBEORTOBEORNOT";

    char *compressedStr = compress(str);
    printf("Compressed string: %s\n", compressedStr);

    char *decompressedStr = decompress(compressedStr);
    printf("Decompressed string: %s\n", decompressedStr);

    return 0;
}