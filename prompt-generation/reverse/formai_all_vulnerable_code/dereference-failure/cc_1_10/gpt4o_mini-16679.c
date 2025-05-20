//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4
#define MAX_INDENT_LEVEL 10

typedef struct {
    char **lines;
    int lineCount;
    int allocatedLines;
} CodeBlock;

void initializeCodeBlock(CodeBlock *codeBlock) {
    codeBlock->lineCount = 0;
    codeBlock->allocatedLines = 10;
    codeBlock->lines = (char **)malloc(codeBlock->allocatedLines * sizeof(char *));
}

void freeCodeBlock(CodeBlock *codeBlock) {
    for (int i = 0; i < codeBlock->lineCount; ++i) {
        free(codeBlock->lines[i]);
    }
    free(codeBlock->lines);
}

void addLine(CodeBlock *codeBlock, const char *line) {
    if (codeBlock->lineCount >= codeBlock->allocatedLines) {
        codeBlock->allocatedLines *= 2;
        codeBlock->lines = (char **)realloc(codeBlock->lines, codeBlock->allocatedLines * sizeof(char *));
    }
    codeBlock->lines[codeBlock->lineCount] = (char *)malloc((strlen(line) + 1) * sizeof(char));
    strcpy(codeBlock->lines[codeBlock->lineCount], line);
    codeBlock->lineCount++;
}

bool isOpeningBrace(char c) {
    return c == '{';
}

bool isClosingBrace(char c) {
    return c == '}';
}

void beautifyCodeBlock(CodeBlock *codeBlock) {
    int indentLevel = 0;
    CodeBlock result;
    initializeCodeBlock(&result);
    
    for (int i = 0; i < codeBlock->lineCount; ++i) {
        char *line = codeBlock->lines[i];
        char trimmedLine[MAX_LINE_LENGTH];
        int trimmedIndex = 0;

        // Trim whitespace at the beginning of the line
        while (*line && (*line == ' ' || *line == '\t')) {
            line++;
        }
        
        // Check for opening brace
        if (isOpeningBrace(line[0])) {
            // Handle previous line indent before brace
            addLine(&result, line);
            indentLevel++;
            continue;
        }
        
        // Handle closing brace
        if (isClosingBrace(line[0])) {
            indentLevel--;
        }
        
        // Add indentation
        for (int j = 0; j < indentLevel * INDENT_SIZE; j++) {
            trimmedLine[trimmedIndex++] = ' ';
        }
        
        // Copy current line, maintaining trailing whitespaces
        while (*line) {
            trimmedLine[trimmedIndex++] = *line++;
        }
        trimmedLine[trimmedIndex] = '\0';
        
        if (indentLevel < MAX_INDENT_LEVEL) {
            addLine(&result, trimmedLine);
        } else {
            printf("Indentation level exceeds the maximum limit at line %d\n", i + 1);
        }
        
        // Your logic to add opening brace for the next loop iteration
        if (isOpeningBrace(trimmedLine[0])) {
            indentLevel++;
        }
    }
    
    // Print beautified code
    printf("Beautified Code:\n");
    for (int i = 0; i < result.lineCount; i++) {
        printf("%s\n", result.lines[i]);
    }
    
    freeCodeBlock(&result);
}

void readCodeFromFile(const char *filename, CodeBlock *codeBlock) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        addLine(codeBlock, line);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <code_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CodeBlock codeBlock;
    initializeCodeBlock(&codeBlock);
    
    readCodeFromFile(argv[1], &codeBlock);
    beautifyCodeBlock(&codeBlock);
    
    freeCodeBlock(&codeBlock);
    return 0;
}