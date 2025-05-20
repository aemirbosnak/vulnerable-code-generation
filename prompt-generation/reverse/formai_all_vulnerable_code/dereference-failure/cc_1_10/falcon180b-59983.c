//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 5
#define MAX_FIELD_SIZE 50

typedef struct {
    char data[MAX_RECORDS][MAX_FIELD_SIZE];
    int num_fields;
    int num_records;
} Database;

void create_database(Database *db) {
    db->num_fields = 0;
    db->num_records = 0;
}

void add_record(Database *db, int num_fields, char **fields) {
    int i;
    for (i = 0; i < num_fields; i++) {
        strncpy(db->data[db->num_records][i], fields[i], MAX_FIELD_SIZE);
    }
    db->num_records++;
}

void display_record(Database *db, int record_num) {
    int i;
    for (i = 0; i < db->num_fields; i++) {
        printf("%s\t", db->data[record_num][i]);
    }
    printf("\n");
}

void search_record(Database *db, char *search_string, int field_num) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->data[i][field_num], search_string) == 0) {
            display_record(db, i);
        }
    }
}

int main() {
    Database db;
    create_database(&db);
    add_record(&db, 2, (char *[]) {"John", "Doe"});
    add_record(&db, 3, (char *[]) {"Jane", "Doe", "25"});
    search_record(&db, "Doe", 0);
    search_record(&db, "25", 2);
    return 0;
}