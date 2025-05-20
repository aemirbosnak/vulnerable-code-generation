//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <string.h>

int is_leap_year(int year) {
    if (year % 400 == 0) {
        return 1;
    }
    if (year % 100 == 0) {
        return 0;
    }
    if (year % 4 == 0) {
        return 1;
    }
    return 0;
}

int days_in_month(int year, int month) {
    switch (month) {
        case 2:
            if (is_leap_year(year)) {
                return 29;
            } else {
                return 28;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

int get_month_from_string(char *month_string) {
    if (strcmp(month_string, "January") == 0) {
        return 1;
    } else if (strcmp(month_string, "February") == 0) {
        return 2;
    } else if (strcmp(month_string, "March") == 0) {
        return 3;
    } else if (strcmp(month_string, "April") == 0) {
        return 4;
    } else if (strcmp(month_string, "May") == 0) {
        return 5;
    } else if (strcmp(month_string, "June") == 0) {
        return 6;
    } else if (strcmp(month_string, "July") == 0) {
        return 7;
    } else if (strcmp(month_string, "August") == 0) {
        return 8;
    } else if (strcmp(month_string, "September") == 0) {
        return 9;
    } else if (strcmp(month_string, "October") == 0) {
        return 10;
    } else if (strcmp(month_string, "November") == 0) {
        return 11;
    } else if (strcmp(month_string, "December") == 0) {
        return 12;
    } else {
        return -1;
    }
}

void print_usage() {
    printf("Usage: date_converter <month> <day> <year>\n");
}

int main(int argc, char **argv) {
    if (argc != 4) {
        print_usage();
        return 1;
    }
    int month = get_month_from_string(argv[1]);
    int day = atoi(argv[2]);
    int year = atoi(argv[3]);
    if (month == -1 || day < 1 || day > days_in_month(year, month) || year < 0) {
        printf("Invalid date\n");
        return 1;
    }
    printf("%04d-%02d-%02d\n", year, month, day);
    return 0;
}