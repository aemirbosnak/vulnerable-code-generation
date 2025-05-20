//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef int bool;
#define true 1
#define false 0

typedef struct {
    char *text;
    int capacity;
    int length;
} StringBuffer;

// Function prototypes
StringBuffer* createStringBuffer(int capacity);
void appendToBuffer(StringBuffer *buffer, const char *text);
void freeStringBuffer(StringBuffer *buffer);
void beautifyHTML(const char *inputFilePath, const char *outputFilePath);
bool isWhitespace(char c);
bool isOpeningTag(const char *line);
bool isClosingTag(const char *line);
void indentLevel(int level);
void processLine(const char *line, StringBuffer *output, int *level);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input HTML file> <output HTML file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautifyHTML(argv[1], argv[2]);
    return EXIT_SUCCESS;
}

StringBuffer* createStringBuffer(int capacity) {
    StringBuffer *buffer = malloc(sizeof(StringBuffer));
    buffer->text = malloc(capacity * sizeof(char));
    buffer->capacity = capacity;
    buffer->length = 0;
    return buffer;
}

void appendToBuffer(StringBuffer *buffer, const char *text) {
    int textLength = strlen(text);
    if (buffer->length + textLength >= buffer->capacity) {
        buffer->capacity *= 2;
        buffer->text = realloc(buffer->text, buffer->capacity * sizeof(char));
    }
    strcpy(buffer->text + buffer->length, text);
    buffer->length += textLength;
}

void freeStringBuffer(StringBuffer *buffer) {
    free(buffer->text);
    free(buffer);
}

void beautifyHTML(const char *inputFilePath, const char *outputFilePath) {
    FILE *inputFile = fopen(inputFilePath, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: could not open input file %s\n", inputFilePath);
        return;
    }

    FILE *outputFile = fopen(outputFilePath, "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: could not open output file %s\n", outputFilePath);
        fclose(inputFile);
        return;
    }

    char line[MAX_LINE_LENGTH];
    StringBuffer *output = createStringBuffer(4096);

    int level = 0;

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        processLine(line, output, &level);
    }

    fprintf(outputFile, "%s", output->text);
    fclose(inputFile);
    fclose(outputFile);
    freeStringBuffer(output);
}

bool isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

bool isOpeningTag(const char *line) {
    return strchr(line, '<') != NULL && strchr(line, '/') == NULL;
}

bool isClosingTag(const char *line) {
    return strchr(line, '/') != NULL && strchr(line, '<') != NULL;
}

void indentLevel(int level) {
    for (int i = 0; i < level; i++) {
        printf("    "); // four spaces per level
    }
}

void processLine(const char *line, StringBuffer *output, int *level) {
    if (isOpeningTag(line)) {
        appendToBuffer(output, line);
        (*level)++;
    } else if (isClosingTag(line)) {
        (*level)--;
        indentLevel(*level);
        appendToBuffer(output, line);
    } else {
        indentLevel(*level);
        appendToBuffer(output, line);
    }
}