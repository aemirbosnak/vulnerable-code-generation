//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *fields[MAX_FIELD_SIZE];
    int num_fields;
} Record;

typedef struct {
    Record *records;
    int num_records;
    char *filename;
} Database;

void read_database(Database *db, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open database file %s\n", filename);
        exit(1);
    }

    db->records = malloc(MAX_RECORDS * sizeof(Record));
    db->num_records = 0;

    char line[MAX_FIELD_SIZE];
    while (fgets(line, MAX_FIELD_SIZE, fp)!= NULL) {
        Record *rec = db->records + db->num_records;
        rec->num_fields = 0;

        char *token = strtok(line, ",");
        while (token!= NULL) {
            if (rec->num_fields >= MAX_FIELD_SIZE) {
                printf("Error: too many fields in record\n");
                exit(1);
            }
            rec->fields[rec->num_fields] = strdup(token);
            rec->num_fields++;

            token = strtok(NULL, ",");
        }

        db->num_records++;
    }

    fclose(fp);
}

void write_database(Database *db, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open database file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < db->num_records; i++) {
        Record *rec = db->records + i;
        for (int j = 0; j < rec->num_fields; j++) {
            fprintf(fp, "%s,", rec->fields[j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        Record *rec = db->records + i;
        for (int j = 0; j < rec->num_fields; j++) {
            printf("%s ", rec->fields[j]);
        }
        printf("\n");
    }
}

void free_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        for (int j = 0; j < db->records[i].num_fields; j++) {
            free(db->records[i].fields[j]);
        }
        free(db->records[i].fields);
    }
    free(db->records);
}

int main() {
    Database db;
    read_database(&db, "database.txt");

    printf("Original database:\n");
    print_database(&db);

    Record *rec = db.records + 2;
    strcpy(rec->fields[2], "updated");

    printf("\nAfter updating record 3:\n");
    print_database(&db);

    write_database(&db, "updated_database.txt");

    printf("\nUpdated database saved to updated_database.txt\n");

    free_database(&db);
    return 0;
}