//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <syslog.h>

// Define the log facility and level
#define LOG_FACILITY LOG_USER
#define LOG_LEVEL LOG_INFO

// Define the maximum length of a log message
#define LOG_MESSAGE_MAX_LENGTH 1024

// Function to generate a random log message
char *generate_log_message()
{
    // Define the possible characters that can be used in the log message
    const char *chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // Generate a random length for the log message
    int length = rand() % LOG_MESSAGE_MAX_LENGTH;

    // Allocate memory for the log message
    char *message = malloc(length + 1);

    // Generate the log message
    for (int i = 0; i < length; i++)
    {
        message[i] = chars[rand() % strlen(chars)];
    }

    // Terminate the log message with a null character
    message[length] = '\0';

    // Return the log message
    return message;
}

// Main function
int main()
{
    // Initialize the random number generator
    srand(time(NULL));

    // Open the system log
    openlog("my_app", LOG_PID | LOG_CONS, LOG_FACILITY);

    // Log a message to the system log
    syslog(LOG_LEVEL, generate_log_message());

    // Close the system log
    closelog();

    return 0;
}