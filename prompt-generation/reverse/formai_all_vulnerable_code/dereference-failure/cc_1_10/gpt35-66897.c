//FormAI DATASET v1.0 Category: Log analysis ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to read the log file
char* readLogFile(char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(0);
    }

    char* logStr = (char*)malloc(sizeof(char));
    logStr[0] = '\0';
    char buffer[1024];
    while (fgets(buffer, 1023, file)) {
        logStr = realloc(logStr, strlen(logStr) + strlen(buffer) + 1);
        strcat(logStr, buffer);
    }

    fclose(file);
    return logStr;
}

// function to count the number of occurrences of a string
int countOccurrences(char* logStr, char* searchStr) {
    int count = 0;
    char* ptr = logStr;
    while ((ptr = strstr(ptr, searchStr)) != NULL) {
        count++;
        ptr++;
    }
    return count;
}

// function to parse the log file and print the results
void parseLogFile(char* fileName) {
    char* logStr = readLogFile(fileName);
    printf("Total number of requests: %d\n", countOccurrences(logStr, "GET /"));
    printf("Total number of successful requests: %d\n", countOccurrences(logStr, "200 OK"));
    printf("Total number of failed requests: %d\n", countOccurrences(logStr, "404 Not Found"));

    // find the average response time
    double totalTime = 0.0;
    int numRequests = 0;
    char* ptr = logStr;
    while ((ptr = strstr(ptr, "GET /")) != NULL) {
        int time;
        sscanf(ptr, "GET /%*s HTTP/1.%*c 200 OK %d", &time);
        totalTime += (double)time;
        numRequests++;
        ptr++;
    }
    if (numRequests > 0) {
        double avgTime = totalTime / numRequests;
        printf("Average response time: %.2lf ms\n", avgTime);
    }

    free(logStr);
}

int main() {
    char fileName[] = "access.log";
    parseLogFile(fileName);
    return 0;
}