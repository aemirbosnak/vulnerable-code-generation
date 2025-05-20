//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 100

typedef struct {
    char *code;
    int len;
} code_t;

code_t codes[256];
int code_count = 0;

void get_codes() {
    for (int i = 0; i < 256; i++) {
        codes[i].code = malloc(MAX_CODE_LEN);
        codes[i].len = 0;
    }

    FILE *fp = fopen("codes.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening codes file\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        char *code = strtok(line, " ");
        char *symbol = strtok(NULL, " ");

        int code_len = strlen(code);
        if (code_len > MAX_CODE_LEN) {
            fprintf(stderr, "Error: Code length exceeds maximum\n");
            exit(1);
        }

        strcpy(codes[symbol[0]].code, code);
        codes[symbol[0]].len = code_len;
        code_count++;
    }

    fclose(fp);
}

void compress(char *input_file, char *output_file) {
    FILE *ifp = fopen(input_file, "r");
    if (ifp == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(1);
    }

    FILE *ofp = fopen(output_file, "w");
    if (ofp == NULL) {
        fprintf(stderr, "Error opening output file\n");
        exit(1);
    }

    int c;
    while ((c = fgetc(ifp)) != EOF) {
        fwrite(codes[c].code, codes[c].len, 1, ofp);
    }

    fclose(ifp);
    fclose(ofp);
}

void decompress(char *input_file, char *output_file) {
    FILE *ifp = fopen(input_file, "r");
    if (ifp == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(1);
    }

    FILE *ofp = fopen(output_file, "w");
    if (ofp == NULL) {
        fprintf(stderr, "Error opening output file\n");
        exit(1);
    }

    char code[MAX_CODE_LEN];
    int code_len = 0;
    while ((code_len = fread(code, 1, MAX_CODE_LEN, ifp)) > 0) {
        for (int i = 0; i < 256; i++) {
            if (strcmp(code, codes[i].code) == 0) {
                fputc(i, ofp);
                break;
            }
        }
    }

    fclose(ifp);
    fclose(ofp);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <get_codes | compress | decompress> <input_file> <output_file> [codes_file]\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "get_codes") == 0) {
        get_codes();
    } else if (strcmp(argv[1], "compress") == 0) {
        compress(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decompress") == 0) {
        decompress(argv[2], argv[3]);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[1]);
        exit(1);
    }

    return 0;
}