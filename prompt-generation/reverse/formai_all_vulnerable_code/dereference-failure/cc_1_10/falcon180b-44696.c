//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to convert a date string to a tm struct
struct tm* string_to_tm(const char* str) {
    struct tm tm = {0};
    strptime(str, "%d/%m/%Y", &tm);
    return &tm;
}

// Function to convert a tm struct to a date string
char* tm_to_string(const struct tm* tm) {
    char buf[80];
    strftime(buf, sizeof(buf), "%d/%m/%Y", tm);
    return strdup(buf);
}

// Function to get the day of the week for a given date
char* get_day_of_week(const struct tm* tm) {
    static char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[tm->tm_wday];
}

// Function to print the current date and time
void print_current_date_and_time() {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    printf("Current date and time: %s %s\n", tm_to_string(tm), get_day_of_week(tm));
}

// Function to convert a date string to a different format
char* convert_date_format(const char* input_date, const char* input_format, const char* output_format) {
    struct tm tm = {0};
    strptime(input_date, input_format, &tm);
    char* output_date = tm_to_string(&tm);
    return strdup(output_date);
}

// Main function to test the date converter
int main() {
    char* input_date = "25/12/2021";
    char* input_format = "%d/%m/%Y";
    char* output_format = "%A, %B %d, %Y";
    char* output_date = convert_date_format(input_date, input_format, output_format);
    printf("Input date: %s\n", input_date);
    printf("Output date: %s\n", output_date);
    free(output_date);
    return 0;
}