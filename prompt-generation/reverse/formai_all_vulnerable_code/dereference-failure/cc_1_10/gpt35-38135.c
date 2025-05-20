//FormAI DATASET v1.0 Category: Database querying ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct for storing data of each record
typedef struct {
    int id;
    char name[50];
    int age;
    char occupation[50];
    char cyborg_implant[50];
} Record;

//function for printing out the records that match the criteria
void printMatchingRecords(Record *records, int count, char *criteria, char *value) {
    int matchCount = 0;
    printf("MATCHING RECORDS:\n");
    for(int i = 0; i < count; i++) {
        Record record = records[i];
        char *fieldValue;
        //determine which field to use for comparison
        if(strcmp(criteria, "id") == 0) {
            fieldValue = malloc(sizeof(char) * (10 + 1));
            sprintf(fieldValue, "%d", record.id);
        } else if(strcmp(criteria, "name") == 0) {
            fieldValue = record.name;
        } else if(strcmp(criteria, "age") == 0) {
            fieldValue = malloc(sizeof(char) * (3 + 1));
            sprintf(fieldValue, "%d", record.age);
        } else if(strcmp(criteria, "occupation") == 0) {
            fieldValue = record.occupation;
        } else if(strcmp(criteria, "cyborg_implant") == 0) {
            fieldValue = record.cyborg_implant;
        } else {
            printf("Invalid criteria.\n");
            return;
        }
        //check if field matches value
        if(strcmp(fieldValue, value) == 0) {
            printf("%d | %s | %d | %s | %s\n", record.id, record.name, record.age, record.occupation, record.cyborg_implant);
            matchCount++;
        }
        //free memory if allocated
        if(strcmp(criteria, "id") == 0 || strcmp(criteria, "age") == 0) {
            free(fieldValue);
        }
    }
    //if no matches were found, print message
    if(matchCount == 0) {
        printf("No matching records found.\n");
    }
}

int main() {
    FILE *file = fopen("cyborg_database.dat", "rb");
    if(file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    //determine number of records in file
    fseek(file, 0L, SEEK_END);
    int fileSize = ftell(file);
    rewind(file);
    int recordCount = fileSize / sizeof(Record);

    //allocate memory for records
    Record *records = malloc(sizeof(Record) * recordCount);

    //read in records from file
    fread(records, sizeof(Record), recordCount, file);

    fclose(file);

    //get user input for querying the database
    char criteria[50];
    char value[50];
    printf("Enter the criteria for the query (id, name, age, occupation, cyborg_implant): ");
    scanf("%s", criteria);
    printf("Enter the value for the query: ");
    scanf("%s", value);

    //convert criteria to lowercase for case-insensitive comparison
    for(int i = 0; i < strlen(criteria); i++) {
        criteria[i] = tolower(criteria[i]);
    }

    //perform query and print matching records
    printMatchingRecords(records, recordCount, criteria, value);

    //free allocated memory
    free(records);

    return 0;
}