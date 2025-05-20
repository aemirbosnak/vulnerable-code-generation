//FormAI DATASET v1.0 Category: Log analysis ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100 // Maximum length of log line
#define MAX_LOG_FILES 10 // Maximum number of log files to read
#define MAX_QUERY_LENGTH 50 // Maximum length of query string
#define MAX_RESULTS 100 // Maximum number of search results
#define MAX_CONFIG_PARAMS 3 // Maximum number of configuration parameters

struct LogLine{
    char date[11];
    char time[9];
    char level[6];
    char message[MAX_LINE_LENGTH-26];
};
typedef struct LogLine LogLine;

void getConfig(char* configFile, int* params){
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;

    fp = fopen(configFile, "r");
    if(fp == NULL){
        printf("Error opening configuration file %s\n", configFile);
        exit(EXIT_FAILURE);
    }

    while((read = getline(&line, &len, fp)) != -1){
        if(count == MAX_CONFIG_PARAMS){
            break;
        }
        params[count++] = atoi(line);
    }

    if(count != MAX_CONFIG_PARAMS){
        printf("Configuration file should contain %d integer parameters\n", MAX_CONFIG_PARAMS);
        exit(EXIT_FAILURE);
    }

    fclose(fp);
}

int getLogs(char* logFilePaths[], int numPaths, LogLine** logLines){
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;
    int i;

    for(i=0; i<numPaths; i++){
        fp = fopen(logFilePaths[i], "r");
        if(fp == NULL){
            printf("Error opening file %s\n", logFilePaths[i]);
            continue;
        }

        while((read = getline(&line, &len, fp)) != -1){
            if(count == MAX_RESULTS){
                break;
            }

            LogLine* logLine = (LogLine*)malloc(sizeof(LogLine));
            strcpy(logLine->date, strtok(line, " "));
            strcpy(logLine->time, strtok(NULL, " "));
            strcpy(logLine->level, strtok(NULL, " "));
            strcpy(logLine->message, strtok(NULL, "\n"));

            logLines[count++] = logLine;
        }

        fclose(fp);
    }

    return count;
}

void searchLogs(char* query, LogLine** logLines, int numLines){
    int i, j;
    for(i=0; i<numLines; i++){
        if(strstr(logLines[i]->message, query) != NULL){
            printf("%s %s %s %s\n", logLines[i]->date, logLines[i]->time,
                                    logLines[i]->level, logLines[i]->message);
        }
    }
}

int main(int argc, char* argv[]){
    if(argc != 4){
        printf("Usage: ./loganalysis <configFile> <query> <logFilePath1> <logFilePath2> ...\n");
        return 0;
    }

    int configParams[MAX_CONFIG_PARAMS];
    getConfig(argv[1], configParams);

    char* query = argv[2];
    if(strlen(query) > MAX_QUERY_LENGTH){
        printf("Query length should be less than or equal to %d\n", MAX_QUERY_LENGTH);
        return 0;
    }

    char* logFilePaths[MAX_LOG_FILES];
    int numLogFiles = argc - 3;
    if(numLogFiles > MAX_LOG_FILES){
        printf("Number of log files should be less than or equal to %d\n", MAX_LOG_FILES);
        return 0;
    }

    int i;
    for(i=0; i<numLogFiles; i++){
        logFilePaths[i] = argv[i+3];
    }

    LogLine* logLines[MAX_RESULTS];
    int numLogLines = getLogs(logFilePaths, numLogFiles, logLines);
    searchLogs(query, logLines, numLogLines);
    
    return 0;
}