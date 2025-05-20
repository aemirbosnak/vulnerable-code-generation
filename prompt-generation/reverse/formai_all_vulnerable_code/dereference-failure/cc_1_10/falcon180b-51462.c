//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

// Function prototypes
int isValidDate(const char* date);
struct tm* parseDate(const char* date, struct tm* tm);
char* formatDate(const struct tm* tm, int format);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <date>\n", argv[0]);
        return 1;
    }

    setlocale(LC_ALL, "");
    const char* date = argv[1];

    if (!isValidDate(date)) {
        printf("Invalid date format\n");
        return 1;
    }

    struct tm* tm = parseDate(date, (struct tm*)malloc(sizeof(struct tm)));
    if (tm == NULL) {
        printf("Invalid date\n");
        return 1;
    }

    char* formattedDate = formatDate(tm, 0);
    printf("Formatted date: %s\n", formattedDate);
    free(tm);
    free(formattedDate);
    return 0;
}

// Checks if a given string is a valid date in the format "YYYY-MM-DD"
int isValidDate(const char* date) {
    int len = strlen(date);
    if (len!= 10) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        char c = tolower(date[i]);
        if (!isdigit(c) && c!= '-') {
            return 0;
        }
    }

    return 1;
}

// Parses a date string and fills a struct tm object
struct tm* parseDate(const char* date, struct tm* tm) {
    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day);

    if (month < 1 || month > 12) {
        return NULL;
    }

    if (day < 1 || day > 31) {
        return NULL;
    }

    tm->tm_year = year - 1900;
    tm->tm_mon = month - 1;
    tm->tm_mday = day;
    tm->tm_isdst = -1;

    return tm;
}

// Formats a struct tm object into a string in the given format
char* formatDate(const struct tm* tm, int format) {
    char* dateString = malloc(50);
    strftime(dateString, 50, "%Y-%m-%d", tm);

    switch (format) {
        case 0:
            return dateString;
        case 1:
            return strftime(dateString, 50, "%A, %B %d, %Y", tm);
        case 2:
            return strftime(dateString, 50, "%d %B %Y", tm);
        case 3:
            return strftime(dateString, 50, "%B %Y", tm);
        default:
            return NULL;
    }
}