//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASSWORD "your_password"
#define DATABASE "your_database"

// Function Prototypes
void connect_to_database(MYSQL *conn);
void create_table(MYSQL *conn);
void insert_data(MYSQL *conn);
void query_data(MYSQL *conn);
void handle_error(MYSQL *conn, const char *message);

int main() {
    MYSQL *conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    connect_to_database(conn);
    create_table(conn);
    insert_data(conn);
    query_data(conn);

    mysql_close(conn);
    return EXIT_SUCCESS;
}

void connect_to_database(MYSQL *conn) {
    if (mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        handle_error(conn, "mysql_real_connect() failed");
    }
    printf("Connected to database successfully.\n");
}

void create_table(MYSQL *conn) {
    const char *create_table_query =
        "CREATE TABLE IF NOT EXISTS Employees ("
        "ID INT PRIMARY KEY AUTO_INCREMENT, "
        "Name VARCHAR(100) NOT NULL, "
        "Age INT NOT NULL, "
        "Position VARCHAR(100))";

    if (mysql_query(conn, create_table_query)) {
        handle_error(conn, "Creating table failed");
    }
    printf("Table Employees created successfully.\n");
}

void insert_data(MYSQL *conn) {
    const char *insert_query_format = 
        "INSERT INTO Employees (Name, Age, Position) VALUES ('%s', %d, '%s')";

    const char *names[] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    int ages[] = {30, 25, 35, 40, 28};
    const char *positions[] = {"Manager", "Developer", "Designer", "Analyst", "Intern"};
    
    for (int i = 0; i < 5; i++) {
        char insert_query[256];
        snprintf(insert_query, sizeof(insert_query), insert_query_format, names[i], ages[i], positions[i]);

        if (mysql_query(conn, insert_query)) {
            handle_error(conn, "Inserting data failed");
        }
    }
    printf("Data inserted successfully.\n");
}

void query_data(MYSQL *conn) {
    const char *query = "SELECT * FROM Employees";
    if (mysql_query(conn, query)) {
        handle_error(conn, "Query execution failed");
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        handle_error(conn, "Getting results failed");
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    
    printf("Employees:\n");
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    
    mysql_free_result(result);
}

void handle_error(MYSQL *conn, const char *message) {
    fprintf(stderr, "%s. Error: %s\n", message, mysql_error(conn));
    mysql_close(conn);
    exit(EXIT_FAILURE);
}