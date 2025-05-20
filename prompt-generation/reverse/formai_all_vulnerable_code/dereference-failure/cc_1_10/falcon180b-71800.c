//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX_STR_LEN 100

struct tm get_date(char *date_str) {
    struct tm tm = {0};
    char *token;
    int day, month, year;

    token = strtok(date_str, " ");
    if (token == NULL) {
        return tm;
    }
    if (strlen(token)!= 3) {
        return tm;
    }
    day = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL) {
        return tm;
    }
    if (strlen(token)!= 3) {
        return tm;
    }
    month = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL) {
        return tm;
    }
    if (strlen(token)!= 4) {
        return tm;
    }
    year = atoi(token);

    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year - 1900;
    tm.tm_isdst = -1;

    return tm;
}

char *date_to_str(struct tm tm) {
    char buf[MAX_STR_LEN];
    strftime(buf, MAX_STR_LEN, "%d %b %Y", &tm);
    return strdup(buf);
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "en_US.UTF-8");

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s DATE\n", argv[0]);
        return 1;
    }

    struct tm tm = get_date(argv[1]);
    if (tm.tm_year < 1000 || tm.tm_year > 9999) {
        fprintf(stderr, "Invalid date\n");
        return 1;
    }

    char *result = date_to_str(tm);
    printf("Result: %s\n", result);

    free(result);
    return 0;
}