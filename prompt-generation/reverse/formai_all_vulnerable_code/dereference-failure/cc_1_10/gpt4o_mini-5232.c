//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function prototypes */
void get_user_input(char *input_date);
void convert_date(const char *input_date, struct tm *date);
void display_date(const struct tm *date);

int main() {
    char input_date[100];
    struct tm date = {0};

    printf("Welcome to the C Natural Language Date Converter!\n");
    printf("Please enter a date (e.g., 'January 1, 2023', 'next Friday', 'in 3 days'):\n");

    get_user_input(input_date);
    convert_date(input_date, &date);
    display_date(&date);

    return 0;
}

void get_user_input(char *input_date) {
    fgets(input_date, 100, stdin);
    input_date[strcspn(input_date, "\n")] = '\0'; // Remove trailing newline
}

void convert_date(const char *input_date, struct tm *date) {
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    char *month_names[] = {"", "January", "February", "March", "April", "May", "June", 
                           "July", "August", "September", "October", "November", "December"};
    int found = 0;

    if (sscanf(input_date, "%d/%d/%d", &date->tm_year, &date->tm_mon, &date->tm_mday) == 3) {
        date->tm_year -= 1900; // Adjust year
        date->tm_mon -= 1;     // Adjust month
        found = 1;
    }
    
    char *token = strtok((char *)input_date, " ");
    if (strcmp(token, "next") == 0) {
        token = strtok(NULL, " ");
        if (strcmp(token, "Friday") == 0) {
            date->tm_mday = current_time->tm_mday + (5 - current_time->tm_wday + 7) % 7;
            date->tm_mon = current_time->tm_mon;
            found = 1;
        }
    } else if (strcmp(token, "in") == 0) {
        token = strtok(NULL, " ");
        int days_ahead = atoi(token);
        date->tm_mday = current_time->tm_mday + days_ahead;
        date->tm_mon = current_time->tm_mon;
        found = 1;
    } else {
        for (int i = 1; i <= 12; i++) {
            if (strstr(input_date, month_names[i]) != NULL) {
                date->tm_mon = i - 1;
                sscanf(strstr(input_date, month_names[i]), "%*s %d, %d", &date->tm_mday, &date->tm_year);
                date->tm_year -= 1900; // Adjust year
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        fprintf(stderr, "Error: Invalid date format. Please try again.\n");
        exit(EXIT_FAILURE);
    }

    // Normalize the struct tm date to manage overflows properly
    mktime(date);
}

void display_date(const struct tm *date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "You entered the date: %A, %B %d, %Y\n", date);
    printf("%s", buffer);
}