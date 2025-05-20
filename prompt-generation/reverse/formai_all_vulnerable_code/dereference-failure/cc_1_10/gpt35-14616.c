//FormAI DATASET v1.0 Category: Log analysis ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// struct to hold log data
struct LogData {
    char timestamp[20];
    char level[10];
    char message[100];
};

// function to read log file and fill data into struct
int readLogData(char *filename, struct LogData *data) {
    FILE *fp;
    char buffer[200];

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }

    int count = 0;
    while(fgets(buffer, 200, fp)) {
        char *token = strtok(buffer, " ");

        int i = 0;
        while(token != NULL && i < 3) {
            if(i == 0) strcpy(data[count].timestamp, token);
            else if(i == 1) strcpy(data[count].level, token);
            else strcpy(data[count].message, token);
            token = strtok(NULL, " ");
            i++;
        }

        count++;
    }

    fclose(fp);

    return count;
}

// function to print log data
void printLogData(struct LogData *data, int count) {
    for(int i = 0; i < count; i++) {
        printf("%s %s %s\n", data[i].timestamp, data[i].level, data[i].message);
    }
}

// function to get count of each log level
void getLogLevelCount(struct LogData *data, int count, int *debugCount, int *infoCount, int *warnCount, int *errorCount) {
    for(int i = 0; i < count; i++) {
        if(strcmp(data[i].level, "DEBUG") == 0) (*debugCount)++;
        else if(strcmp(data[i].level, "INFO") == 0) (*infoCount)++;
        else if(strcmp(data[i].level, "WARN") == 0) (*warnCount)++;
        else if(strcmp(data[i].level, "ERROR") == 0) (*errorCount)++;
    }
}

// main function
int main() {
    struct LogData *data = (struct LogData*) malloc(sizeof(struct LogData) * 100);
    int count = readLogData("application.log", data);

    printf("-----APPLICATION LOG ANALYSIS-----\n");

    printf("\nLog Data:\n");
    printLogData(data, count);

    int debugCount = 0, infoCount = 0, warnCount = 0, errorCount = 0;
    getLogLevelCount(data, count, &debugCount, &infoCount, &warnCount, &errorCount);

    printf("\nLevel Counts:\n");
    printf("DEBUG: %d\n", debugCount);
    printf("INFO: %d\n", infoCount);
    printf("WARN: %d\n", warnCount);
    printf("ERROR: %d\n", errorCount);

    free(data);
    return 0;
}