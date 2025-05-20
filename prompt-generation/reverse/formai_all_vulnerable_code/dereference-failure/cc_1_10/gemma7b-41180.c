//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECOVERY_SIZE 1024

typedef struct DataRecord {
    char *name;
    int age;
    struct DataRecord *next;
} DataRecord;

DataRecord *recoverData(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    DataRecord *head = NULL;
    DataRecord *tail = NULL;

    char line[MAX_RECOVERY_SIZE];
    while (fgets(line, MAX_RECOVERY_SIZE, fp) != NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));

        DataRecord *newRecord = malloc(sizeof(DataRecord));
        newRecord->name = strdup(name);
        newRecord->age = age;
        newRecord->next = NULL;

        if (head == NULL) {
            head = newRecord;
            tail = newRecord;
        } else {
            tail->next = newRecord;
            tail = newRecord;
        }
    }

    fclose(fp);
    return head;
}

int main() {
    DataRecord *data = recoverData("data.txt");

    if (data != NULL) {
        for (DataRecord *current = data; current; current = current->next) {
            printf("Name: %s, Age: %d\n", current->name, current->age);
        }
    } else {
        printf("Error recovering data.\n");
    }

    return 0;
}