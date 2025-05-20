//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a natural language date to standard date format
void convert_date(char* date) {
    // Convert month to lowercase and store in a temporary variable
    char temp_month[3];
    for (int i = 0; i < 2; i++) {
        temp_month[i] = tolower(date[i]);
    }

    // Check if month is "jan" or "feb"
    if (strcmp(temp_month, "jan") == 0) {
        // Set January
        printf("%d-01", 1);
    } else if (strcmp(temp_month, "feb") == 0) {
        // Set February
        printf("%d-02", 2);
    } else {
        // Invalid month, print error message
        printf("Invalid month\n");
    }

    // Convert day to lowercase and store in a temporary variable
    char temp_day[3];
    for (int i = 2; i < strlen(date); i++) {
        temp_day[i - 2] = tolower(date[i]);
    }

    // Check if day is less than 10
    if (temp_day[0] == '0') {
        // Add leading zero
        printf("%d", 10 + atoi(temp_day));
    } else {
        // Print day as is
        printf("%d", atoi(temp_day));
    }

    // Check if year is 2 digits
    if (strlen(date) == 6) {
        // Add leading zero
        printf("%d", 20 + atoi(date + 5));
    } else {
        // Print year as is
        printf("%d", atoi(date + 5));
    }

    // Print space after date
    printf(" ");
}

// Function to print program usage and exit
void print_usage(void) {
    printf("Usage:./date_converter <date>\n");
    exit(0);
}

// Function to get command line arguments
void get_arguments(int argc, char* argv[]) {
    if (argc!= 2) {
        print_usage();
    }
    convert_date(argv[1]);
}

// Main function
int main(int argc, char* argv[]) {
    get_arguments(argc, argv);
    return 0;
}