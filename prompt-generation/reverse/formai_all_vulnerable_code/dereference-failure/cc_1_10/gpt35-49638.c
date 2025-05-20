//FormAI DATASET v1.0 Category: Database querying ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/mysql.h>

// Function to print the results of the query
void print_result(MYSQL* connection, MYSQL_RES* result) {
    MYSQL_ROW row;
    MYSQL_FIELD* field;
    int num_fields = mysql_num_fields(result);
    int row_num = 0;
    while(row = mysql_fetch_row(result)) {
        printf("Row %d: ", row_num);
        for(int i=0; i<num_fields; i++) {
            field = mysql_fetch_field_direct(result, i);
            printf("%s: %s, ", field->name, row[i]);
        }
        printf("\n");
        row_num++;
    }
    mysql_free_result(result);
    mysql_close(connection);
}

int main(int argc, char** argv) {
    MYSQL* connection = mysql_init(NULL);
    if(connection == NULL) {
        fprintf(stderr, "Error initializing MySQL connection\n");
        exit(1);
    }
    if(mysql_real_connect(connection, "localhost", "root", "password", "my_database", 0, NULL, 0) == NULL) {
        fprintf(stderr, "Error connecting to MySQL database: %s\n", mysql_error(connection));
        mysql_close(connection);
        exit(1);
    } 
    printf("Connected to MySQL database!\n");

    // Query to retrieve all users whose name contains "John"
    char* query = "SELECT * FROM users WHERE name LIKE '%John%'";
    MYSQL_RES* result;
    if(mysql_query(connection, query)) {
        fprintf(stderr, "Error querying database: %s\n", mysql_error(connection));
        mysql_close(connection);
        exit(1);
    }
    result = mysql_store_result(connection);
    if(result == NULL) {
        fprintf(stderr, "Error storing MySQL query result: %s\n", mysql_error(connection));
        mysql_close(connection);
        exit(1);
    }

    // Print the query results
    printf("Query Result:\n");
    print_result(connection, result);
    printf("Wow, that was easy!\n");

    return 0;
}