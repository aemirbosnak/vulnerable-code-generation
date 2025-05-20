//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECOVERY_Attempts 5

typedef struct Record {
    char name[20];
    int age;
    struct Record* next;
} Record;

Record* recover_data(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    Record* head = NULL;
    Record* current = NULL;

    char line[200];
    int attempts = 0;

    while (fgets(line, 200, file) != NULL) {
        if (attempts >= MAX_RECOVERY_Attempts) {
            fclose(file);
            return NULL;
        }

        char* name = strtok(line, ",");
        int age = atoi(strtok(name, ","));

        Record* new_record = malloc(sizeof(Record));
        strcpy(new_record->name, name);
        new_record->age = age;
        new_record->next = NULL;

        if (head == NULL) {
            head = new_record;
        } else {
            current->next = new_record;
        }

        current = new_record;
        attempts++;
    }

    fclose(file);
    return head;
}

int main() {
    char* filename = "data.txt";
    Record* head = recover_data(filename);

    if (head != NULL) {
        for (Record* current = head; current; current = current->next) {
            printf("%s is %d years old.\n", current->name, current->age);
        }
    } else {
        printf("Error recovering data.\n");
    }

    return 0;
}