//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CODE_LENGTH 30
#define MAX_CODE_COUNT 10000
#define CODE_TABLE_SIZE 10007

typedef struct code_t {
    int count;
    char code[MAX_CODE_LENGTH + 1];
} code_t;

code_t *codetable[CODE_TABLE_SIZE];

char *encode(char *input) {
    int len = strlen(input);
    char *output = (char *) calloc(len, sizeof(char));
    int current_code_count = 256;
    int input_pos = 0;
    int output_pos = 0;

    while (input_pos < len) {
        char current_char = input[input_pos];
        int code_index = current_char;
        while (codetable[code_index] != NULL && strcmp(codetable[code_index]->code, &input[input_pos]) == 0) {
            input_pos += strlen(codetable[code_index]->code);
            current_char = input[input_pos];
            code_index = (code_index << 4) ^ current_char;
        }

        if (codetable[code_index] != NULL) {
            output[output_pos++] = (char) code_index;
            codetable[code_index]->count++;
        } else {
            if (current_code_count >= MAX_CODE_COUNT) {
                printf("Error: dictionary full\n");
                return NULL;
            }
            code_t *new_code = (code_t *) calloc(1, sizeof(code_t));
            new_code->count = 1;
            strncpy(new_code->code, &input[input_pos], 1);
            new_code->code[1] = '\0';
            codetable[code_index] = new_code;
            output[output_pos++] = (char) (code_index >> 8);
            output[output_pos++] = (char) (code_index & 0xff);
            current_code_count++;
        }
    }

    output[output_pos] = '\0';
    return output;
}

char *decode(char *input) {
    int len = strlen(input);
    int current_code_count = 256;
    int input_pos = 0;
    int output_pos = 0;

    char *output = (char *) calloc(len * 2, sizeof(char));

    while (input_pos < len) {
        int code_index = ((unsigned char) input[input_pos++] << 8) | ((unsigned char) input[input_pos++]);
        if (codetable[code_index] != NULL) {
            strncpy(&output[output_pos], codetable[code_index]->code, strlen(codetable[code_index]->code));
            output_pos += strlen(codetable[code_index]->code);
            codetable[code_index]->count++;
            if (strlen(codetable[code_index]->code) == 1 && current_code_count < MAX_CODE_COUNT) {
                code_t *new_code = (code_t *) calloc(1, sizeof(code_t));
                new_code->count = 1;
                strncpy(new_code->code, codetable[code_index]->code, strlen(codetable[code_index]->code));
                codetable[new_code->code[0]] = new_code;
                current_code_count++;
            }
        } else {
            printf("Error: bad input\n");
            return NULL;
        }
    }

    output[output_pos] = '\0';
    return output;
}

int main() {
    char input[101];
    printf("Enter a string to compress: ");
    scanf("%s", input);

    char *compressed = encode(input);
    printf("Compressed: %s\n", compressed);

    char *decompressed = decode(compressed);
    printf("Decompressed: %s\n", decompressed);

    for (int i = 0; i < CODE_TABLE_SIZE; ++i) {
        if (codetable[i] != NULL) {
            printf("%d\t%d\t%s\n", i, codetable[i]->count, codetable[i]->code);
        }
    }
    
    return 0;
}