//FormAI DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000

// Define a struct to represent a single log entry
typedef struct {
    char timestamp[20];
    char module[20];
    char message[200];
} LogEntry;

// Define a struct to represent an array of LogEntry structs
typedef struct {
    LogEntry entries[MAX_LOG_SIZE];
    int count;
} LogArray;

// Function to parse a single line from a log file and return a LogEntry struct
LogEntry parseLine(char* line) {
    LogEntry entry;
    char *token;

    // Set the timestamp
    token = strtok(line, " ");
    strcpy(entry.timestamp, token);

    // Set the module name
    token = strtok(NULL, " ");
    strcpy(entry.module, token);

    // Set the message
    token = strtok(NULL, "\n");
    strcpy(entry.message, token);

    return entry;
}

// Function to read a log file and populate a LogArray struct with LogEntry structs
LogArray readFile(char* filename) {
    FILE* file = fopen(filename, "r");
    char line[255];
    LogArray logArray = { .count = 0 };

    if (file) {
        while (fgets(line, sizeof(line), file)) {
            LogEntry entry = parseLine(line);
            logArray.entries[logArray.count] = entry;
            logArray.count++;
        }
        fclose(file);
    }
    return logArray;
}

// Function to filter a LogArray by module name and return a new LogArray with matching entries
LogArray filterByModule(LogArray logArray, char* module) {
    LogArray filteredArray = { .count = 0 };

    for (int i = 0; i < logArray.count; i++) {
        if (strcmp(logArray.entries[i].module, module) == 0) {
            filteredArray.entries[filteredArray.count] = logArray.entries[i];
            filteredArray.count++;
        }
    }

    return filteredArray;
}

// Function to print all entries in a LogArray
void printAll(LogArray logArray) {
    for (int i = 0; i < logArray.count; i++) {
        printf("%s %s %s\n", logArray.entries[i].timestamp, logArray.entries[i].module, logArray.entries[i].message);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <log_file> <module_name>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    char* module = argv[2];

    LogArray logArray = readFile(filename);
    LogArray filteredArray = filterByModule(logArray, module);

    printf("All entries for module %s:\n", module);
    printAll(filteredArray);

    printf("Total entries: %d\n", filteredArray.count);

    return 0;
}