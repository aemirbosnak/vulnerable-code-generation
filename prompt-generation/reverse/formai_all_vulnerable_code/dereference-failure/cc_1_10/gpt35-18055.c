//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CSV_LINE_LENGTH 1024
#define MAX_CSV_COLUMNS     100

/* Tokenizer State */
typedef struct TokenizerState {
    int position;
    int length;
    char* parse_string;
} TokenizerState;

/* Function to create a new Tokenizer State Instance */
TokenizerState* new_tokenizer_state(char* parse_string) {
    TokenizerState* ts = (TokenizerState*) malloc(sizeof(TokenizerState));
    ts->position = 0;
    ts->length = strlen(parse_string);
    ts->parse_string = parse_string;
    return ts;
}

/* Function to tokenize the CSV Line */
char* next_token(TokenizerState* ts, const char delimiter) {
    int p = ts->position;
    while (p < ts->length && ts->parse_string[p] != delimiter) {
        p++;
    }
    char* result = strndup(ts->parse_string + ts->position, p - ts->position);
    ts->position = (p < ts->length) ? p + 1 : p;
    return result;
}

/* CSV Reader Function */
int csv_read(const char* filename, char*** rows, int* row_count, int* column_count) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }
    char buffer[MAX_CSV_LINE_LENGTH];
    int rcount = 0;
    int ccount = 0;
    while (fgets(buffer, MAX_CSV_LINE_LENGTH, fp) != NULL) {
        if (rcount == 0) {
            *column_count = ccount = 0;
            TokenizerState* ts = new_tokenizer_state(buffer);
            while (next_token(ts, ',') != NULL) {
                ccount++;
            }
            ccount++;
            *column_count = ccount;
            free(ts);
            *rows = (char**)malloc(ccount * sizeof(char*));
            for (int i = 0; i < ccount; i++) {
                (*rows)[i] = (char*)malloc(MAX_CSV_LINE_LENGTH * sizeof(char));
            }
        }
        TokenizerState* ts = new_tokenizer_state(buffer);
        int c = 0;
        char* tok;
        while ((tok = next_token(ts, ',')) != NULL) {
            strcpy((*rows)[c++], tok);
            free(tok);
        }
        (*row_count)++;
        rcount++;
        free(ts);
    }
    fclose(fp);
    return 0;
}

/* Main Function */
int main() {
    char** rows;
    int row_count = 0, column_count = 0;
    int ret = csv_read("test.csv", &rows, &row_count, &column_count);
    if (ret != 0) {
        printf("Error reading CSV File.");
        return -1;
    }
    printf("Successfully read %d rows with %d columns each.\n", row_count, column_count);
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            printf("%s\n", rows[i] + j * MAX_CSV_LINE_LENGTH);
        }
    }
    for (int i = 0; i < column_count; i++) {
        free(rows[i]);
    }
    free(rows);
    return 0;
}