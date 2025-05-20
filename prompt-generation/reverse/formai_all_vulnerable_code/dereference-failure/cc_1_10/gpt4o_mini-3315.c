//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "your_user"
#define PASSWORD "your_password"
#define DATABASE "your_database"

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

void execute_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
}

void print_results(MYSQL *conn) {
    MYSQL_RES *res;
    MYSQL_ROW row;

    res = mysql_store_result(conn);
    if (res == NULL) {
        finish_with_error(conn);
    }

    int num_fields = mysql_num_fields(res);
    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s | ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(res);
}

void insert_data(MYSQL *conn) {
    char query[256];
    const char *name = "John Doe";
    int age = 30;
    snprintf(query, sizeof(query), "INSERT INTO users (name, age) VALUES ('%s', %d)", name, age);
    execute_query(conn, query);
    printf("Inserted %s, age %d into the database.\n", name, age);
}

void fetch_all_users(MYSQL *conn) {
    execute_query(conn, "SELECT * FROM users");
    print_results(conn);
}

void fetch_users_by_age(MYSQL *conn, int age) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT * FROM users WHERE age = %d", age);
    execute_query(conn, query);
    print_results(conn);
}

void update_user_age(MYSQL *conn, const char *name, int new_age) {
    char query[256];
    snprintf(query, sizeof(query), "UPDATE users SET age = %d WHERE name = '%s'", new_age, name);
    execute_query(conn, query);
    printf("Updated %s age to %d.\n", name, new_age);
}

void delete_user(MYSQL *conn, const char *name) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM users WHERE name = '%s'", name);
    execute_query(conn, query);
    printf("Deleted user %s from the database.\n", name);
}

int main() {
    MYSQL *conn;
    conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }

    if (mysql_real_connect(conn, SERVER, USER, PASSWORD,
                           DATABASE, 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }

    printf("Connected to the database successfully.\n");

    // Inserting data
    insert_data(conn);

    // Fetching all users
    printf("Fetching all users:\n");
    fetch_all_users(conn);
    
    // Fetch users by age
    printf("Fetching users with age 30:\n");
    fetch_users_by_age(conn, 30);

    // Updating user's age
    update_user_age(conn, "John Doe", 31);
    printf("Updated John's age:\n");
    fetch_all_users(conn);

    // Deleting user
    delete_user(conn, "John Doe");
    printf("Users after deletion:\n");
    fetch_all_users(conn);

    mysql_close(conn);
    return 0;
}