//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 100

struct tm parse_date(const char* date_str) {
    struct tm result = {0};
    char* copy = strdup(date_str);
    char* token = strtok(copy, " ");
    int year = 0, month = 0, day = 0;

    if (token == NULL) {
        free(copy);
        return result;
    }

    if (sscanf(token, "%d", &day)!= 1) {
        free(copy);
        return result;
    }

    token = strtok(NULL, " ");
    if (token == NULL) {
        free(copy);
        return result;
    }

    if (sscanf(token, "%d", &month)!= 1) {
        free(copy);
        return result;
    }

    token = strtok(NULL, " ");
    if (token == NULL) {
        free(copy);
        return result;
    }

    if (sscanf(token, "%d", &year)!= 1) {
        free(copy);
        return result;
    }

    result.tm_year = year - 1900;
    result.tm_mon = month - 1;
    result.tm_mday = day;

    free(copy);
    return result;
}

const char* format_date(const struct tm* date) {
    static char buffer[MAX_DATE_LENGTH];
    strftime(buffer, MAX_DATE_LENGTH, "%d %B %Y", date);
    return buffer;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <date>\n", argv[0]);
        return 1;
    }

    struct tm date = parse_date(argv[1]);
    if (date.tm_year == -1) {
        printf("Invalid date\n");
        return 1;
    }

    printf("%s\n", format_date(&date));
    return 0;
}