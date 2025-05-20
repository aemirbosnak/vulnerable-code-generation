//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char* date_string;
    Date date;
} DateInfo;

DateInfo* convert_date(char* input_date, int* month_list[], int month_size) {
    DateInfo* date_info = (DateInfo*)malloc(sizeof(DateInfo));

    sscanf(input_date, "%d-%d-%d", &date_info->date.year, &date_info->date.month, &date_info->date.day);

    if (date_info->date.month < *month_list[0] || date_info->date.month > *month_list[month_size - 1]) {
        fprintf(stderr, "Invalid month: %d\n", date_info->date.month);
        free(date_info);
        return NULL;
    }

    date_info->date_string = malloc(strlen(input_date) + 1);
    strcpy(date_info->date_string, input_date);

    return date_info;
}

int main() {
    srand(time(NULL));

    int month_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int month_size = sizeof(month_list) / sizeof(int);

    DateInfo* date_info = convert_date("2023-01-01", month_list, month_size);

    if (date_info == NULL) {
        fprintf(stderr, "Error converting date\n");
        return 1;
    }

    printf("Converted date: %s\n", date_info->date_string);

    free(date_info->date_string);
    free(date_info);

    return 0;
}