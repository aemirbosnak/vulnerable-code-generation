//Falcon-180B DATASET v1.0 Category: Database querying ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LENGTH 1024

typedef struct {
    char *host;
    char *user;
    char *password;
    char *database;
    int port;
} MYSQL_CONNECTION;

int main() {
    // Define database connection details
    MYSQL_CONNECTION connection = {
       .host = "localhost",
       .user = "root",
       .password = "password",
       .database = "testdb",
       .port = 3306
    };

    // Connect to database
    MYSQL *mysql = mysql_init(NULL);
    if (!mysql_real_connect(mysql, connection.host, connection.user, connection.password, connection.database, connection.port, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(mysql));
        return 1;
    }

    // Create table
    char create_table_query[MAX_QUERY_LENGTH];
    snprintf(create_table_query, MAX_QUERY_LENGTH, "CREATE TABLE IF NOT EXISTS users ("
            "id INT AUTO_INCREMENT PRIMARY KEY,"
            "name VARCHAR(255),"
            "email VARCHAR(255))");

    if (mysql_query(mysql, create_table_query)) {
        fprintf(stderr, "Error creating table: %s\n", mysql_error(mysql));
        return 1;
    }

    // Insert sample data
    char insert_data_query[MAX_QUERY_LENGTH];
    snprintf(insert_data_query, MAX_QUERY_LENGTH, "INSERT INTO users (name, email) VALUES ('John Doe', 'johndoe@example.com')");

    if (mysql_query(mysql, insert_data_query)) {
        fprintf(stderr, "Error inserting data: %s\n", mysql_error(mysql));
        return 1;
    }

    // Retrieve data from table
    char select_data_query[MAX_QUERY_LENGTH];
    snprintf(select_data_query, MAX_QUERY_LENGTH, "SELECT * FROM users");

    if (mysql_query(mysql, select_data_query)) {
        fprintf(stderr, "Error selecting data: %s\n", mysql_error(mysql));
        return 1;
    }

    MYSQL_RES *result = mysql_store_result(mysql);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        printf("ID: %s, Name: %s, Email: %s\n", row[0], row[1], row[2]);
    }

    // Close database connection
    mysql_close(mysql);

    return 0;
}