//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char* input, char* output) {
    char* stack[256];
    int top = -1;

    char* token = strtok(input, " ");
    while (token!= NULL) {
        if (strncmp(token, "<", 1) == 0) {
            top++;
            strcpy(stack[top], token);
        } else if (strncmp(token, "</", 3) == 0) {
            if (top == -1) {
                fprintf(stderr, "Error: unmatched </%s>\n", token);
                exit(1);
            }
            top--;
            strcpy(stack[top], token);
        } else if (strncmp(token, " ", 1) == 0) {
            char* indent = malloc(strlen(stack[top]) + 2);
            if (strncmp(stack[top], "<", 1) == 0) {
                strncpy(indent, stack[top], strlen(stack[top]) - 1);
                strcat(indent, "\t");
            } else if (strncmp(stack[top], " ", 1) == 0) {
                strncpy(indent, stack[top], strlen(stack[top]) - 2);
                strcat(indent, "\t");
            } else {
                strncpy(indent, stack[top], strlen(stack[top]));
            }
            printf("%s", indent);
            free(indent);
        } else {
            printf("%s", token);
        }
        token = strtok(NULL, " ");
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        exit(1);
    }
    char* input = argv[1];
    char* output = argv[2];
    beautify_html(input, output);
    return 0;
}