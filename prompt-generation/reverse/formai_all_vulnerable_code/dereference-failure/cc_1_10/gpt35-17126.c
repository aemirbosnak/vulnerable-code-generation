//FormAI DATASET v1.0 Category: Database querying ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main()
{
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;

  char *server = "localhost";
  char *user = "root";
  char *password = "password";
  char *database = "mydb";

  conn = mysql_init(NULL);
  
  if(!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
  {
    printf("Error connecting to database: %s\n", mysql_error(conn));
    exit(1);
  }

  printf("Connected to database successfully!\n");

  // Get the total number of records in the table
  if(mysql_query(conn, "SELECT COUNT(*) FROM employees"))
  {
    printf("Error querying database: %s\n", mysql_error(conn));
    exit(1);
  }

  res = mysql_use_result(conn);

  printf("Total number of records in the table: ");

  while((row = mysql_fetch_row(res)) != NULL)
  {
    printf("%s\n", row[0]);
  }

  mysql_free_result(res);

  // Get the details of the youngest employee
  if(mysql_query(conn, "SELECT name, age, salary FROM employees WHERE age = (SELECT MIN(age) FROM employees)"))
  {
    printf("Error querying database: %s\n", mysql_error(conn));
    exit(1);
  }

  res = mysql_use_result(conn);

  printf("\nDetails of the youngest employee: \n");

  while((row = mysql_fetch_row(res)) != NULL)
  {
    printf("Name: %s | Age: %s | Salary: %s\n", row[0], row[1], row[2]);
  }

  mysql_free_result(res);

  mysql_close(conn);
  
  printf("\nDisconnected from database.\n");

  return 0;
}