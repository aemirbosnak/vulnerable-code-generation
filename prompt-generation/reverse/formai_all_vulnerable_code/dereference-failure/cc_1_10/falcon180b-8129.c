//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

static Date parse_date(const char* str) {
    Date date = { 0 };
    char* token = strtok(str, " ");
    if (token == NULL) {
        return date;
    }
    date.day = atoi(token);
    token = strtok(NULL, " ");
    if (token == NULL) {
        return date;
    }
    date.month = atoi(token);
    token = strtok(NULL, " ");
    if (token == NULL) {
        return date;
    }
    date.year = atoi(token);
    return date;
}

static char* format_date(Date date, const char* format) {
    size_t bufsize = 64;
    char* buf = malloc(bufsize);
    strftime(buf, bufsize, format, mktime(&(struct tm){ 0, 0, 0, date.day, date.month - 1, date.year - 1900, 0, 0, -1 }));
    return buf;
}

int main() {
    setlocale(LC_TIME, "");
    char* input = NULL;
    size_t bufsize = 0;
    ssize_t read;
    while ((read = getline(&input, &bufsize, stdin))!= -1) {
        if (read > 0 && input[read - 1] == '\n') {
            input[--read] = '\0';
        }
        Date date = parse_date(input);
        if (date.day == 0 || date.month == 0 || date.year == 0) {
            printf("Invalid date\n");
        } else {
            char* format = "%A, %B %d, %Y";
            printf("Formatted date: %s\n", format_date(date, format));
        }
        free(input);
        input = NULL;
        bufsize = 0;
    }
    return 0;
}