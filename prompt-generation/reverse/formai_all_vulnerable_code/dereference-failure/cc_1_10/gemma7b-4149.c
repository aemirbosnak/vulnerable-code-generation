//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void dateread(char **date, int *year, int *month, int *day) {
    char buffer[256];
    printf("Enter the date in the format YYYY-MM-DD: ");
    fgets(buffer, 256, stdin);

    *year = atoi(strtok(buffer, "-"));
    *month = atoi(strtok(NULL, "-"));
    *day = atoi(strtok(NULL, "-"));
}

int datevalidate(int year, int month, int day) {
    if (year < 1 || year > 2023) {
        return 0;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    if (day < 1 || day > 31) {
        return 0;
    }
    return 1;
}

char *dateformat(int year, int month, int day) {
    char *date = malloc(20);
    snprintf(date, 20, "%d-%d-%d", year, month, day);
    return date;
}

int main() {
    char **date = NULL;
    int year, month, day;

    dateread(&date, &year, &month, &day);

    if (datevalidate(year, month, day) == 1) {
        char *formatted_date = dateformat(year, month, day);
        printf("The formatted date is: %s\n", formatted_date);
        free(formatted_date);
    } else {
        printf("Invalid date.\n");
    }

    return 0;
}