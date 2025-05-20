//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "password"
#define DB_NAME "future_db"

void handle_mysql_error(MYSQL *conn) {
    fprintf(stderr, "MySQL Error: %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(EXIT_FAILURE);
}

void create_table(MYSQL *conn) {
    const char *create_table_query =
        "CREATE TABLE IF NOT EXISTS Users ("
        "id INT AUTO_INCREMENT PRIMARY KEY, "
        "name VARCHAR(100), "
        "email VARCHAR(100), "
        "age INT"
        ");";

    if (mysql_query(conn, create_table_query)) {
        handle_mysql_error(conn);
    }
    printf("Table 'Users' created successfully!\n");
}

void insert_user(MYSQL *conn, const char *name, const char *email, int age) {
    char insert_query[256];
    snprintf(insert_query, sizeof(insert_query), 
             "INSERT INTO Users (name, email, age) VALUES ('%s', '%s', %d);", 
             name, email, age);

    if (mysql_query(conn, insert_query)) {
        handle_mysql_error(conn);
    }
    printf("User %s inserted successfully!\n", name);
}

void query_users(MYSQL *conn) {
    if (mysql_query(conn, "SELECT * FROM Users;")) {
        handle_mysql_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        handle_mysql_error(conn);
    }

    printf("Query Results:\n");
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        printf("ID: %s, Name: %s, Email: %s, Age: %s\n", 
                row[0], row[1], row[2], row[3]);
    }

    mysql_free_result(result);
}

void update_user(MYSQL *conn, int user_id, const char *new_email) {
    char update_query[256];
    snprintf(update_query, sizeof(update_query),
             "UPDATE Users SET email='%s' WHERE id=%d;", 
             new_email, user_id);

    if (mysql_query(conn, update_query)) {
        handle_mysql_error(conn);
    }
    printf("User with ID %d updated successfully!\n", user_id);
}

void delete_user(MYSQL *conn, int user_id) {
    char delete_query[256];
    snprintf(delete_query, sizeof(delete_query), 
             "DELETE FROM Users WHERE id=%d;", user_id);

    if (mysql_query(conn, delete_query)) {
        handle_mysql_error(conn);
    }
    printf("User with ID %d deleted successfully!\n", user_id);
}

void close_connection(MYSQL *conn) {
    mysql_close(conn);
    printf("Database connection closed.\n");
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 0, NULL, 0) == NULL) {
        handle_mysql_error(conn);
    }

    create_table(conn);

    insert_user(conn, "Alice Smith", "alice@example.com", 30);
    insert_user(conn, "Bob Johnson", "bob@example.com", 25);

    query_users(conn);

    update_user(conn, 1, "alice.smith@newmail.com");

    query_users(conn);

    delete_user(conn, 2);
    
    query_users(conn);

    close_connection(conn);
    return EXIT_SUCCESS;
}