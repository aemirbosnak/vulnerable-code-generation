//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

void create_database(MYSQL *conn) {
    if (mysql_query(conn, "CREATE DATABASE IF NOT EXISTS ScientificStudies")) {
        finish_with_error(conn);
    }
}

void create_table(MYSQL *conn) {
    if (mysql_query(conn, "USE ScientificStudies")) {
        finish_with_error(conn);
    }
    
    const char *create_table_query = 
        "CREATE TABLE IF NOT EXISTS ResearchData ("
        "ID INT AUTO_INCREMENT PRIMARY KEY, "
        "Title VARCHAR(255) NOT NULL, "
        "Author VARCHAR(100) NOT NULL, "
        "PublishedYear INT NOT NULL, "
        "Journal VARCHAR(100) NOT NULL, "
        "Citations INT DEFAULT 0 );";

    if (mysql_query(conn, create_table_query)) {
        finish_with_error(conn);
    }
}

void insert_data(MYSQL *conn) {
    const char *insert_query = 
        "INSERT INTO ResearchData (Title, Author, PublishedYear, Journal, Citations) VALUES "
        "('Quantum Entanglement Explained', 'Dr. John Doe', 2022, 'Quantum Physics Journal', 150), "
        "('The Theory of Relativity', 'Dr. Albert Einstein', 1916, 'Physics Monthly', 2000), "
        "('Genetic Algorithms in Computer Science', 'Dr. Ada Lovelace', 2021, 'Computer Science Review', 300);";

    if (mysql_query(conn, insert_query)) {
        finish_with_error(conn);
    }
}

void query_data(MYSQL *conn) {
    if (mysql_query(conn, "SELECT * FROM ResearchData")) {
        finish_with_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        finish_with_error(conn);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    printf("Research Data:\n");
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(result);
}

void delete_data(MYSQL *conn) {
    const char *delete_query = "DELETE FROM ResearchData WHERE Title='Quantum Entanglement Explained';";
    if (mysql_query(conn, delete_query)) {
        finish_with_error(conn);
    }
}

int main(void) {
    MYSQL *conn = mysql_init(NULL);
    
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    conn = mysql_real_connect(conn, "localhost", "username", "password", NULL, 0, NULL, 0);
    if (conn == NULL) {
        finish_with_error(conn);
    }

    create_database(conn);
    create_table(conn);
    insert_data(conn);
    query_data(conn);
    delete_data(conn);
    query_data(conn);

    mysql_close(conn);
    return EXIT_SUCCESS;
}