//FormAI DATASET v1.0 Category: Date and time ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

// Function to get the current time as a formatted string
void getFormattedTime(char* buffer, size_t bufferSize) {
    time_t rawTime;
    struct tm* timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(buffer, bufferSize, "%m/%d/%Y %I:%M:%S %p", timeInfo);
}

// Function to handle SIGINT signal
void handleSigint(int signum) {
    printf("\nReceived SIGINT signal, program terminating...\n");
    exit(0);
}

int main() {
    // Register signal handler for SIGINT
    struct sigaction sigintAction;
    sigintAction.sa_handler = handleSigint;
    sigintAction.sa_flags = 0;
    sigemptyset(&sigintAction.sa_mask);
    sigaction(SIGINT, &sigintAction, NULL);

    // Open a file for writing
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    // Enable non-blocking mode for file descriptor
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        printf("Error getting file descriptor flags: %s\n", strerror(errno));
        close(fd);
        return 1;
    }
    flags |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flags) == -1) {
        printf("Error setting file descriptor flags: %s\n", strerror(errno));
        close(fd);
        return 1;
    }

    // Asynchronous loop
    bool done = false;
    while (!done) {
        // Generate random number of seconds to wait
        int waitTime = rand() % 6;
        printf("Waiting %d second(s)...\n", waitTime);
        sleep(waitTime);

        // Get current time and write to file
        char buffer[50];
        getFormattedTime(buffer, sizeof(buffer));
        int bytesWritten = write(fd, buffer, strlen(buffer));
        if (bytesWritten == -1 && errno != EAGAIN) {
            printf("Error writing to file: %s\n", strerror(errno));
            done = true;
        }

        // Check if user wants to quit
        char userChoice;
        printf("Press 'q' to quit or any key to continue.\n");
        scanf(" %c", &userChoice);
        if (userChoice == 'q') {
            done = true;
        }
    }

    // Close file and exit
    close(fd);
    return 0;
}