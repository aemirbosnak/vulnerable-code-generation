//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int indent;
    int length;
    char *data;
} HTMLBuffer;

HTMLBuffer *newHTMLBuffer(int initialSize) {
    HTMLBuffer *buffer = malloc(sizeof(HTMLBuffer));
    buffer->indent = 0;
    buffer->length = initialSize;
    buffer->data = malloc(buffer->length);
    return buffer;
}

void freeHTMLBuffer(HTMLBuffer *buffer) {
    free(buffer->data);
    free(buffer);
}

void HTMLBuffer_append(HTMLBuffer *buffer, char *data) {
    int requiredLength = buffer->length + strlen(data);
    if (requiredLength > buffer->length) {
        buffer->length = requiredLength * 2;
        buffer->data = realloc(buffer->data, buffer->length);
    }
    strcpy(buffer->data + buffer->length - strlen(data), data);
}

void HTMLBuffer_appendWithIndent(HTMLBuffer *buffer, char *data) {
    int requiredLength = buffer->length + strlen(data) + buffer->indent;
    if (requiredLength > buffer->length) {
        buffer->length = requiredLength * 2;
        buffer->data = realloc(buffer->data, buffer->length);
    }
    int i;
    for (i = 0; i < buffer->indent; i++) {
        buffer->data[buffer->length - strlen(data) - buffer->indent + i] = ' ';
    }
    strcpy(buffer->data + buffer->length - strlen(data), data);
}

void HTMLBeautifier_beautify(char *input, char *output) {
    HTMLBuffer *buffer = newHTMLBuffer(512);
    int inTag = 0;
    int inComment = 0;
    int inString = 0;
    int i;
    char c;
    for (i = 0; i < strlen(input); i++) {
        c = input[i];
        if (inComment) {
            // If we're in a comment, we just need to find the closing tag
            if (c == '-' && input[i + 1] == '-') {
                HTMLBuffer_append(buffer, "<!-- ");
                i += 2;
            } else if (c == '>' && input[i - 1] == '-') {
                HTMLBuffer_append(buffer, " -->");
                inComment = 0;
            }
        } else if (inString) {
            // If we're in a string, we just need to find the closing quote
            if (c == '\"') {
                inString = 0;
            }
        } else if (c == '<') {
            // If we encounter a less than sign, we're entering a tag
            inTag = 1;
            buffer->indent++;
            HTMLBuffer_appendWithIndent(buffer, "<");
        } else if (c == '>' && inTag) {
            // If we encounter a greater than sign and we're in a tag, we're exiting the tag
            inTag = 0;
            buffer->indent--;
            HTMLBuffer_append(buffer, ">");
        } else if (c == '\"') {
            // If we encounter a double quote, we're entering a string
            inString = 1;
            HTMLBuffer_append(buffer, "\"");
        } else if (c == '-' && input[i + 1] == '-') {
            // If we encounter two hyphens, we're entering a comment
            inComment = 1;
        } else if (c == '\n') {
            // If we encounter a newline, we're starting a new line
            HTMLBuffer_append(buffer, "\n");
        } else if (inTag) {
            // If we're in a tag, we just need to append the character
            HTMLBuffer_appendWithIndent(buffer, &c);
        } else {
            // If we're not in a tag, we just need to append the character
            HTMLBuffer_append(buffer, &c);
        }
    }
    strcpy(output, buffer->data);
    freeHTMLBuffer(buffer);
}

int main() {
    char *input = "<html><head><title>Hello World</title></head><body><h1>Hello World</h1></body></html>";
    char output[512];
    HTMLBeautifier_beautify(input, output);
    printf("%s", output);
    return 0;
}