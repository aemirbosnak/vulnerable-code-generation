//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 32
#define MAX_VARS 128

typedef struct {
    char name[MAX_NAME_LEN];
    int type;
    int size;
} Metadata;

Metadata vars[MAX_VARS];
int num_vars = 0;

void extract_metadata(const char *code, int len) {
    const char *ptr = code;
    char name[MAX_NAME_LEN];
    int i;

    while (len > 0) {
        while (*ptr && isspace(*ptr)) ptr++;
        if (*ptr == '\0') break;

        i = 0;
        while (*ptr && !isspace(*ptr) && i < MAX_NAME_LEN - 1) {
            name[i++] = *ptr++;
        }
        name[i] = '\0';

        if (strcmp(name, "int") == 0 || strcmp(name, "float") == 0) {
            vars[num_vars].type = *ptr++;
            vars[num_vars].size = (strcmp(name, "int") == 0) ? sizeof(int) : sizeof(float);
            num_vars++;
        }

        len -= i + 1;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <code>\n", argv[0]);
        return 1;
    }

    extract_metadata(argv[1], strlen(argv[1]));

    printf("Metadata:\n");
    for (int i = 0; i < num_vars; i++) {
        printf("%s: %d bytes\n", vars[i].name, vars[i].size);
    }

    return 0;
}