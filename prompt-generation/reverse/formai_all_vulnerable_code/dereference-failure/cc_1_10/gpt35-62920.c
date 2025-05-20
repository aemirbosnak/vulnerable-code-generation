//FormAI DATASET v1.0 Category: Database querying ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main(int argc, char **argv){

//connect to database
MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;
char *server = "localhost";
char *user = "root";
char *password = "root"; /* set me first */
char *database = "social_media";
conn = mysql_init(NULL);
if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
 }

//query the database
char query[1000];
char name[50];
printf("Enter the name of the user you want to search: ");
fgets(name, 50, stdin);
name[strcspn(name, "\n")] = 0; //remove the newline character from input
sprintf(query, "SELECT * FROM users WHERE name='%s'", name); //build the query string
if (mysql_query(conn, query)) {
     fprintf(stderr, "%s\n", mysql_error(conn));
     exit(1);
 }
res = mysql_use_result(conn);

//display results
while ((row = mysql_fetch_row(res)) != NULL){
    printf("User ID: %d\n", atoi(row[0]));
    printf("Name: %s\n", row[1]);
    printf("Email: %s\n", row[2]);
    printf("Bio: %s\n", row[3]);
    printf("Number of Posts: %d\n", atoi(row[4]));
    printf("\n");
}

//clean up
mysql_free_result(res);
mysql_close(conn);

return 0;
}