//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "your_password" // Change this to your actual password
#define DATABASE "testdb"

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

void display_results(MYSQL_RES *result) {
    MYSQL_ROW row;
    unsigned int num_fields = mysql_num_fields(result);
    unsigned long *lengths;

    // Print each row of the result
    while ((row = mysql_fetch_row(result))) {
        lengths = mysql_fetch_lengths(result);
        for (unsigned int i = 0; i < num_fields; i++) {
            if (row[i] != NULL)
                printf("%.*s ", (int)lengths[i], row[i]);
            else
                printf("NULL ");
        }
        printf("\n");
    }
}

void query_database(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result) {
        display_results(result);
        mysql_free_result(result);
    } else {
        if (mysql_field_count(conn) == 0) {
            printf("%lld rows affected.\n", mysql_affected_rows(conn));
        } else {
            finish_with_error(conn);
        }
    }
}

int main(int argc, char **argv) {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }

    printf("Surprise! Let's fetch data from the database.\n");

    // Assuming we have a table named 'employees'
    const char *query = "SELECT id, name, age, salary FROM employees WHERE age > 30 ORDER BY salary DESC;";
    printf("Querying database: %s\n", query);
    query_database(conn, query);

    printf("Whoa, look at this data we just fetched from the 'employees' table!\n");
    
    // Random surprise data retrieval
    query = "SELECT DISTINCT department FROM employees;";
    printf("Now let's see the different departments:\n");
    query_database(conn, query);
    
    // Surprise insertion
    printf("Enter name, age and salary to insert into employees (comma-separated): ");
    char input[100];
    fgets(input, sizeof(input), stdin);
    char name[50];
    int age;
    float salary;

    sscanf(input, "%49[^,], %d, %f", name, &age, &salary);
    char insert_query[200];
    snprintf(insert_query, sizeof(insert_query), "INSERT INTO employees (name, age, salary) VALUES ('%s', %d, %.2f);", name, age, salary);

    printf("Inserting the new employee: %s\n", insert_query);
    query_database(conn, insert_query);

    // Surprise update
    printf("Let's give everyone in the 'IT' department a bonus!\n");
    char update_query[100];
    snprintf(update_query, sizeof(update_query), "UPDATE employees SET salary = salary * 1.10 WHERE department = 'IT';");
    query_database(conn, update_query);

    // Finalidy surprise removing one employee
    printf("Now let's remove the employee with a specific id (be careful!): ");
    int id_to_remove;
    scanf("%d", &id_to_remove);
    char delete_query[100];
    snprintf(delete_query, sizeof(delete_query), "DELETE FROM employees WHERE id = %d;", id_to_remove);
    query_database(conn, delete_query);

    printf("Finishing up!\n");
    mysql_close(conn);
    return EXIT_SUCCESS;
}