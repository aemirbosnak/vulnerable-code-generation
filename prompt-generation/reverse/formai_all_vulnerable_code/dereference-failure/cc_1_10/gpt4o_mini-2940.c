//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function prototypes
void initialize_db(MYSQL **conn, const char *host, const char *user, const char *password, const char *dbname);
void close_db(MYSQL *conn);
void execute_query(MYSQL *conn, const char *query);
void print_results(MYSQL *conn);
void insert_user(MYSQL *conn, const char *name, const char *email);
void fetch_all_users(MYSQL *conn);

int main() {
    MYSQL *conn = NULL;
    const char *host = "localhost";
    const char *user = "root";
    const char *password = "password";
    const char *dbname = "testdb";

    // Initialize the database connection
    initialize_db(&conn, host, user, password, dbname);

    // Create a user table if it does not exist
    execute_query(conn, "CREATE TABLE IF NOT EXISTS users (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(100), email VARCHAR(100))");

    // Insert some users
    insert_user(conn, "Alice", "alice@example.com");
    insert_user(conn, "Bob", "bob@example.com");

    // Fetch and display all users
    fetch_all_users(conn);

    // Clean up and close the database connection
    close_db(conn);
    return 0;
}

// Function to initialize the database connection
void initialize_db(MYSQL **conn, const char *host, const char *user, const char *password, const char *dbname) {
    *conn = mysql_init(NULL);
    if (*conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }
    
    if (mysql_real_connect(*conn, host, user, password, dbname, 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(*conn);
        exit(EXIT_FAILURE);
    }
}

// Function to close the database connection
void close_db(MYSQL *conn) {
    mysql_close(conn);
}

// Function to execute a query
void execute_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "QUERY ERROR: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }
}

// Function to print results of a query
void print_results(MYSQL *conn) {
    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "STORE RESULT ERROR: %s\n", mysql_error(conn));
        return;
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

// Function to insert a new user
void insert_user(MYSQL *conn, const char *name, const char *email) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO users(name, email) VALUES('%s', '%s')", name, email);
    execute_query(conn, query);
    printf("Inserted user: %s <%s>\n", name, email);
}

// Function to fetch and display all users
void fetch_all_users(MYSQL *conn) {
    execute_query(conn, "SELECT * FROM users");
    printf("Users in the database:\n");
    print_results(conn);
}