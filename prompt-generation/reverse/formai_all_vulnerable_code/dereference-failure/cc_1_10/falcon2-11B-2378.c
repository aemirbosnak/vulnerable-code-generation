//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    char* name;
    int age;
    char* address;
} Person;

typedef struct {
    Person* person;
    int row;
} CSVRow;

void* read_csv_row(void* arg) {
    CSVRow* row = (CSVRow*)arg;
    FILE* csv_file = fopen("data.csv", "r");
    if (csv_file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }

    char line[100];
    int field_count = 0;
    Person person;
    while (fgets(line, sizeof(line), csv_file)!= NULL) {
        char* fields[3];
        char* field;
        char* field_ptr;

        field_ptr = strtok(line, ",");
        person.name = field_ptr;
        field_ptr = strtok(NULL, ",");
        person.age = atoi(field_ptr);
        field_ptr = strtok(NULL, ",");
        person.address = field_ptr;

        fields[0] = person.name;
        fields[1] = person.age;
        fields[2] = person.address;

        row->person = &person;
        row->row = field_count;

        field_count++;
    }

    fclose(csv_file);
    return NULL;
}

void print_results(void) {
    int thread_count = 10;
    pthread_t threads[thread_count];
    CSVRow* rows[thread_count];
    int i;

    for (i = 0; i < thread_count; i++) {
        rows[i] = malloc(sizeof(CSVRow));
        rows[i]->row = i;
        pthread_create(&threads[i], NULL, read_csv_row, rows[i]);
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
        free(rows[i]);
    }

    printf("Results:\n");
    for (i = 0; i < thread_count; i++) {
        CSVRow* row = rows[i];
        printf("Row %d:\n", row->row);
        printf("Name: %s\n", row->person->name);
        printf("Age: %d\n", row->person->age);
        printf("Address: %s\n", row->person->address);
        printf("\n");
    }
}

int main() {
    print_results();
    return 0;
}