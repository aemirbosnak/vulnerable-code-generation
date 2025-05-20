//Falcon-180B DATASET v1.0 Category: Database querying ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} employee;

int main() {
    MYSQL *conn = NULL;
    MYSQL_RES *res = NULL;
    MYSQL_ROW row;
    char query[100];
    char server = 'localhost';
    char user = 'root';
    char password = 'password';
    char dbname = 'company';

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, dbname, 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    printf("Connected to database successfully\n");

    // Query to retrieve all employee details
    sprintf(query, "SELECT * FROM employees");

    if (!mysql_query(conn, query)) {
        printf("Error querying database: %s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_store_result(conn);

    printf("Employee Details:\n");

    while ((row = mysql_fetch_row(res))!= NULL) {
        employee emp;
        memset(&emp, 0, sizeof(employee));

        strcpy(emp.name, row[0]);
        emp.age = atoi(row[1]);
        emp.salary = atof(row[2]);

        printf("Name: %s\nAge: %d\nSalary: %.2f\n\n", emp.name, emp.age, emp.salary);
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}