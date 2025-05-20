//FormAI DATASET v1.0 Category: Log analysis ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

typedef struct LogInfo {
  char* timestamp;
  char* loglevel;
  char* message;
} LogInfo;

// Function to split the log line by delimiter
void split_line(char* line, LogInfo* log) {
    char* token = strtok(line, " ");
    log->timestamp = token;
    token = strtok(NULL, " ");
    log->loglevel = token;
    char* message = strtok(NULL, "\n");
    message++;
    log->message = message;
}

// Function to get the log level count
int get_level_count(char* filename, char* level) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        LogInfo* log = malloc(sizeof(LogInfo));
        split_line(line, log);
        if(strcmp(log->loglevel, level) == 0) {
            count++;
        }
    }
    fclose(fp);
    if(line) {
        free(line);
    }
    return count;
}

// Main function
int main() {
    char* filename = "example_log.txt";
    printf("Total count: %d\n", get_level_count(filename, "DEBUG"));
    printf("Total count: %d\n", get_level_count(filename, "INFO"));
    printf("Total count: %d\n", get_level_count(filename, "WARNING"));
    printf("Total count: %d\n", get_level_count(filename, "ERROR"));
    return 0;
}