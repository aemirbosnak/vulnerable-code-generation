//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

void execute_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "QUERY ERROR: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }
}

void print_results(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
}

void select_from_table(MYSQL *conn) {
    const char *query = "SELECT * FROM shapes;";
    execute_query(conn, query);

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "RESULT ERROR: %s\n", mysql_error(conn));
        return;
    }

    print_results(result);
    mysql_free_result(result);
}

void insert_shape(MYSQL *conn, const char *name, const char *property) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO shapes (name, property) VALUES ('%s', '%s');", name, property);
    execute_query(conn, query);
}

void update_shape_property(MYSQL *conn, const char *name, const char *new_property) {
    char query[256];
    snprintf(query, sizeof(query), "UPDATE shapes SET property='%s' WHERE name='%s';", new_property, name);
    execute_query(conn, query);
}

void delete_shape(MYSQL *conn, const char *name) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM shapes WHERE name='%s';", name);
    execute_query(conn, query);
}

void menu(MYSQL *conn) {
    int choice = 0;
    while (choice != 5) {
        printf("\nShape Database Menu:\n");
        printf("1. View all shapes\n");
        printf("2. Add a new shape\n");
        printf("3. Update a shape's property\n");
        printf("4. Delete a shape\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                select_from_table(conn);
                break;
            case 2: {
                char name[50], property[50];
                printf("Enter shape name: ");
                scanf("%s", name);
                printf("Enter shape property: ");
                scanf("%s", property);
                insert_shape(conn, name, property);
                break;
            }
            case 3: {
                char name[50], new_property[50];
                printf("Enter shape name to update: ");
                scanf("%s", name);
                printf("Enter new property: ");
                scanf("%s", new_property);
                update_shape_property(conn, name, new_property);
                break;
            }
            case 4: {
                char name[50];
                printf("Enter shape name to delete: ");
                scanf("%s", name);
                delete_shape(conn, name);
                break;
            }
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, "localhost", "username", "password", "shapes_db", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    menu(conn);
    mysql_close(conn);
    return EXIT_SUCCESS;
}