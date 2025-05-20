//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_date(char *date_str, int *month, int *day, int *year) {
    char *month_str[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month_len = 11;
    int day_len = 2;
    int year_len = 4;
    char *date_arr[3] = {date_str, NULL, NULL};

    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < month_len; j++) {
            if (strcmp(date_arr[i], month_str[j]) == 0) {
                *month = j + 1;
                break;
            }
        }
    }
    for (i = 0; i < day_len; i++) {
        if (date_arr[i + 1] == NULL) {
            break;
        } else {
            if (strcmp(date_arr[i], "th") == 0) {
                if (i == 0) {
                    *day = 1;
                } else {
                    *day = atoi(date_arr[i - 1]) + 1;
                }
                break;
            } else if (strcmp(date_arr[i], "st") == 0) {
                *day = 1;
                break;
            } else if (strcmp(date_arr[i], "nd") == 0) {
                *day = 2;
                break;
            } else if (strcmp(date_arr[i], "rd") == 0) {
                *day = 3;
                break;
            }
        }
    }
    for (i = 0; i < year_len; i++) {
        if (date_arr[i + 2] == NULL) {
            break;
        } else {
            if (strcmp(date_arr[i], "th") == 0) {
                if (i == 0) {
                    *year = 2000;
                } else {
                    *year = atoi(date_arr[i - 1]) + 2000;
                }
                break;
            } else if (strcmp(date_arr[i], "st") == 0) {
                *year = 2000;
                break;
            } else if (strcmp(date_arr[i], "nd") == 0) {
                *year = 2001;
                break;
            } else if (strcmp(date_arr[i], "rd") == 0) {
                *year = 2002;
                break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <date string>\n", argv[0]);
        return 1;
    }
    char *date_str = argv[1];
    int month, day, year;
    convert_date(date_str, &month, &day, &year);
    printf("%d-%d-%d\n", year, month, day);
    return 0;
}