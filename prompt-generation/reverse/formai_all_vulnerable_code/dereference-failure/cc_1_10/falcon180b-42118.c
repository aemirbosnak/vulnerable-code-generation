//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

#define MAX_LENGTH 100

struct tm get_date(char *date_str) {
    struct tm result = {0};
    char *ptr = strptime(date_str, "%a %b %d %H:%M:%S %Y", &result);
    if (ptr == NULL || *ptr!= '\0') {
        fprintf(stderr, "Invalid date format: %s\n", date_str);
        exit(1);
    }
    return result;
}

char *format_date(struct tm date, int format) {
    char *result = malloc(MAX_LENGTH);
    strftime(result, MAX_LENGTH, "%a %b %d %H:%M:%S %Y", &date);
    switch (format) {
        case 1:
            /* Day/Month/Year */
            strcpy(result, strtok(result, " "));
            strcat(result, "/");
            strcat(result, strtok(NULL, " "));
            strcat(result, "/");
            strcat(result, strtok(NULL, " "));
            break;
        case 2:
            /* Month/Day/Year */
            strcpy(result, strtok(result, " "));
            strcat(result, "/");
            strcat(result, strtok(NULL, " "));
            strcat(result, "/");
            strcat(result, strtok(NULL, " "));
            break;
        case 3:
            /*Year/Month/Day */
            strcpy(result, strtok(result, " "));
            strcat(result, "/");
            strcat(result, strtok(NULL, " "));
            strcat(result, "/");
            strcat(result, strtok(NULL, " "));
            break;
        default:
            break;
    }
    return result;
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "en_US.UTF-8");
    if (argc!= 3) {
        printf("Usage: %s <date_format> <input_date>\n", argv[0]);
        return 1;
    }
    int format = atoi(argv[1]);
    char *input_date = argv[2];
    struct tm date = get_date(input_date);
    char *output_date = format_date(date, format);
    printf("Input Date: %s\n", input_date);
    printf("Output Date: %s\n", output_date);
    free(output_date);
    return 0;
}