//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
// It's time to get database queries rolling
// Let's go on a whimsical coding journey

void finish_with_error(MYSQL *conn) {
    printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
    mysql_close(conn);
    exit(1);
}


void query_database(MYSQL *conn) {
    if (mysql_query(conn, "SELECT * FROM Students")) { 
        finish_with_error(conn); 
    }

    MYSQL_RES *result = mysql_store_result(conn);
    
    if (result == NULL) { 
        finish_with_error(conn); 
    }
    
    int num_fields = mysql_num_fields(result);
    
    // Set up for the joyous display of the records
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL"); 
        }
        printf("\n");
    }
    
    mysql_free_result(result);
}

void insert_database(MYSQL *conn, const char *name, int age) {
    char query[256];
    
    // Crafting our insertion query
    snprintf(query, sizeof(query), "INSERT INTO Students(Name, Age) VALUES('%s', %d)", name, age);
    
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
}

void delete_database(MYSQL *conn, const char *name) {
    char query[256];
    
    // The mysterious delete query blossom
    snprintf(query, sizeof(query), "DELETE FROM Students WHERE Name='%s'", name);
    
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }
    
    // Time for database connection
    if (mysql_real_connect(conn, "localhost", "root", "your_password", 
                           "school", 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }
    
    // Let's cozy up with an entry
    insert_database(conn, "Alice", 22);
    insert_database(conn, "Bob", 23);
    
    // A little moment of joy
    printf("Current Students:\n");
    query_database(conn);
    
    // Shuffling the entries like cards
    delete_database(conn, "Alice");
    
    // A peek again, what's left?
    printf("After Deletion:\n");
    query_database(conn);

    // Wrapping things up like a birthday gift
    mysql_close(conn);
    return EXIT_SUCCESS;  
}

// A sprinkle of comments to cherish the code at every step.
// The whimsical nature of this code brings it to life!