//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: retro
// Retro-style Website Uptime Monitor
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main() {
    // Define variables
    char website[50];
    int status_code;
    time_t current_time;
    char* time_string;
    int uptime = 0;
    int downtime = 0;

    // Welcome message
    printf("Welcome to the Retro Website Uptime Monitor!\n\n");

    while(1) { // Continuously monitor website
        // Get website URL from user
        printf("Enter the URL of the website to monitor: ");
        scanf("%s", website);

        // Send request to website
        status_code = system(website);

        // Get current time
        current_time = time(NULL);
        time_string = ctime(&current_time);
        time_string[strlen(time_string)-1] = '\0'; // Remove newline character

        // Print results
        if (status_code == 0) {
            // Website is up
            printf("[UP] %s - %s\n", website, time_string);
            uptime++;
        } else {
            // Website is down
            printf("[DOWN] %s - %s\n", website, time_string);
            downtime++;
        }

        // Print uptime/downtime statistics
        printf("Uptime: %d | Downtime: %d\n\n", uptime, downtime);

        // Wait for 10 seconds before checking website again
        sleep(10);
    }

    return 0;
}