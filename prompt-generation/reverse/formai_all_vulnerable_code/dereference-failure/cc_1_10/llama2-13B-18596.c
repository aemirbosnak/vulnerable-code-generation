//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 20
#define MAX_AGE 100

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} record_t;

record_t records[MAX_RECORDS];
int record_count = 0;

void add_record(char *name, int age) {
    record_t *new_record = (record_t *) malloc(sizeof(record_t));
    strcpy(new_record->name, name);
    new_record->age = age;
    records[record_count++] = *new_record;
}

int get_record_count() {
    return record_count;
}

record_t *get_record(int index) {
    return &records[index];
}

void print_records() {
    int i;
    for (i = 0; i < record_count; i++) {
        printf("%d: %s %d\n", i, records[i].name, records[i].age);
    }
}

int main() {
    srand(time(NULL));

    add_record("Alice", rand() % MAX_AGE);
    add_record("Bob", rand() % MAX_AGE);
    add_record("Charlie", rand() % MAX_AGE);

    print_records();

    return 0;
}