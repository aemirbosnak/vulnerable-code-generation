//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
/* C Natural Language Date Converter - Ken Thompson style */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char *MONTHS[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const char *DAYS[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

int days_in_month(int month, int year);
int is_leap_year(int year);
int get_day_of_week(int day, int month, int year);
int parse_month(const char *month);
void tokenize_date(char *date, char ***tokens, int *num_tokens);
void free_tokens(char **tokens, int num_tokens);
void print_tokens(char **tokens, int num_tokens);

int main(int argc, char **argv) {
    char date[100];
    printf("Enter a date: ");
    fgets(date, 100, stdin);
    date[strcspn(date, "\n")] = '\0'; // remove newline character
    
    char **tokens;
    int num_tokens = 0;
    tokenize_date(date, &tokens, &num_tokens);
    
    if (num_tokens != 4) {
        printf("Invalid date format.\n");
        free_tokens(tokens, num_tokens);
        exit(1);
    }
    
    int day = atoi(tokens[1]);
    int month = parse_month(tokens[0]);
    int year = atoi(tokens[2]);
    
    if (month == -1) {
        printf("Invalid month.\n");
        free_tokens(tokens, num_tokens);
        exit(1);
    }
    
    if (day < 1 || day > days_in_month(month, year)) {
        printf("Invalid day.\n");
        free_tokens(tokens, num_tokens);
        exit(1);
    }
    
    printf("%s, %s %d, %d\n", DAYS[get_day_of_week(day, month, year)], MONTHS[month - 1], day, year);
    
    free_tokens(tokens, num_tokens);
    return 0;
}

int days_in_month(int month, int year) {
    if (month == 2) {
        return is_leap_year(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int is_leap_year(int year) {
    if (year % 4 != 0) {
        return 0;
    } else if (year % 100 != 0) {
        return 1;
    } else if (year % 400 != 0) {
        return 0;
    } else {
        return 1;
    }
}

int get_day_of_week(int day, int month, int year) {
    // January and February are considered months 13 and 14 of the previous year
    if (month < 3) {
        month += 12;
        year--;
    }
    
    // Calculate day of the week using Zeller's Congruence
    int k = year % 100;
    int j = year / 100;
    int h = (day + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7;
    
    // Convert result to 0-6 range (Sunday-Saturday)
    h -= 1;
    if (h < 0) h = 6;
    return h;
}

int parse_month(const char *month) {
    int i;
    for (i = 0; i < 12; i++) {
        if (strcasecmp(month, MONTHS[i]) == 0) {
            return i + 1;
        }
    }
    return -1;
}

void tokenize_date(char *date, char ***tokens, int *num_tokens) {
    *tokens = malloc(sizeof(char *));
    char *token = strtok(date, " ");
    while (token) {
        (*tokens)[*num_tokens] = malloc(strlen(token) + 1);
        strcpy((*tokens)[*num_tokens], token);
        (*num_tokens)++;
        *tokens = realloc(*tokens, sizeof(char *) * (*num_tokens + 1));
        token = strtok(NULL, " ");
    }
}

void free_tokens(char **tokens, int num_tokens) {
    int i;
    for (i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

void print_tokens(char **tokens, int num_tokens) {
    int i;
    for (i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i]);
    }
}