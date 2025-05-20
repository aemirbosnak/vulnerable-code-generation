//FormAI DATASET v1.0 Category: Database querying ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

// Function to print the error message if the database connection fails
void finish_with_error(MYSQL *con) {
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main() {
  MYSQL *con = mysql_init(NULL);

  if (con == NULL) {
    fprintf(stderr, "mysql_init() failed\n");
    exit(1);
  }

  // Connect to the database
  if (mysql_real_connect(con, "localhost", "user", "password", "database", 0, NULL, 0) == NULL) {
    finish_with_error(con);
  }

  // Select all rows from the table 'employees'
  if (mysql_query(con, "SELECT * FROM employees")) {
      finish_with_error(con);
  }

  // Store the results in a 'result' variable
  MYSQL_RES *result = mysql_store_result(con);

  // If the results are NULL, print the error message and exit
  if (result == NULL) {
      finish_with_error(con);
  }

  // Get the number of columns in the result set
  int num_fields = mysql_num_fields(result);

  // Print the column headers
  MYSQL_FIELD *field;
  while ((field = mysql_fetch_field(result))) {
      printf("%s ", field->name);
  }
  printf("\n");

  // Loop through the rows of the result set
  MYSQL_ROW row;
  while ((row = mysql_fetch_row(result))) {
      for(int i = 0; i < num_fields; i++) {
          printf("%s ", row[i] ? row[i] : "NULL");
      }
      printf("\n");
  }

  // Free the memory allocated for the result set
  mysql_free_result(result);

  // Close the database connection
  mysql_close(con);

  return 0;
}