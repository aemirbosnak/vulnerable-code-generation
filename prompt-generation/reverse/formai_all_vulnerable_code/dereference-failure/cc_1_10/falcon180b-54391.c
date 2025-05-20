//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 20
#define MONTH_NAMES_LENGTH 12

struct tm parse_date(const char* date_string) {
    struct tm result = {0};
    char* token = strtok(date_string, " ");
    if(token == NULL || strlen(token)!= 3) {
        printf("Invalid date format\n");
        exit(1);
    }
    result.tm_mday = atoi(token);
    token = strtok(NULL, " ");
    if(token == NULL || strlen(token) < 3 || strlen(token) > 9) {
        printf("Invalid date format\n");
        exit(1);
    }
    result.tm_mon = atoi(token) - 1;
    result.tm_year = atoi(strtok(NULL, " ")) - 1900;
    mktime(&result);
    return result;
}

void print_date(const struct tm* date, char* format) {
    strftime(format, MAX_DATE_LENGTH, "%A, %B %d, %Y", date);
}

int main(int argc, char** argv) {
    if(argc!= 2) {
        printf("Usage: %s <date>\n", argv[0]);
        exit(1);
    }

    char* input_date = argv[1];
    struct tm parsed_date = parse_date(input_date);
    char output_date[MAX_DATE_LENGTH];

    print_date(&parsed_date, "Today is %A, %B %d, %Y");
    printf("\n");

    print_date(&parsed_date, "On %A, %B %d, %Y");
    printf("\n");

    print_date(&parsed_date, "%A, %B %d, %Y was %A, %B %d, %Y ago");
    printf("\n");

    return 0;
}