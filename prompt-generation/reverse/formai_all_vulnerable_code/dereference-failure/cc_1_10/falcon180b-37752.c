//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

#define MAX_LEN 100
#define DELIM " \t\n\r\f\v"

struct tm get_date(char *date_str) {
    struct tm result = {0};
    char *token;
    int len;

    setlocale(LC_TIME, "");
    strptime(date_str, "%a %b %d %H:%M:%S %Y", &result);

    return result;
}

char *format_date(struct tm date, int format) {
    char *result = malloc(MAX_LEN * sizeof(char));
    strftime(result, MAX_LEN, "%a %b %d %H:%M:%S %Y", &date);

    switch (format) {
        case 1:
            strcpy(result, "Day: ");
            strcat(result, result + 9);
            break;
        case 2:
            strcpy(result, "Month: ");
            strcat(result, result + 8);
            break;
        case 3:
            strcpy(result, "Year: ");
            strcat(result, result + 10);
            break;
        case 4:
            strcpy(result, "Hour: ");
            strcat(result, result + 12);
            break;
        case 5:
            strcpy(result, "Minute: ");
            strcat(result, result + 16);
            break;
        case 6:
            strcpy(result, "Second: ");
            strcat(result, result + 19);
            break;
        default:
            strcpy(result, "Invalid format");
    }

    return result;
}

int main() {
    char input_str[MAX_LEN];
    char *token;
    struct tm date;
    int format;

    printf("Enter a date in the format 'Day Month Year Hour:Minute:Second': ");
    fgets(input_str, MAX_LEN, stdin);

    token = strtok(input_str, DELIM);
    if (token == NULL) {
        printf("Invalid input\n");
        return 1;
    }

    date = get_date(token);

    printf("Enter the output format (1: Day, 2: Month, 3: Year, 4: Hour, 5: Minute, 6: Second): ");
    scanf("%d", &format);

    char *result = format_date(date, format);
    printf("%s\n", result);

    free(result);
    return 0;
}