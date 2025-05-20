//Falcon-180B DATASET v1.0 Category: Database querying ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

#define MAX_NAME_LENGTH 64
#define MAX_QUERY_LENGTH 1024
#define MAX_RESULTS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float grade;
} Student;

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    char query[MAX_QUERY_LENGTH];
    sprintf(query, "SELECT * FROM students");

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error querying database: %s\n", mysql_error(conn));
        exit(1);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row;
    int num_results = 0;

    while ((row = mysql_fetch_row(result))) {
        if (num_results >= MAX_RESULTS) {
            fprintf(stderr, "Too many results. Exiting.\n");
            exit(1);
        }

        Student student;
        memset(&student, 0, sizeof(student));

        strncpy(student.name, row[0], MAX_NAME_LENGTH - 1);
        student.age = atoi(row[1]);
        student.grade = atof(row[2]);

        printf("Name: %s\n", student.name);
        printf("Age: %d\n", student.age);
        printf("Grade: %.2f\n\n", student.grade);

        num_results++;
    }

    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}