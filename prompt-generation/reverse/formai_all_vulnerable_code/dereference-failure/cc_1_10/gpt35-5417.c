//FormAI DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_ROWS 100
#define MAX_DATA 100

// Struct for the database
typedef struct Row {
    int id;
    char name[MAX_DATA];
    char email[MAX_DATA];
} Row;

typedef struct Database {
    Row rows[MAX_ROWS];
} Database;

typedef struct Connection {
    FILE *file;
    Database *db;
} Connection;

// Prototypes
void print_row(Row *row);
void print_database(Database *db);
Connection *connect(char *filename);
void close(Connection *conn);
void write_database(Connection *conn);
void load_database(Connection *conn);

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: program <dbfile> <action> [action params]\n");
        exit(1);
    }

    // Connect to the database and load data
    Connection *conn = connect(argv[1]);

    if (strcmp(argv[2], "load") == 0) {
        load_database(conn);
        print_database(conn->db);
    } else if (strcmp(argv[2], "write") == 0) {
        // Add rows to database
        int id = atoi(argv[3]);
        char *name = argv[4];
        char *email = argv[5];

        // Allocate new row and assign data
        Row *new_row = malloc(sizeof(Row));
        new_row->id = id;
        strcpy(new_row->name, name);
        strcpy(new_row->email, email);

        // Add row to database and write to file
        conn->db->rows[id] = *new_row;
        write_database(conn);
    }

    // Close the connection and free memory
    close(conn);

    return 0;
}

// Helper functions
void print_row(Row *row) {
    printf("%d, %s, %s\n", row->id, row->name, row->email);
}

void print_database(Database *db) {
    for (int i = 0; i < MAX_ROWS; i++) {
        Row *row = &db->rows[i];
        if (row->id != 0) {
            print_row(row);
        }
    }
}

// Connect to a database file and return connection
Connection *connect(char *filename) {
    // Allocate memory for connection and database
    Connection *conn = malloc(sizeof(Connection));
    Database *db = malloc(sizeof(Database));

    // Open file for reading and writing
    conn->file = fopen(filename, "r+");
    if (!conn->file) {
        printf("Could not open file: %s\n", filename);
        exit(1);
    }

    // Assign database to connection and return
    conn->db = db;
    return conn;
}

// Close connection and free memory
void close(Connection *conn) {
    // Write to file, close file, and free memory
    write_database(conn);
    fclose(conn->file);
    free(conn->db);
    free(conn);
}

// Write contents of database to file
void write_database(Connection *conn) {
    // Move to beginning of file, write database, and truncate
    fseek(conn->file, 0, SEEK_SET);
    fwrite(conn->db, sizeof(Database), 1, conn->file);
    fflush(conn->file);
    ftruncate(fileno(conn->file), ftell(conn->file));
}

// Load contents of file into database
void load_database(Connection *conn) {
    // Read data from file and assign to database
    fread(conn->db, sizeof(Database), 1, conn->file);
}