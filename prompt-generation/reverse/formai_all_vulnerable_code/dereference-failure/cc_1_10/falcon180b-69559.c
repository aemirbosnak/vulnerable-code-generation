//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50
#define DELIM ","

typedef struct {
    char *fields[MAX_FIELD_SIZE];
    int num_fields;
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void create_database(Database *db) {
    db->records = (Record *)malloc(MAX_RECORDS * sizeof(Record));
    db->num_records = 0;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        for (int j = 0; j < db->records[i].num_fields; j++) {
            free(db->records[i].fields[j]);
        }
        free(db->records[i].fields);
    }
    free(db->records);
}

void add_record(Database *db, char *line) {
    Record record;
    char *token = strtok(line, DELIM);
    int num_fields = 0;

    while (token!= NULL) {
        if (num_fields >= MAX_FIELD_SIZE) {
            printf("Error: Too many fields in record.\n");
            return;
        }
        record.fields[num_fields] = strdup(token);
        num_fields++;
        token = strtok(NULL, DELIM);
    }

    record.num_fields = num_fields;
    db->records[db->num_records++] = record;
}

void print_record(Record record) {
    for (int i = 0; i < record.num_fields; i++) {
        printf("%s ", record.fields[i]);
    }
    printf("\n");
}

void print_database(Database db) {
    for (int i = 0; i < db.num_records; i++) {
        print_record(db.records[i]);
    }
}

int main() {
    Database db;
    create_database(&db);

    FILE *fp = fopen("data.csv", "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char line[1024];

    while (fgets(line, sizeof(line), fp)!= NULL) {
        add_record(&db, line);
    }

    fclose(fp);

    print_database(db);

    destroy_database(&db);

    return 0;
}