//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function prototypes
void connect_to_database(MYSQL *conn);
void create_table(MYSQL *conn);
void insert_data(MYSQL *conn);
void query_data(MYSQL *conn);
void close_connection(MYSQL *conn);

int main() {
    MYSQL *conn = mysql_init(NULL);
    
    // Connect to the MySQL database
    connect_to_database(conn);

    // Create a new table
    create_table(conn);

    // Insert sample data into the table
    insert_data(conn);

    // Query and print the results
    query_data(conn);
    
    // Close the connection to the database
    close_connection(conn);
    
    return 0;
}

void connect_to_database(MYSQL *conn) {
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the database using mysql_real_connect
    if (mysql_real_connect(conn, "localhost", "root", "password123", "testdb", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        exit(EXIT_FAILURE);
    }
    printf("Connected to the database successfully!\n");
}

void create_table(MYSQL *conn) {
    const char *create_table_query = 
        "CREATE TABLE IF NOT EXISTS Users ("
        "id INT AUTO_INCREMENT PRIMARY KEY,"
        "username VARCHAR(100) NOT NULL,"
        "email VARCHAR(100),"
        "age INT DEFAULT 0);";

    if (mysql_query(conn, create_table_query)) {
        fprintf(stderr, "CREATE TABLE failed. Error: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }
    printf("Table 'Users' created successfully!\n");
}

void insert_data(MYSQL *conn) {
    const char *insert_query_template = 
        "INSERT INTO Users (username, email, age) VALUES ('%s', '%s', %d);";
    
    char insert_query[256];
    
    // Sample users
    const char *usernames[] = {"JohnDoe", "JaneSmith", "AliceJohnson", "BobBrown"};
    const char *emails[] = {"john@example.com", "jane@example.com", "alice@example.com", "bob@example.com"};
    int ages[] = {30, 25, 35, 40};

    for (int i = 0; i < 4; i++) {
        snprintf(insert_query, sizeof(insert_query), insert_query_template, usernames[i], emails[i], ages[i]);
        if (mysql_query(conn, insert_query)) {
            fprintf(stderr, "INSERT failed. Error: %s\n", mysql_error(conn));
            exit(EXIT_FAILURE);
        }
        printf("Inserted user %s successfully!\n", usernames[i]);
    }
}

void query_data(MYSQL *conn) {
    if (mysql_query(conn, "SELECT * FROM Users")) {
        fprintf(stderr, "SELECT * failed. Error: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "mysql_store_result() failed. Error: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }
    
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    printf("\nUser Records:\n");
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}

void close_connection(MYSQL *conn) {
    mysql_close(conn);
    printf("Connection to the database closed.\n");
}