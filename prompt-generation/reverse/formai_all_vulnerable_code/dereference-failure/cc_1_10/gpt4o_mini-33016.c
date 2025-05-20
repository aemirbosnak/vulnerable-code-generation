//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

// Function to convert natural language date to timestamp
time_t convertToTimestamp(char *input) {
    struct tm timeInfo = {0};
    
    // Token for months just like a grocery list, but with a twist
    const char *months[] = {
        "jan", "feb", "mar", "apr", "may", "jun",
        "jul", "aug", "sep", "oct", "nov", "dec"
    };

    // Try to find the month, day, and year just like a scavenger hunt
    char monthStr[4], dayStr[3], yearStr[5];
    sscanf(input, "%3s %2s %4s", monthStr, dayStr, yearStr);

    // Convert month string using a calculator (not really)
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(monthStr, months[i]) == 0) {
            timeInfo.tm_mon = i;
            break;
        }
    }

    // Assuming the input is always in the form of "mmm dd yyyy"
    timeInfo.tm_mday = atoi(dayStr);
    timeInfo.tm_year = atoi(yearStr) - 1900; // Year needs to be 1900 offset

    // If the date is an invalid date, give it a good slap
    if (mktime(&timeInfo) == -1) {
        printf("Womp womp! That date seems invalid! Try again!\n");
        return -1;
    }

    return mktime(&timeInfo);
}

// Function to retrieve the date in a pretty format like a fancy dinner invitation
void printFormattedDate(time_t timestamp) {
    struct tm *tm_info;
    char buffer[26];

    tm_info = localtime(&timestamp);
    
    strftime(buffer, sizeof(buffer), "Your date is: %Y-%m-%d", tm_info);
    printf("%s\n", buffer);
}

int main() {
    char input[MAX_LENGTH];

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Type your date in format 'MMM DD YYYY' (e.g. Jan 01 2023): \n");

    // We will capture the user's response like a secret agent
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character at the end, if any
    input[strcspn(input, "\n")] = 0;

    // Now we convert the input to a timestamp
    time_t timestamp = convertToTimestamp(input);

    // If the timestamp is -1, someone wasn't playing nice
    if (timestamp == -1) {
        return 1; // Exit with an error
    }

    // Finally, let’s get fancy and display the date
    printFormattedDate(timestamp);

    // Exit gracefully, like a ninja in the night
    return 0;
}