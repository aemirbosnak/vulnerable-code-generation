//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_SIZE 4096
#define MAX_CODE_ENTRIES 4096

typedef struct {
    int code;
    char *string;
} CodeEntry;

typedef struct {
    int code;
    int next;
} CodeTable;

CodeEntry codeTable[MAX_CODE_ENTRIES];
int codeTableSize = 0;

CodeTable codeTable2[MAX_CODE_SIZE];
int codeTable2Size = 0;

int addCode(char *string) {
    int i;
    for (i = 0; i < codeTableSize; i++) {
        if (strcmp(string, codeTable[i].string) == 0) {
            return i;
        }
    }
    if (codeTableSize >= MAX_CODE_ENTRIES) {
        printf("ERROR: Code table is full!\n");
        exit(1);
    }
    codeTable[codeTableSize].code = codeTableSize;
    codeTable[codeTableSize].string = strdup(string);
    codeTableSize++;
    return codeTableSize - 1;
}

int addCode2(int code) {
    if (codeTable2Size >= MAX_CODE_SIZE) {
        printf("ERROR: Code table 2 is full!\n");
        exit(1);
    }
    codeTable2[codeTable2Size].code = code;
    codeTable2[codeTable2Size].next = -1;
    codeTable2Size++;
    return codeTable2Size - 1;
}

void buildCodeTable2() {
    int i, j, k;
    for (i = 0; i < codeTableSize; i++) {
        for (j = 0; j < strlen(codeTable[i].string); j++) {
            k = (codeTable[i].code << (j * 8)) | (codeTable[i].string[j] & 0xFF);
            addCode2(k);
        }
    }
}

int encode(char *string) {
    int i, j, k;
    int code = 0;
    for (i = 0; i < strlen(string); i++) {
        k = codeTable[string[i]].code;
        if (k == -1) {
            printf("ERROR: Invalid character '%c' in input!\n", string[i]);
            exit(1);
        }
        code = (code << 8) | k;
    }
    return code;
}

char *decode(int code) {
    int i, j, k;
    char *string = malloc(MAX_CODE_SIZE);
    for (i = 0; i < strlen(string); i++) {
        k = codeTable2[code & 0xFF].code;
        if (k == -1) {
            printf("ERROR: Invalid code in input!\n");
            exit(1);
        }
        string[i] = k;
        code >>= 8;
    }
    return string;
}

int main() {
    int i, j, k;
    char input[MAX_CODE_SIZE];
    char *output;

    printf("Enter a string to compress:\n");
    fgets(input, MAX_CODE_SIZE, stdin);

    addCode(input);

    buildCodeTable2();

    printf("Compressed string:\n");
    for (i = 0; i < strlen(input); i++) {
        k = encode(input + i);
        output = decode(k);
        printf("%s ", output);
    }

    return 0;
}