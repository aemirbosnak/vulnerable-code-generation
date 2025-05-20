//FormAI DATASET v1.0 Category: System event logger ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>


// define the maximum size of a log message
#define MAX_LOG_MSG_SIZE 1024

// define the number of log files to keep
#define MAX_LOG_FILES 10

// define the maximum size of a log file
#define MAX_LOG_FILE_SIZE 1048576

// define the log file name format
#define LOG_FILE_FORMAT "event_log_%d.log"


// structure to hold a single log message
typedef struct log_message {
    time_t timestamp;
    char message[MAX_LOG_MSG_SIZE];
} LogMessage;


// function to write a log message to a log file
void write_log_message(LogMessage* log_msg) {
    // get the current time
    time_t current_time;
    time(&current_time);

    // format the timestamp as a string
    char timestamp_string[32];
    strftime(timestamp_string, sizeof(timestamp_string), "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    // create the log message string
    char log_message_string[MAX_LOG_MSG_SIZE+64];
    sprintf(log_message_string, "[%s] %s\n", timestamp_string, log_msg->message);

    // open the log file for writing
    static FILE* log_file = NULL;
    if (log_file == NULL) {
        char log_file_name[32];
        snprintf(log_file_name, sizeof(log_file_name), LOG_FILE_FORMAT, 0);
        log_file = fopen(log_file_name, "w");
        if (log_file == NULL) {
            fprintf(stderr, "Error opening log file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    // check if the log file has reached its maximum size
    long current_pos = ftell(log_file);
    if (current_pos >= MAX_LOG_FILE_SIZE) {
        fclose(log_file);
        for (int i = MAX_LOG_FILES-1; i > 0; i--) {
            char old_log_file_name[32];
            char new_log_file_name[32];
            snprintf(old_log_file_name, sizeof(old_log_file_name), LOG_FILE_FORMAT, i-1);
            snprintf(new_log_file_name, sizeof(new_log_file_name), LOG_FILE_FORMAT, i);
            rename(old_log_file_name, new_log_file_name);
        }
        char log_file_name[32];
        snprintf(log_file_name, sizeof(log_file_name), LOG_FILE_FORMAT, 0);
        log_file = fopen(log_file_name, "w");
        if (log_file == NULL) {
            fprintf(stderr, "Error opening log file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    // write the log message string to the log file
    fprintf(log_file, "%s", log_message_string);

    // flush the log file buffer
    fflush(log_file);
}


int main(int argc, char* argv[]) {
    // create a test log message
    LogMessage test_log_msg = {time(NULL), "Test log message"};

    // write the log message to a log file
    write_log_message(&test_log_msg);

    // exit the program
    exit(EXIT_SUCCESS);
}