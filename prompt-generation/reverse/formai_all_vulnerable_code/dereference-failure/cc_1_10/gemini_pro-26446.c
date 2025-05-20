//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a number
int is_number(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a string to an integer
int to_int(char *str) {
    int i, num = 0;
    for (i = 0; i < strlen(str); i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

// Function to convert a date string to a date struct
struct date {
    int year;
    int month;
    int day;
} to_date(char *str) {
    struct date date;
    char *token = strtok(str, "/");
    date.month = to_int(token);
    token = strtok(NULL, "/");
    date.day = to_int(token);
    token = strtok(NULL, "/");
    date.year = to_int(token);
    return date;
}

// Function to print a date struct
void print_date(struct date date) {
    printf("%02d/%02d/%04d\n", date.month, date.day, date.year);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <date string>\n", argv[0]);
        return 1;
    }

    if (!is_number(argv[1])) {
        printf("Error: Invalid date string\n");
        return 1;
    }

    struct date date = to_date(argv[1]);
    print_date(date);

    return 0;
}