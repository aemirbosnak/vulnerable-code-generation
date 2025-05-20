//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

#define DB_PATH "/home/user/mydatabase"
#define DB_SIZE 1024 * 1024 * 10
#define MAX_RECORDS 1000
#define RECORD_SIZE 512

typedef struct record {
    char name[50];
    char email[50];
    int age;
} record_t;

typedef struct database {
    char *data;
    size_t size;
    size_t capacity;
} database_t;

database_t *create_database(void);
void insert_record(database_t *db, record_t *record);
record_t *search_record(database_t *db, char *name);
void delete_record(database_t *db, char *name);
void update_record(database_t *db, record_t *record);
void print_database(database_t *db);

int main(void) {
    database_t *db = create_database();

    insert_record(db, (record_t *)malloc(sizeof(record_t)));
    insert_record(db, (record_t *)malloc(sizeof(record_t)));
    insert_record(db, (record_t *)malloc(sizeof(record_t)));

    search_record(db, "John Doe");
    search_record(db, "Jane Doe");

    delete_record(db, "John Doe");

    update_record(db, (record_t *)malloc(sizeof(record_t)));

    print_database(db);

    free(db->data);
    free(db);

    return 0;
}

database_t *create_database(void) {
    database_t *db = (database_t *)malloc(sizeof(database_t));
    db->data = (char *)mmap(NULL, DB_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    db->size = DB_SIZE;
    db->capacity = DB_SIZE;

    return db;
}

void insert_record(database_t *db, record_t *record) {
    char *ptr = db->data + db->size;
    db->size += RECORD_SIZE;
    memcpy(ptr, record, RECORD_SIZE);
}

record_t *search_record(database_t *db, char *name) {
    char *ptr = db->data;
    char *found = NULL;

    while (ptr < db->data + db->size) {
        if (strcmp(ptr + 1, name) == 0) {
            found = ptr;
            break;
        }
        ptr += RECORD_SIZE;
    }

    return found;
}

void delete_record(database_t *db, char *name) {
    char *ptr = db->data;
    char *found = NULL;

    while (ptr < db->data + db->size) {
        if (strcmp(ptr + 1, name) == 0) {
            found = ptr;
            break;
        }
        ptr += RECORD_SIZE;
    }

    if (found != NULL) {
        memmove(ptr, ptr + RECORD_SIZE, db->size - (ptr - db->data));
        db->size -= RECORD_SIZE;
    }
}

void update_record(database_t *db, record_t *record) {
    char *ptr = db->data;
    char *found = NULL;

    while (ptr < db->data + db->size) {
        if (strcmp(ptr + 1, record->name) == 0) {
            found = ptr;
            break;
        }
        ptr += RECORD_SIZE;
    }

    if (found != NULL) {
        memcpy(ptr, record, RECORD_SIZE);
    }
}

void print_database(database_t *db) {
    char *ptr = db->data;

    printf("Database contains %ld records\n", (long)db->size);

    while (ptr < db->data + db->size) {
        printf("%s %s %d\n", ptr + 1, ptr + 51, *(int *)(ptr + 53));
        ptr += RECORD_SIZE;
    }
}