//FormAI DATASET v1.0 Category: Database querying ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main(int argc, char const *argv[]) {
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;

  char *server = "localhost";
  char *user = "root";
  char *password = "mypassword";  // Please replace with your MySQL root password
  char *database = "mydatabase";

  conn = mysql_init(NULL);
  if (conn == NULL) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    exit(1);
  }

  if (mysql_real_connect(conn, server, user, password, database, 0, NULL, 0) == NULL) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
  }

  char query[1000] = "SELECT * FROM users WHERE";
  strcat(query, " username = '");
  strcat(query, argv[1]);
  strcat(query, "' AND password = '");
  strcat(query, argv[2]);
  strcat(query, "'");

  if (mysql_query(conn, query)) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
  }

  res = mysql_store_result(conn);
  if (res == NULL) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
  }

  while ((row = mysql_fetch_row(res)) != NULL) {
    printf("Welcome %s!\n", row[0]);
  }

  mysql_free_result(res);
  mysql_close(conn);

  return 0;
}