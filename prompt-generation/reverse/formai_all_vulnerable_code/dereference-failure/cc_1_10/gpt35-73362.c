//FormAI DATASET v1.0 Category: Database querying ; Style: irregular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<mysql/mysql.h>

//Function to handle any errors with the MySQL connection
void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main(int argc, char **argv)
{
  MYSQL *con = mysql_init(NULL);

  if (con == NULL) 
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  //Connecting to the MySQL database
  if (mysql_real_connect(con, "localhost", "user", "password", "database_name", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }

  //Querying the database to retrieve all data from the products table
  if (mysql_query(con, "SELECT * FROM products")) 
  {
      finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL) 
  {
      finish_with_error(con);
  }

  //Getting the number of rows in the result set
  int num_fields = mysql_num_fields(result);
  int num_rows = mysql_num_rows(result);

  printf("Number of fields: %d\n", num_fields);
  printf("Number of rows: %d\n", num_rows);

  //Printing the column headers
  MYSQL_FIELD *field;
  while ((field = mysql_fetch_field(result))) 
  {
      printf("%s ", field->name);
  }
  printf("\n");

  //Printing the data retrieved
  MYSQL_ROW row;
  while ((row = mysql_fetch_row(result))) 
  { 
      for(int i = 0; i < num_fields; i++) 
      { 
          printf("%s ", row[i] ? row[i] : "NULL"); 
      } 
      printf("\n"); 
  }

  //Freeing up the result set and closing the MySQL connection
  mysql_free_result(result);
  mysql_close(con);

  return 0;
}