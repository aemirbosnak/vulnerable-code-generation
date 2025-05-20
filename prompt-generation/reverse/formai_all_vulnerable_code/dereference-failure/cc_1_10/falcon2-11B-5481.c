//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to recursively parse a string into a tree structure
void parse(char* s, char** tokens, int* depth, int* level, int** operands) {
    int op, i;
    char* token;
    int left, right;

    for (i = 0; i < *depth; i++) {
        token = *tokens;
        op = *token;
        *tokens = *token + 1;
        if (*token == '(') {
            parse(token + 1, tokens, depth, level, operands);
        } else if (*token == ')') {
            parse(*tokens, tokens, depth, level, operands);
            *tokens = token;
            return;
        } else {
            left = *level;
            right = *depth - 1;
            if (op == '+') {
                (*operands)[left] = (*operands)[left] + (*operands)[right];
            } else if (op == '-') {
                (*operands)[left] = (*operands)[left] - (*operands)[right];
            } else {
                (*operands)[left] = (*operands)[left] * (*operands)[right];
            }
            (*level)--;
        }
    }
}

int main() {
    char* s = "(2+3)*(4-1)";
    char** tokens = NULL;
    int depth = 0;
    int level = 0;
    int* operands = NULL;

    operands = (int*) malloc(sizeof(int) * 2);
    if (operands == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    parse(s, &tokens, &depth, &level, &operands);

    printf("Result: %d\n", operands[level]);
    return 0;
}