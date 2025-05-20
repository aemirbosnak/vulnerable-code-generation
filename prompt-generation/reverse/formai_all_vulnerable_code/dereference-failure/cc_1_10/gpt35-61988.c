//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    // Define variables
    struct tm starttime, endtime;
    time_t seconds;
    char time1[20], time2[20], buffer[100];

    // Set starting and ending times
    strptime("01/01/1950 00:00:00", "%d/%m/%Y %H:%M:%S", &starttime);
    strptime("01/01/2050 00:00:00", "%d/%m/%Y %H:%M:%S", &endtime);

    // Print starting message
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Your journey will start at the beginning of the year 1950 and end at the beginning of the year 2050.\n");

    // Loop through time travel simulations
    while (1) {
        
        // Prompt user for desired year
        printf("Enter a year between 1950 and 2050 to time travel to: ");
        fgets(buffer, 100, stdin);
        int year = atoi(buffer);
        
        // Check if year is within valid range
        if (year < 1950 || year > 2050) {
            printf("Invalid year entered. Please enter a year between 1950 and 2050.\n");
            continue;
        }
        
        // Set time to desired year
        sprintf(time1, "01/01/%d 00:00:00", year);
        strptime(time1, "%d/%m/%Y %H:%M:%S", &starttime);
        seconds = mktime(&starttime);

        // Check if desired year is before present
        if (seconds > time(NULL)) {
            printf("You cannot travel to a year in the future! Please enter a year before the current year.\n");
            continue;
        }

        // Calculate time difference
        int difference = (int) difftime(time(NULL), seconds);

        // Set end time to starting time plus time difference
        endtime = *localtime(&seconds);
        seconds += difference;
        endtime = *localtime(&seconds);

        // Print time travel results
        strftime(time1, 20, "%d/%m/%Y %H:%M:%S", &starttime);
        strftime(time2, 20, "%d/%m/%Y %H:%M:%S", &endtime);
        printf("You have traveled through time to %s from your current time of %s!\n", time1, time2);

        // Prompt for continuation
        printf("Would you like to continue time traveling? (Y/N): ");
        fgets(buffer, 100, stdin);
        if (buffer[0] != 'Y' && buffer[0] != 'y') {
            printf("Thank you for using the Time Travel Simulator!\n");
            break;
        }

    }

    return 0;
}