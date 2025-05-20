//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "your_password" // Set your MySQL root password
#define DATABASE "testdb"

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

void display_records(MYSQL_RES *result) {
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < mysql_num_fields(result); i++) {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
}

void create_table(MYSQL *conn) {
    const char *query = "CREATE TABLE IF NOT EXISTS Employees (id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(100), age INT, department VARCHAR(100))";
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
}

void insert_record(MYSQL *conn, const char *name, int age, const char *department) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO Employees (name, age, department) VALUES ('%s', %d, '%s')", name, age, department);
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
}

void select_all_records(MYSQL *conn) {
    if (mysql_query(conn, "SELECT * FROM Employees")) {
        finish_with_error(conn);
    }
    
    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        finish_with_error(conn);
    }
    
    display_records(result);
    
    mysql_free_result(result);
}

void delete_record(MYSQL *conn, int id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM Employees WHERE id = %d", id);
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
}

void update_record(MYSQL *conn, int id, const char *name, int age, const char *department) {
    char query[256];
    snprintf(query, sizeof(query), "UPDATE Employees SET name='%s', age=%d, department='%s' WHERE id=%d", name, age, department, id);
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
}

int main(int argc, char **argv) {
    MYSQL *conn = mysql_init(NULL);
    
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }
    
    create_table(conn);
    
    insert_record(conn, "Alice", 30, "HR");
    insert_record(conn, "Bob", 24, "Engineering");
    insert_record(conn, "Charlie", 29, "Marketing");
    
    printf("Records after insertion:\n");
    select_all_records(conn);
    
    printf("\nUpdating Bob's record...\n");
    update_record(conn, 2, "Bob Brown", 25, "Product Management");
    
    printf("Records after update:\n");
    select_all_records(conn);
    
    printf("\nDeleting Alice's record...\n");
    delete_record(conn, 1);
    
    printf("Records after deletion:\n");
    select_all_records(conn);
    
    mysql_close(conn);
    return EXIT_SUCCESS;
}