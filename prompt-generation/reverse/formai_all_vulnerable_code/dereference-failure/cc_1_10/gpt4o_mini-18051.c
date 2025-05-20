//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <time.h>

void surrealDream(MYSQL *conn) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    
    printf("In the land of floating ideas, we create our query...\n");

    // A whimsical query where fruits gather beneath a pixelated sun
    const char *query = "SELECT fruit_name, color, quantity FROM surreal_fruits WHERE quantity > 0 ORDER BY quantity DESC;";
    
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Dream shattered: %s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_store_result(conn);
    if (res == NULL) {
        fprintf(stderr, "The dream was a mirage: %s\n", mysql_error(conn));
        exit(1);
    }

    int num_fields = mysql_num_fields(res);
    
    printf("Behold the fruits of our labor:\n");
    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < num_fields; i++) {
            printf("A %s colored %s rests beside a pile of %s.\n", row[1], row[0], row[2]);
        }
        printf("~~~~~~~~~~~\n");
    }
    
    mysql_free_result(res);
}

void summonDatabaseConnection(MYSQL *conn, const char *host, const char *user, const char *password, const char *dbname) {
    mysql_init(conn);
    
    if (!mysql_real_connect(conn, host, user, password, dbname, 0, NULL, 0)) {
        fprintf(stderr, "Connection failed: %s\n", mysql_error(conn));
        exit(1);
    }
    
    printf("Connection to the fruits' kingdom established!\n");
}

void whimsicalClosure(MYSQL *conn) {
    mysql_close(conn);
    printf("As the sun sets on our database, we bid adieu...\n");
}

int main(int argc, char **argv) {
    MYSQL *conn = malloc(sizeof(MYSQL));
    const char *host = "localhost";
    const char *user = "username";
    const char *password = "password";
    const char *dbname = "surreal_fruits_db";

    if (argc > 1) {
        host = argv[1];
    }
    if (argc > 2) {
        user = argv[2];
    }
    if (argc > 3) {
        password = argv[3];
    }
    if (argc > 4) {
        dbname = argv[4];
    }

    summonDatabaseConnection(conn, host, user, password, dbname);
    
    surrealDream(conn);
   
    whimsicalClosure(conn);
    
    free(conn);
    return 0;
}