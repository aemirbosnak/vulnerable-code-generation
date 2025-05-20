//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_QUERY_LENGTH 256

// Function to handle sqlite errors
void handle_error(int rc, sqlite3 *db) {
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }
}

// Function to create a table
void create_table(sqlite3 *db) {
    char *err_msg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS Students ("
                      "Id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "Name TEXT NOT NULL, "
                      "Age INTEGER NOT NULL, "
                      "Grade TEXT NOT NULL);";
    
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    handle_error(rc, db);
}

// Function to insert a student
void insert_student(sqlite3 *db, const char *name, int age, const char *grade) {
    char sql[MAX_QUERY_LENGTH];
    snprintf(sql, sizeof(sql), "INSERT INTO Students (Name, Age, Grade) VALUES ('%s', %d, '%s');", name, age, grade);
    
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    handle_error(rc, db);
}

// Function to display all students
void display_students(sqlite3 *db) {
    const char *sql = "SELECT * FROM Students;";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    handle_error(rc, db);

    printf("Students List:\n");
    printf("ID\tName\tAge\tGrade\n");
    printf("-----------------------------\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        const unsigned char *grade = sqlite3_column_text(stmt, 3);
        printf("%d\t%s\t%d\t%s\n", id, name, age, grade);
    }

    sqlite3_finalize(stmt);
}

// Function to query a student by ID
void query_student_by_id(sqlite3 *db, int id) {
    const char *sql = "SELECT * FROM Students WHERE Id = ?;";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    handle_error(rc, db);

    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int student_id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        const unsigned char *grade = sqlite3_column_text(stmt, 3);
        printf("Student Found: ID=%d, Name=%s, Age=%d, Grade=%s\n", student_id, name, age, grade);
    } else {
        printf("No student found with ID %d.\n", id);
    }

    sqlite3_finalize(stmt);
}

// Main function
int main(int argc, char *argv[]) {
    sqlite3 *db;
    int rc = sqlite3_open("school.db", &db);
    handle_error(rc, db);

    create_table(db);

    // Insert some dummy students
    insert_student(db, "Alice", 20, "A");
    insert_student(db, "Bob", 22, "B");
    insert_student(db, "Charlie", 19, "C");

    // Display all students
    display_students(db);

    // Query a specific student by ID
    if (argc == 2) {
        int student_id = atoi(argv[1]);
        query_student_by_id(db, student_id);
    } else {
        printf("Usage: %s <student_id>\n", argv[0]);
    }

    // Close the database
    sqlite3_close(db);
    return 0;
}