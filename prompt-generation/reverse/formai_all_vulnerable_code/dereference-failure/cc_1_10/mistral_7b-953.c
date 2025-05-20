//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    int month, day, year;
} date;

date parse_date(char *str) {
    date result;
    char *token;

    token = strtok(str, "/- ");
    result.month = atoi(token);

    token = strtok(NULL, "/- ");
    result.day = atoi(token);

    token = strtok(NULL, "\0");
    result.year = atoi(token);

    return result;
}

void print_date(date d) {
    printf("%02d/%02d/%04d", d.month, d.day, d.year);
}

int main(int argc, char **argv) {
    int i;
    char input[100];
    date dates[10];

    if (argc < 11) {
        printf("Usage: %s DATE1 DATE2 ... DATE10\n", argv[0]);
        return 1;
    }

    for (i = 1; i <= 10; i++) {
        sprintf(input, "%s", argv[i]);
        dates[i - 1] = parse_date(input);
    }

    for (i = 1; i <= 10; i++) {
        printf("Date %d: ", i);
        print_date(dates[i - 1]);
        printf("\n");
    }

    time_t now = time(NULL);
    struct tm *ltm = localtime(&now);
    printf("\nCurrent date: %d/%d/%d\n", ltm->tm_mon + 1, ltm->tm_mday, ltm->tm_year + 1900);

    return 0;
}