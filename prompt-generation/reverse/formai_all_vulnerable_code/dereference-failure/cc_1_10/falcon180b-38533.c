//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

#define MAX_INPUT_LENGTH 50
#define MONTHS_IN_A_YEAR 12

typedef struct {
    int day;
    int month;
    int year;
} Date;

void print_date(Date date) {
    char month_name[20];
    strftime(month_name, sizeof(month_name), "%B", date.month);
    printf("%s %d, %d\n", month_name, date.day, date.year);
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    Date input_date;

    printf("Enter a date in the format 'MM/DD/YYYY': ");
    fgets(input_date.month, MAX_INPUT_LENGTH, stdin);
    sscanf(input_date.month, "%d/%d/%d", &input_date.day, &input_date.month, &input_date.year);

    if (input_date.day < 1 || input_date.day > 31 ||
        input_date.month < 1 || input_date.month > 12 ||
        input_date.year < 1 || input_date.year > 9999) {
        printf("Invalid date.\n");
        return 1;
    }

    time_t input_time = mktime(&(struct tm){0, input_date.month - 1, input_date.day, 0, 0, input_date.year - 1900, 0, -1, 0});
    if (input_time == -1) {
        printf("Invalid date.\n");
        return 1;
    }

    input_date.day = (int)mktime(NULL);
    input_date.month = (int)mktime(NULL);
    input_date.year = (int)mktime(NULL);

    printf("You entered: ");
    print_date(input_date);

    return 0;
}