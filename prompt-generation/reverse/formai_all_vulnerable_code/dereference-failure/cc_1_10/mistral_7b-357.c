//MISTRAL-7B DATASET v1.0 Category: Database querying ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_EMPLOYEES 1000
#define EMP_NAME_LEN 50
#define EMP_ID_LEN 10

typedef struct {
    int id;
    char name[EMP_NAME_LEN];
    float salary;
} Employee;

void print_employee(Employee emp) {
    printf("| %-10s | %-10d | %-12.2f |\n", emp.name, emp.id, emp.salary);
}

int main() {
    sqlite3 *db;
    int rc;
    Employee employees[MAX_EMPLOYEES];
    int num_employees = 0;

    rc = sqlite3_open("employees.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char *sql = "CREATE TABLE IF NOT EXISTS employees (" \
                "id INTEGER PRIMARY KEY," \
                "name TEXT NOT NULL," \
                "salary REAL NOT NULL);";

    rc = sqlite3_exec(db, sql, 0, 0, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sql = "INSERT INTO employees (name, salary) VALUES " \
         "('John Doe', 50000.0)," \
         "('Jane Smith', 55000.0)," \
         "('Mike Johnson', 60000.0);";

    rc = sqlite3_exec(db, sql, 0, 0, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    sql = "SELECT name, id, salary FROM employees;" \
         "ORDER BY salary DESC;" \
         "LIMIT 5;" \
         "INTO :name," \
         ":id," \
         ":salary;" \
         ";";

    sqlite3_stmt *stmt;
    char name[EMP_NAME_LEN];
    int id;
    float salary;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        strcpy(name, (char*)sqlite3_column_text(stmt, 0));
        id = sqlite3_column_int(stmt, 1);
        salary = sqlite3_column_double(stmt, 2);

        employees[num_employees++] = (Employee){id, name, salary};
    }

    sqlite3_finalize(stmt);

    printf("+--------+--------+---------------+\n");
    printf("| Name  | ID    | Salary        |\n");
    printf("+--------+--------+---------------+\n");

    for (int i = 0; i < num_employees; ++i) {
        print_employee(employees[i]);
    }

    sqlite3_close(db);

    return 0;
}