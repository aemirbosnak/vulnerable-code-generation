//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 64
#define MAX_FIELDS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    char address[MAX_LINE_LENGTH];
    char phone[MAX_LINE_LENGTH];
    char email[MAX_LINE_LENGTH];
    char city[MAX_NAME_LENGTH];
    char state[MAX_NAME_LENGTH];
    char zip[MAX_NAME_LENGTH];
} ResumeRecord;

void parseLine(char *line, ResumeRecord *record) {
    char *token;
    int fieldIndex = 0;

    token = strtok(line, ",");
    strcpy(record->name, token);

    token = strtok(NULL, ",");
    record->age = atoi(token);

    token = strtok(NULL, ",");
    record->salary = atof(token);

    int remainingFields = MAX_FIELDS - 3;
    while (token != NULL && remainingFields > 0) {
        fieldIndex++;

        switch (fieldIndex) {
            case 4:
                strcpy(record->address, token);
                break;
            case 5:
                strcpy(record->phone, token);
                break;
            case 6:
                strcpy(record->email, token);
                break;
            case 7:
                strcpy(record->city, token);
                break;
            case 8:
                strcpy(record->state, token);
                break;
            case 9:
                strcpy(record->zip, token);
                break;
            default:
                // Ignore extra fields
                break;
        }

        token = strtok(NULL, ",");
        remainingFields--;
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    ResumeRecord record;
    int numRecords = 0;

    FILE *resumeFile = fopen("resume.csv", "r");

    if (resumeFile == NULL) {
        fprintf(stderr, "Error: Could not open resume file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, resumeFile)) {
        parseLine(line, &record);
        printf("Record %d:\n", numRecords + 1);
        printf("Name: %s\n", record.name);
        printf("Age: %d\n", record.age);
        printf("Salary: %.2f\n", record.salary);
        printf("Address: %s\n", record.address);
        printf("Phone: %s\n", record.phone);
        printf("Email: %s\n", record.email);
        printf("City: %s\n", record.city);
        printf("State: %s\n", record.state);
        printf("Zip: %s\n\n", record.zip);
        numRecords++;
    }

    fclose(resumeFile);

    return 0;
}