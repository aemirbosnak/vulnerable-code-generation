//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 //maximum length of a line in the CSV file
#define MAX_FIELD_LENGTH 100 //maximum length of a single field in the CSV file

//define a struct to store the data from each line of the CSV file
typedef struct record {
    char* fields[10]; //array of pointers to strings representing the fields in a line
    int num_fields; //the number of fields in the line
} Record;

//function to split a line into fields and return the number of fields found
//this function modifies the input string, so it should only be called on a copy of the original string
int split_fields(char* line, char* delimiter, char** fields) {
    int num_fields = 0;
    char* token = strtok(line, delimiter);
    while (token != NULL) {
        fields[num_fields] = token;
        num_fields++;
        token = strtok(NULL, delimiter);
    }
    fields[num_fields] = NULL; //add a null terminator to the end of the array
    return num_fields;
}

//function to read a CSV file
void read_csv(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s.\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    char delimiter[] = ",";
    Record* records = (Record*) malloc(sizeof(Record) * 100); //allocate memory for 100 records
    int num_records = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        //remove the newline character at the end of the line
        line[strcspn(line, "\n")] = 0;

        //split the line into fields
        char* fields[MAX_FIELD_LENGTH];
        int num_fields = split_fields(line, delimiter, fields);

        //store the fields in a new record
        Record record;
        record.num_fields = num_fields;
        for (int i = 0; i < num_fields; i++) {
            record.fields[i] = fields[i];
        }

        //add the record to the array of records
        records[num_records] = record;
        num_records++;
    }

    //print out the records
    printf("Found %d records in file %s:\n", num_records, filename);
    for (int i = 0; i < num_records; i++) {
        printf("Record %d (num fields = %d):\n", i+1, records[i].num_fields);
        for (int j = 0; j < records[i].num_fields; j++) {
            printf("    Field %d: %s\n", j+1, records[i].fields[j]);
        }
    }

    //free allocated memory
    free(records);
    fclose(fp);
}

int main() {
    read_csv("example.csv");
    return 0;
}