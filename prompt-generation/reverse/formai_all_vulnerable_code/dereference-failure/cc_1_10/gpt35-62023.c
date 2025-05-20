//FormAI DATASET v1.0 Category: Database querying ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Global variables for storing connection parameters
char *host = "localhost";
char *user = "root";
char *password = "123456";
char *database = "University";

int main() {
  MYSQL *conn = mysql_init(NULL);
  MYSQL_RES *result;
  MYSQL_ROW row;

  // Connect to the database
  if (!mysql_real_connect(conn, host, user, password, database, 0, NULL, 0)) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    exit(1);
  }

  // Select all courses offered by the Computer Science department
  char *query = "SELECT * FROM courses WHERE department='Computer Science'";
  if (mysql_query(conn, query)) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    exit(1);
  }

  result = mysql_use_result(conn);

  // Print the header
  printf("%-10s %-30s %-20s\n", "Course ID", "Course Name", "Department");

  // Print each row of the result
  while ((row = mysql_fetch_row(result))) {
    printf("%-10s %-30s %-20s\n", row[0], row[1], row[2]);
  }

  mysql_free_result(result);

  // Select all students taking the course CS101
  query = "SELECT students.name, courses.course_name FROM students INNER JOIN enrollments ON students.id=enrollments.student_id INNER JOIN courses ON enrollments.course_id=courses.id WHERE courses.course_id='CS101'";
  if (mysql_query(conn, query)) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    exit(1);
  }

  result = mysql_use_result(conn);

  // Print the header
  printf("\n%-30s %-30s\n", "Student Name", "Course Name");

  // Print each row of the result
  while ((row = mysql_fetch_row(result))) {
    printf("%-30s %-30s\n", row[0], row[1]);
  }

  mysql_free_result(result);

  // Clean up and close the connection
  mysql_close(conn);

  return 0;
}