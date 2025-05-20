//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_VALUE_SIZE 256
#define MAX_NUM_KEY_VALUES 1000

// Struct to hold a key-value pair
typedef struct {
    char key[MAX_KEY_VALUE_SIZE];
    char value[MAX_KEY_VALUE_SIZE];
} KeyValue;

// Struct to hold the resume data
typedef struct {
    int numKeyValues;
    KeyValue keyValues[MAX_NUM_KEY_VALUES];
} ResumeData;

// Function prototypes
void parseLine(char* line, int keyValueCount, KeyValue keyValues[MAX_NUM_KEY_VALUES]);
void printResume(ResumeData* resumeData);

int main() {
    FILE* resumeFile = fopen("resume.txt", "r");
    if (resumeFile == NULL) {
        printf("Error: Could not open resume file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int keyValueCount = 0;
    ResumeData resumeData = {0};

    // Read in the resume data
    while (fgets(line, MAX_LINE_LENGTH, resumeFile)!= NULL) {
        parseLine(line, keyValueCount, resumeData.keyValues);
        keyValueCount++;
    }

    // Print the parsed resume data
    printResume(&resumeData);

    fclose(resumeFile);
    return 0;
}

void parseLine(char* line, int keyValueCount, KeyValue keyValues[MAX_NUM_KEY_VALUES]) {
    char* token = strtok(line, ":");
    while (token!= NULL && keyValueCount < MAX_NUM_KEY_VALUES) {
        strcpy(keyValues[keyValueCount].key, token);
        token = strtok(NULL, ":");
        strcpy(keyValues[keyValueCount].value, token);
        keyValueCount++;
    }
}

void printResume(ResumeData* resumeData) {
    printf("Name: %s\n", resumeData->keyValues[0].value);
    printf("Email: %s\n", resumeData->keyValues[1].value);
    printf("Phone: %s\n", resumeData->keyValues[2].value);
    printf("Address: %s\n", resumeData->keyValues[3].value);
    printf("Education: %s\n", resumeData->keyValues[4].value);
    printf("Experience: %s\n", resumeData->keyValues[5].value);
}