//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "your_username"
#define PASSWORD "your_password"
#define DATABASE "your_database"
#define MAX_QUERY_LENGTH 256
#define MAX_RESULT_LENGTH 1024

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

void connect_to_database(MYSQL **conn) {
    *conn = mysql_init(NULL);
    if (*conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }

    if (mysql_real_connect(*conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        finish_with_error(*conn);
    }
}

void query_database(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        finish_with_error(conn);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}

void create_table(MYSQL *conn) {
    const char *create_table_query =
        "CREATE TABLE IF NOT EXISTS Employees ("
        "ID INT PRIMARY KEY AUTO_INCREMENT, "
        "Name VARCHAR(100), "
        "Position VARCHAR(100), "
        "Salary DECIMAL(10, 2))";

    query_database(conn, create_table_query);
    printf("Table 'Employees' created successfully.\n");
}

void insert_employee(MYSQL *conn, const char *name, const char *position, double salary) {
    char query[MAX_QUERY_LENGTH];
    snprintf(query, sizeof(query), 
             "INSERT INTO Employees (Name, Position, Salary) VALUES ('%s', '%s', %.2f)",
             name, position, salary);
    query_database(conn, query);
    printf("Inserted employee %s with position %s and salary %.2f\n", name, position, salary);
}

void fetch_employees(MYSQL *conn) {
    const char *query = "SELECT * FROM Employees";
    printf("\nEmployee List:\n");
    query_database(conn, query);
}

void delete_employee(MYSQL *conn, int id) {
    char query[MAX_QUERY_LENGTH];
    snprintf(query, sizeof(query), "DELETE FROM Employees WHERE ID = %d", id);
    query_database(conn, query);
    printf("Deleted employee with ID %d\n", id);
}

int main() {
    MYSQL *conn;
    connect_to_database(&conn);

    // Step 1: Create the Employees table
    create_table(conn);
   
    // Step 2: Insert employees
    insert_employee(conn, "John Doe", "Software Developer", 50000.00);
    insert_employee(conn, "Jane Smith", "Project Manager", 75000.00);
    insert_employee(conn, "Emily Davis", "Analyst", 65000.00);

    // Step 3: Fetch all employees
    fetch_employees(conn);
    
    // Step 4: Delete an employee
    delete_employee(conn, 1);

    // Step 5: Fetch all employees again
    fetch_employees(conn);
    
    mysql_close(conn);
    return EXIT_SUCCESS;
}