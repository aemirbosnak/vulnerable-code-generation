//FormAI DATASET v1.0 Category: Database querying ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 100
#define MAX_ROWS 1000

struct Person {
    int id;
    char name[MAX_DATA];
    int age;
};

struct Database {
    struct Person rows[MAX_ROWS];
};

struct Connection {
    FILE *file;
    struct Database *db;
};

void Database_load(struct Connection *conn) {
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) {
        printf("Failed to load database.\n");
        exit(1);
    }
}

struct Connection *Database_open(const char *filename, char mode) {
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) {
        printf("Memory error.\n");
        exit(1);
    }

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) {
        printf("Memory error.\n");
        exit(1);
    }

    if(mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");
        if(conn->file) {
            Database_load(conn);
        }
    }

    if(!conn->file) {
        printf("Failed to open the file.\n");
        exit(1);
    }

    return conn;
}

void Database_close(struct Connection *conn) {
    if(conn) {
        if(conn->file) fclose(conn->file);
        if(conn->db) free(conn->db);
        free(conn);
    }
}

void Database_write(struct Connection *conn) {
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) {
        printf("Failed to write database.\n");
        exit(1);
    }

    rc = fflush(conn->file);
    if(rc == -1) {
        printf("Cannot flush database.\n");
        exit(1);
    }
}

void Database_create(struct Connection *conn) {
    int i;

    for(i = 0; i < MAX_ROWS; i++) {
        struct Person person = {.id = i, .name = " ", .age = 0};
        conn->db->rows[i] = person;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, int age) {
    struct Person *person = &conn->db->rows[id];
    if(person) {
        strncpy(person->name, name, MAX_DATA);
        person->name[MAX_DATA - 1] = '\0';
        person->age = age;
    }
}

void Database_get(struct Connection *conn, int id) {
    struct Person *person = &conn->db->rows[id];
    if(person->name[0] != '\0') {
        printf("ID: %d, Name: %s, Age: %d\n", person->id, person->name, person->age);
    } else {
        printf("No record found with ID: %d\n", id);
    }
}

void Database_delete(struct Connection *conn, int id) {
    struct Person person = {.id = id, .name = "", .age = 0};
    conn->db->rows[id] = person;
}

int main() {
    struct Connection *conn = Database_open("test.txt", 'c');
    Database_create(conn);

    Database_set(conn, 0, "John", 30);
    Database_set(conn, 1, "Jane", 25);
    Database_set(conn, 2, "Bob", 40);
    Database_set(conn, 3, "Mary", 35);

    Database_write(conn);

    Database_close(conn);

    conn = Database_open("test.txt", 'r');

    Database_get(conn, 0);
    Database_get(conn, 2);
    Database_get(conn, 5);

    Database_delete(conn, 1);
    Database_set(conn, 2, "Tom", 45);

    Database_write(conn);

    Database_close(conn);

    return 0;
}