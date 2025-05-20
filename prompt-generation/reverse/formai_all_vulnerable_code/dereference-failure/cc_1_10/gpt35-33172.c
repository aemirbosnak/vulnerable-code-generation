//FormAI DATASET v1.0 Category: Database querying ; Style: complete
/*
*  This program is an example of querying a database using C.
*
*  The database used in this example contains a table named "students"
*  with columns "id", "name", "age", and "grade".
*
*  The program prompts the user to enter a student's ID, and then queries
*  the database to retrieve that student's name, age, and grade. If the 
*  student is not found in the database, the program prints an error message.
*
*  This program assumes the user has already set up a MySQL database with the
*  above table, and has included the necessary header files and libraries for
*  MySQL connector in C.
*/

#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

//function to handle errors thrown by MySQL queries
void finish_with_error(MYSQL *con) {
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main() {

  MYSQL *con = mysql_init(NULL);

  if (con == NULL) {
    fprintf(stderr, "%s\n", mysql_error(con));
    exit(1);
  }

  //connect to local MySQL server with specified credentials
  if (mysql_real_connect(con, "localhost", "myuser", "mypassword", 
          "mydatabase", 0, NULL, 0) == NULL) {
    finish_with_error(con);
  }

  char id[6];
  printf("Enter the student's ID: ");
  fgets(id, 6, stdin);

  //prepare SQL query as a string
  char query[100];
  sprintf(query, "SELECT name, age, grade FROM students WHERE id=%s", id);

  if (mysql_query(con, query)) {
    finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL) {
    finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;
  if ((row = mysql_fetch_row(result))) {

    printf("\nStudent found:\n");
    printf("Name: %s\n", row[0]);
    printf("Age: %s\n", row[1]);
    printf("Grade: %s\n", row[2]);

  } else {
    printf("\nStudent not found.\n");
  }

  mysql_free_result(result);
  mysql_close(con);

  return 0;
}