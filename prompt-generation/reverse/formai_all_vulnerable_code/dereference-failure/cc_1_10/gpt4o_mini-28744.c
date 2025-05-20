//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256

void printHelp() {
    printf("Usage: date_converter <date_in_natural_language>\n");
    printf("Examples:\n");
    printf(" - \"tomorrow\"\n");
    printf(" - \"next Friday\"\n");
    printf(" - \"January 1, 2023\"\n");
    printf(" - \"three days ago\"\n");
}

int parseNaturalLanguageDate(const char *input, struct tm *date) {
    time_t now = time(NULL);
    struct tm *current = localtime(&now);
    
    if (strstr(input, "tomorrow")) {
        current->tm_mday += 1;
    } else if (strstr(input, "yesterday")) {
        current->tm_mday -= 1;
    } else if (strstr(input, "next ")) {
        char weekday[10];
        sscanf(input + 5, "%s", weekday);
        if (strcmp(weekday, "Monday") == 0) current->tm_mday += (7 - current->tm_wday + 1) % 7 + 1;
        else if (strcmp(weekday, "Tuesday") == 0) current->tm_mday += (7 - current->tm_wday + 2) % 7 + 1;
        else if (strcmp(weekday, "Wednesday") == 0) current->tm_mday += (7 - current->tm_wday + 3) % 7 + 1;
        else if (strcmp(weekday, "Thursday") == 0) current->tm_mday += (7 - current->tm_wday + 4) % 7 + 1;
        else if (strcmp(weekday, "Friday") == 0) current->tm_mday += (7 - current->tm_wday + 5) % 7 + 1;
        else if (strcmp(weekday, "Saturday") == 0) current->tm_mday += (7 - current->tm_wday + 6) % 7 + 1;
        else if (strcmp(weekday, "Sunday") == 0) current->tm_mday += (7 - current->tm_wday + 0) % 7 + 1;
    } else if (strstr(input, "days ago")) {
        int days;
        sscanf(input, "%d days ago", &days);
        current->tm_mday -= days;
    } else if (strstr(input, "today")) {
        // Do nothing, just stay with the current date
    } else {
        if (strptime(input, "%B %d, %Y", current) == NULL) {
            fprintf(stderr, "Error: Cannot parse date format. Please follow 'Month Day, Year'\n");
            return -1;
        }
    }
    
    // Normalize the date
    mktime(current);
    *date = *current;
    return 0;
}

void printDate(struct tm *date) {
    char buffer[BUFFER_SIZE];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", date);
    printf("Converted Date: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printHelp();
        return EXIT_FAILURE;
    }
    
    struct tm date = {0};
    if (parseNaturalLanguageDate(argv[1], &date) != 0) {
        return EXIT_FAILURE;
    }
    
    printDate(&date);
    return EXIT_SUCCESS;
}