//Falcon-180B DATASET v1.0 Category: Database querying ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

struct employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};

MYSQL *conn = NULL;

int main() {
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Failed to connect to MySQL: %s\n", mysql_error(conn));
        exit(1);
    }

    printf("Connected to MySQL.\n");

    struct employee emp;
    char query[100];

    sprintf(query, "SELECT * FROM employees");

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error querying database: %s\n", mysql_error(conn));
        exit(1);
    }

    printf("Query executed successfully.\n");

    while ((mysql_fetch_row(conn))!= NULL) {
        memset(&emp, 0, sizeof(emp));

        emp.id = atoi(mysql_fetch_row(conn)[0]);
        strcpy(emp.name, mysql_fetch_row(conn)[1]);
        strcpy(emp.department, mysql_fetch_row(conn)[2]);
        emp.salary = atof(mysql_fetch_row(conn)[3]);

        printf("ID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n", emp.id, emp.name, emp.department, emp.salary);
    }

    mysql_close(conn);

    return 0;
}