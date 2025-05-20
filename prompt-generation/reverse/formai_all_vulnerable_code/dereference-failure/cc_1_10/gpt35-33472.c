//FormAI DATASET v1.0 Category: Syntax parsing ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100

int isAlphaNumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

char* getWord(char *line, int *curr_idx) {
    char *word = malloc(sizeof(char) * MAX_LEN);
    int idx = 0;
    while(isAlphaNumeric(line[*curr_idx])) {
        word[idx++] = line[(*curr_idx)++];
    }
    word[idx] = '\0';
    return word;
}

void parseLine(char *line, int *line_no, int *paren_count) {
    int i = 0, has_paren = 0, prev_paren_count = *paren_count;
    char *word;

    while(line[i] != '\0') {
        if(line[i] == '(') {
            has_paren = 1;
            (*paren_count)++;
        }
        else if(line[i] == ')') {
            (*paren_count)--;
            has_paren = 1;
        }
        else if(!isAlphaNumeric(line[i])) {
            if(i > 0 && isAlphaNumeric(line[i-1])) {
                word = getWord(line, &i);
                printf("Line %d: %s\n", *line_no, word);
                free(word);
            }
        }
        i++;
    }
    if(has_paren && prev_paren_count != *paren_count) {
        printf("Line %d: Unmatched Parentheses!\n", *line_no);
    }
}

int main() {
    char input[MAX_LEN];
    int line_no = 1, paren_count = 0;

    printf("Enter your input (Maximum Length: %d):\n", MAX_LEN);
    while(fgets(input, MAX_LEN, stdin)) {
        parseLine(input, &line_no, &paren_count);
        line_no++;
    }

    if(paren_count != 0) {
        printf("Unmatched Parentheses Present!");
    }

    return 0;
}