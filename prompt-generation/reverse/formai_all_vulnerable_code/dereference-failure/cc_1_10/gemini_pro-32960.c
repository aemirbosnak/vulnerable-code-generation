//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
    int len;
} CompressedString;

CompressedString compress(char *str) {
    CompressedString cs;
    cs.str = malloc(strlen(str) + 1);
    strcpy(cs.str, str);
    cs.len = strlen(str);

    int i, j;
    for (i = 0; i < cs.len; i++) {
        for (j = i + 1; j < cs.len; j++) {
            if (cs.str[i] == cs.str[j]) {
                cs.str[j] = 0;
                cs.len--;
            }
        }
    }

    return cs;
}

void decompress(CompressedString cs) {
    char *str = malloc(cs.len + 1);
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < cs.len; i++) {
        if (cs.str[i] != 0) {
            str[j++] = cs.str[i];
        } else {
            str[j++] = str[k++];
        }
    }
    str[j] = 0;

    printf("%s\n", str);
}

int main() {
    char *str = "abracadabra";
    CompressedString cs = compress(str);
    decompress(cs);

    return 0;
}