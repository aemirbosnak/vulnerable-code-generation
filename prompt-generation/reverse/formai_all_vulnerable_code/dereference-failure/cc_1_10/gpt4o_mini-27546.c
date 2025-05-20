//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_CODES 20

typedef struct {
    char code[4];
    int count;
} ResponseCode;

void printBanner() {
    printf("==============================================\n");
    printf("          Welcome to Log Analyzer!          \n");
    printf("==============================================\n");
}

void addCode(ResponseCode *codes, int *size, const char *code) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(codes[i].code, code) == 0) {
            codes[i].count++;
            return;
        }
    }
    strcpy(codes[*size].code, code);
    codes[*size].count = 1;
    (*size)++;
}

void printResults(ResponseCode *codes, int size) {
    printf("\nResponse Code Analysis:\n");
    printf("%-10s %-10s\n", "Code", "Count");
    printf("----------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-10s %-10d\n", codes[i].code, codes[i].count);
    }
    printf("==============================================\n");
}

void analyzeLogFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    ResponseCode *codes = malloc(MAX_CODES * sizeof(ResponseCode));
    if (!codes) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    int size = 0;

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " ");
        
        while (token != NULL) {
            // Look for the HTTP response codes, assuming they are 3-digit numeric strings
            if (strlen(token) == 3 && isdigit(token[0]) && isdigit(token[1]) && isdigit(token[2])) {
                addCode(codes, &size, token);
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);
    printResults(codes, size);
    free(codes);
}

int main(int argc, char *argv[]) {
    printBanner();
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyzeLogFile(argv[1]);
    printf("Thank you for using Log Analyzer!\n");
    return EXIT_SUCCESS;
}