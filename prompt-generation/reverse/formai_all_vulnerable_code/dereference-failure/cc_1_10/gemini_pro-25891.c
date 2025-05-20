//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_STR_LEN 11

int convert_date(char *date_str, struct tm *datetime) {
    char *tokens[4];
    char *delims = "/", *context;
    char *tmp_str;
    int num_tokens;
    int i;

    num_tokens = 0;
    tmp_str = strtok(date_str, delims);
    while (tmp_str != NULL) {
        tokens[num_tokens++] = tmp_str;
        tmp_str = strtok(NULL, delims);
    }

    if (num_tokens != 3) {
        fprintf(stderr, "Error: Invalid date format. Expected: MM/DD/YYYY\n");
        return -1;
    }

    datetime->tm_mon = atoi(tokens[0]) - 1;
    datetime->tm_mday = atoi(tokens[1]);
    datetime->tm_year = atoi(tokens[2]) - 1900;

    return 0;
}

int main(int argc, char *argv[]) {
    struct tm datetime;
    time_t timestamp;
    char date_str[MAX_DATE_STR_LEN + 1];

    if (argc == 2) {
        strncpy(date_str, argv[1], MAX_DATE_STR_LEN);
        date_str[MAX_DATE_STR_LEN] = '\0';
    } else {
        printf("Enter a date in MM/DD/YYYY format: ");
        if (fgets(date_str, MAX_DATE_STR_LEN + 1, stdin) == NULL) {
            fprintf(stderr, "Error: Failed to read date from input.\n");
            return -1;
        }
    }

    if (convert_date(date_str, &datetime) != 0) {
        return -1;
    }

    timestamp = mktime(&datetime);
    if (timestamp == -1) {
        fprintf(stderr, "Error: Failed to convert date to timestamp.\n");
        return -1;
    }

    printf("Timestamp: %ld\n", timestamp);

    return 0;
}