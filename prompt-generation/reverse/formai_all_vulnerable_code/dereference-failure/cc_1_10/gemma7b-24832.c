//Gemma-7B DATASET v1.0 Category: Database querying ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORD_SIZE 1024

typedef struct Record {
    char name[MAX_RECORD_SIZE];
    int age;
    float salary;
    struct Record* next;
} Record;

Record* InsertRecord(Record* head, char* name, int age, float salary) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    newRecord->age = age;
    newRecord->salary = salary;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        head->next = newRecord;
    }

    return head;
}

void PrintRecords(Record* head) {
    while (head) {
        printf("%s, %d, %.2f\n", head->name, head->age, head->salary);
        head = head->next;
    }
}

int main() {
    time_t t = time(NULL);
    srand(t);

    Record* head = NULL;

    // Insert some records
    InsertRecord(head, "John Doe", 25, 50000);
    InsertRecord(head, "Jane Doe", 30, 60000);
    InsertRecord(head, "Peter Pan", 12, 20000);

    // Print the records
    PrintRecords(head);

    return 0;
}