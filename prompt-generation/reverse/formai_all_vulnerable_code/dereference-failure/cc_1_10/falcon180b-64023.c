//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter some text:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Remove leading/trailing whitespace
    char *trimmed = input;
    while (isspace(*trimmed)) {
        trimmed++;
    }
    int length = strlen(trimmed) - 1;
    while (isspace(trimmed[length])) {
        trimmed[length] = '\0';
        length--;
    }
    
    // Replace special characters with their HTML entities
    char *sanitized = malloc(MAX_INPUT_LENGTH);
    char *p = sanitized;
    for (char *q = trimmed; *q; q++) {
        if (*q == '<') {
            strcpy(p, "&lt;");
            p += 4;
        } else if (*q == '>') {
            strcpy(p, "&gt;");
            p += 4;
        } else if (*q == '&') {
            strcpy(p, "&amp;");
            p += 5;
        } else if (*q == '"') {
            strcpy(p, "&quot;");
            p += 6;
        } else if (*q == '\'') {
            strcpy(p, "&#39;");
            p += 5;
        } else {
            *p++ = *q;
        }
    }
    
    // Print sanitized input
    printf("Sanitized input:\n%s\n", sanitized);
    
    return 0;
}