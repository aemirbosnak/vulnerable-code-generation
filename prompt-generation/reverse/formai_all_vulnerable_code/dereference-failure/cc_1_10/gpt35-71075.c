//FormAI DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <string.h>

#define LOG_FILE "example.log"

// Function to parse a log line and extract fields
int parse_log_line(char *line, char **level, char **timestamp, char **message){
    char *token;
    int count = 0;
    while ((token = strsep(&line, " ")) != NULL) {
        if (count == 0) {
            *level = token;
        } else if (count == 1) {
            *timestamp = token;
        } else {
            *message = token;
            while ((token = strsep(&line, " ")) != NULL) {
                *message = strcat(*message, " ");
                *message = strcat(*message, token);
            }
            return 1;
        }
        count++;
    }
    return 0;
}

int main(){
    FILE *log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        printf("Error opening log file.");
        return 1;
    }

    char *line = NULL, *level, *timestamp, *message;
    size_t len = 0;
    ssize_t read;

    int info_count = 0, warning_count = 0, error_count = 0;

    // Read each line of the log file and parse it
    while ((read = getline(&line, &len, log_file)) != -1) {
        int parsed = parse_log_line(line, &level, &timestamp, &message);
        if (parsed) {
            if (strcmp(level, "INFO") == 0) {
                info_count++;
            } else if (strcmp(level, "WARNING") == 0) {
                warning_count++;
            } else if (strcmp(level, "ERROR") == 0) {
                error_count++;
            }
        }
    }

    printf("Log analysis results:\n");
    printf("INFO count:\t%d\n", info_count);
    printf("WARNING count:\t%d\n", warning_count);
    printf("ERROR count:\t%d\n", error_count);

    fclose(log_file);
    return 0;
}