//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "password"
#define DATABASE "testdb"

void executeQuery(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Query Error: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }
}

void printResults(MYSQL_RES *result) {
    MYSQL_ROW row;
    unsigned int num_fields = mysql_num_fields(result);
    
    // Print column names
    MYSQL_FIELD *fields = mysql_fetch_fields(result);
    for (unsigned int i = 0; i < num_fields; i++) {
        printf("%s\t", fields[i].name);
    }
    printf("\n");

    // Print rows
    while ((row = mysql_fetch_row(result))) {
        for (unsigned int i = 0; i < num_fields; i++) {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    printf("\n");
}

void connectToDatabase(MYSQL *conn) {
    if (mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        fprintf(stderr, "Connection Error: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }
}

void closeDatabaseConnection(MYSQL *conn) {
    mysql_close(conn);
}

void createTable(MYSQL *conn) {
    const char *createTableQuery = "CREATE TABLE IF NOT EXISTS Employees ("
                                    "ID INT AUTO_INCREMENT PRIMARY KEY, "
                                    "Name VARCHAR(100), "
                                    "Position VARCHAR(100), "
                                    "Salary DECIMAL(10, 2), "
                                    "JoiningDate DATE);";
    executeQuery(conn, createTableQuery);
}

void insertEmployee(MYSQL *conn, const char *name, const char *position, double salary, const char *joiningDate) {
    char insertQuery[256];
    snprintf(insertQuery, sizeof(insertQuery),
             "INSERT INTO Employees (Name, Position, Salary, JoiningDate) VALUES ('%s', '%s', %.2f, '%s');",
             name, position, salary, joiningDate);
    executeQuery(conn, insertQuery);
}

void selectEmployees(MYSQL *conn) {
    const char *selectQuery = "SELECT * FROM Employees;";
    executeQuery(conn, selectQuery);
    
    MYSQL_RES *result = mysql_store_result(conn);
    if (result) {
        printResults(result);
        mysql_free_result(result);
    } else {
        fprintf(stderr, "Result Error: %s\n", mysql_error(conn));
    }
}

void updateEmployeeSalary(MYSQL *conn, int employeeId, double newSalary) {
    char updateQuery[256];
    snprintf(updateQuery, sizeof(updateQuery),
             "UPDATE Employees SET Salary = %.2f WHERE ID = %d;", newSalary, employeeId);
    executeQuery(conn, updateQuery);
}

void deleteEmployee(MYSQL *conn, int employeeId) {
    char deleteQuery[256];
    snprintf(deleteQuery, sizeof(deleteQuery),
             "DELETE FROM Employees WHERE ID = %d;", employeeId);
    executeQuery(conn, deleteQuery);
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    connectToDatabase(conn);
    createTable(conn);

    insertEmployee(conn, "Alice Johnson", "Software Engineer", 80000.00, "2020-01-15");
    insertEmployee(conn, "Bob Smith", "Product Manager", 90000.00, "2019-03-01");
    insertEmployee(conn, "Charlie Brown", "Designer", 70000.00, "2021-07-23");
    
    printf("Initial Employee List:\n");
    selectEmployees(conn);

    updateEmployeeSalary(conn, 1, 85000.00); // Updating Alice's salary
    printf("After Salary Update:\n");
    selectEmployees(conn);

    deleteEmployee(conn, 2); // Deleting Bob
    printf("After Deleting Bob:\n");
    selectEmployees(conn);

    closeDatabaseConnection(conn);
    return 0;
}