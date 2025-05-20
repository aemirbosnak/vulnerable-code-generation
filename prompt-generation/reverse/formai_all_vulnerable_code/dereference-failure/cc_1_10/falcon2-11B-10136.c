//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

struct database {
    int num_records;
    char** records;
};

void create_db() {
    struct database db = {0, NULL};
    return;
}

void add_record(struct database* db, int record_id, char* data, int time) {
    if (db->num_records >= 100) {
        printf("Database is full.\n");
        return;
    }

    db->records[db->num_records] = (char*)malloc(sizeof(char) * 100);
    if (db->records[db->num_records] == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(db->records[db->num_records], "");
    db->num_records++;

    printf("Record added successfully.\n");
    return;
}

void update_record(struct database* db, int record_id, char* new_data) {
    if (db->num_records <= 0) {
        printf("Database is empty.\n");
        return;
    }

    if (record_id >= db->num_records) {
        printf("Invalid record ID.\n");
        return;
    }

    if (db->records[record_id] == NULL) {
        printf("Record not found.\n");
        return;
    }

    strcpy(db->records[record_id], new_data);

    printf("Record updated successfully.\n");
    return;
}

void delete_record(struct database* db, int record_id) {
    if (db->num_records <= 0) {
        printf("Database is empty.\n");
        return;
    }

    if (record_id >= db->num_records) {
        printf("Invalid record ID.\n");
        return;
    }

    if (db->records[record_id] == NULL) {
        printf("Record not found.\n");
        return;
    }

    free(db->records[record_id]);
    db->records[record_id] = NULL;
    db->num_records--;

    printf("Record deleted successfully.\n");
    return;
}

int main() {
    struct database db = {0, NULL};
    create_db(&db);

    add_record(&db, 1, "Hello", 10);
    add_record(&db, 2, "World", 20);
    update_record(&db, 1, "Hi");
    delete_record(&db, 1);

    return 0;
}