//FormAI DATASET v1.0 Category: System event logger ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to log system events to a file
void logEvent(char *event)
{
    // Open log file
    FILE *logFile = fopen("system_log.txt", "a");

    // Get current time
    time_t now = time(NULL);

    // Convert time to local time
    struct tm *localTime = localtime(&now);

    // Write event and timestamp to log file
    fprintf(logFile, "%d-%02d-%02d %02d:%02d:%02d - %s\n",
            localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
            localTime->tm_hour, localTime->tm_min, localTime->tm_sec, event);

    // Close log file
    fclose(logFile);
}

int main()
{
    // Generate random events
    char *events[] = {
        "CPU temperature exceeded maximum threshold",
        "Hard disk failure detected",
        "Memory usage exceeded 90%",
        "Network connection lost",
        "System update available",
        "Security breach detected"
    };

    // Seed random number generator
    srand(time(NULL));

    // Log 10 random events
    int i;
    for (i = 0; i < 10; i++) {
        int randomIndex = rand() % 6;
        logEvent(events[randomIndex]);
    }

    // Print success message
    printf("System events logged successfully!\n");

    return 0;
}