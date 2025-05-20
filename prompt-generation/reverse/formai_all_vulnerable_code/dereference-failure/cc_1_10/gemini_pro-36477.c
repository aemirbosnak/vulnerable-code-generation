//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 10
#define MAX_FIELD_LEN 50

typedef struct {
    char *name;
    int type;
    int length;
} Field;

typedef struct {
    Field fields[MAX_FIELDS];
    int num_fields;
} Schema;

typedef struct {
    char *data[MAX_FIELDS];
    int id;
} Record;

typedef struct {
    Schema schema;
    Record records[MAX_RECORDS];
    int num_records;
} Database;

Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->num_records = 0;
    return db;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        for (int j = 0; j < db->schema.num_fields; j++) {
            free(db->records[i].data[j]);
        }
    }
    free(db);
}

int add_field(Database *db, char *name, int type, int length) {
    if (db->schema.num_fields == MAX_FIELDS) {
        return -1;
    }

    db->schema.fields[db->schema.num_fields].name = malloc(strlen(name) + 1);
    strcpy(db->schema.fields[db->schema.num_fields].name, name);
    db->schema.fields[db->schema.num_fields].type = type;
    db->schema.fields[db->schema.num_fields].length = length;
    db->schema.num_fields++;

    return 0;
}

int add_record(Database *db, char **data) {
    if (db->num_records == MAX_RECORDS) {
        return -1;
    }

    for (int i = 0; i < db->schema.num_fields; i++) {
        db->records[db->num_records].data[i] = malloc(strlen(data[i]) + 1);
        strcpy(db->records[db->num_records].data[i], data[i]);
    }
    db->records[db->num_records].id = db->num_records;
    db->num_records++;

    return 0;
}

int find_record(Database *db, char *field_name, char *value) {
    for (int i = 0; i < db->schema.num_fields; i++) {
        if (strcmp(db->schema.fields[i].name, field_name) == 0) {
            for (int j = 0; j < db->num_records; j++) {
                if (strcmp(db->records[j].data[i], value) == 0) {
                    return j;
                }
            }
        }
    }

    return -1;
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        for (int j = 0; j < db->schema.num_fields; j++) {
            printf("%s: %s\t", db->schema.fields[j].name, db->records[i].data[j]);
        }
        printf("\n");
    }
}

int main() {
    Database *db = create_database();

    add_field(db, "name", 1, 50);
    add_field(db, "age", 2, 3);
    add_field(db, "city", 1, 50);

    char *data1[] = {"John Doe", "30", "New York"};
    add_record(db, data1);

    char *data2[] = {"Jane Doe", "25", "Los Angeles"};
    add_record(db, data2);

    char *data3[] = {"Bob Smith", "40", "Chicago"};
    add_record(db, data3);

    print_database(db);

    int index = find_record(db, "name", "John Doe");
    if (index != -1) {
        printf("Found record with name John Doe: %d\n", index);
    } else {
        printf("Record with name John Doe not found\n");
    }

    destroy_database(db);

    return 0;
}