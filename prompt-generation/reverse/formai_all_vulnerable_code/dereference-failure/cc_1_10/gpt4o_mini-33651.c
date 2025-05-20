//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "password" // Update with your MySQL root password
#define DATABASE "test_db"

// Function prototypes
void connect_database(MYSQL **conn);
void disconnect_database(MYSQL *conn);
void create_table(MYSQL *conn);
void insert_data(MYSQL *conn);
void query_data(MYSQL *conn);
void clean_up(MYSQL *conn);

int main() {
    MYSQL *conn = NULL;
    
    // Connect to the database
    connect_database(&conn);

    // Create a new table
    create_table(conn);

    // Insert data into the table
    insert_data(conn);

    // Query and display data
    query_data(conn);

    // Cleanup and disconnect from the database
    clean_up(conn);
    
    return 0;
}

void connect_database(MYSQL **conn) {
    *conn = mysql_init(NULL);
    if (*conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }

    if (mysql_real_connect(*conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(*conn);
        exit(EXIT_FAILURE);
    }
    printf("Connected to database successfully.\n");
}

void disconnect_database(MYSQL *conn) {
    mysql_close(conn);
    printf("Disconnected from database.\n");
}

void create_table(MYSQL *conn) {
    const char *create_table_query = "CREATE TABLE IF NOT EXISTS Employees ("
                                      "ID INT AUTO_INCREMENT PRIMARY KEY, "
                                      "FirstName VARCHAR(255) NOT NULL, "
                                      "LastName VARCHAR(255) NOT NULL, "
                                      "Position VARCHAR(255) NOT NULL, "
                                      "Salary DECIMAL(10, 2) NOT NULL);";
    
    if (mysql_query(conn, create_table_query)) {
        fprintf(stderr, "CREATE TABLE failed. Error: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }
    printf("Table 'Employees' created successfully.\n");
}

void insert_data(MYSQL *conn) {
    const char *insert_query = "INSERT INTO Employees (FirstName, LastName, Position, Salary) VALUES "
                               "('John', 'Doe', 'Developer', 75000), "
                               "('Jane', 'Smith', 'Manager', 85000), "
                               "('Robert', 'Brown', 'Designer', 65000);";

    if (mysql_query(conn, insert_query)) {
        fprintf(stderr, "INSERT failed. Error: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }
    printf("Data inserted into 'Employees' table successfully.\n");
}

void query_data(MYSQL *conn) {
    if (mysql_query(conn, "SELECT * FROM Employees")) {
        fprintf(stderr, "SELECT failed. Error: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "mysql_store_result() failed. Error: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    printf("\nEmployees List:\n");
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(result);
}

void clean_up(MYSQL *conn) {
    disconnect_database(conn);
    printf("Program completed. Exiting...\n");
}