//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 50
#define MAX_TOKEN_LENGTH 50

struct token {
    char *value;
    int length;
};

struct date {
    int day;
    int month;
    int year;
};

int get_token(char *input, int start, int end, struct token *token) {
    int i = start;
    int j = 0;
    while (i < end && j < MAX_TOKEN_LENGTH - 1) {
        if (!isalnum(input[i])) {
            if (j == 0) {
                printf("Error: Invalid input\n");
                exit(1);
            }
            break;
        }
        token->value[j++] = toupper(input[i++]);
    }
    token->value[j] = '\0';
    token->length = j;
    return i;
}

int parse_date(char *input, struct date *date) {
    int i = 0;
    struct token tokens[MAX_TOKENS];
    int num_tokens = 0;
    while (i < strlen(input)) {
        if (num_tokens >= MAX_TOKENS) {
            printf("Error: Too many tokens\n");
            exit(1);
        }
        int j = get_token(input, i, strlen(input), &tokens[num_tokens]);
        if (num_tokens == 0 && j == i) {
            printf("Error: Invalid input\n");
            exit(1);
        }
        i = j;
        num_tokens++;
    }
    if (num_tokens < 3) {
        printf("Error: Invalid input\n");
        exit(1);
    }
    date->day = atoi(tokens[0].value);
    date->month = atoi(tokens[1].value);
    date->year = atoi(tokens[2].value);
    return 0;
}

void print_date(struct date date) {
    printf("%d/%d/%d\n", date.day, date.month, date.year);
}

int main() {
    char input[100];
    printf("Enter a date (DD/MM/YYYY): ");
    fgets(input, sizeof(input), stdin);
    struct date date;
    parse_date(input, &date);
    print_date(date);
    return 0;
}