//FormAI DATASET v1.0 Category: Database querying ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/mysql.h>

//global variable to hold database connection info
MYSQL *conn;

//function to handle errors
void error(const char *msg)
{
    fprintf(stderr,"%s: %s\n",msg,mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

//function to display data from the database
void display_data(MYSQL_RES *result)
{
    MYSQL_ROW row;
    int i,num_fields;
    num_fields = mysql_num_fields(result);
    printf("\n--------------------------------------------------------\n");

    while((row = mysql_fetch_row(result)) != NULL)
    {
        for(i = 0; i < num_fields; i++)
        {
            printf("| %s\t",row[i] ? row[i] : "NULL");
        }
        printf("|\n");
    }

    printf("--------------------------------------------------------\n");
}

int main(int argc, char *argv[])
{
    //local variable declarations
    char *server = "localhost";
    char *user = "root";
    char *password = "password";
    char *database = "testdb";
    char *query;
    int rc;

    //initialize the connection
    conn = mysql_init(NULL);

    //check if initialization was successful
    if(conn == NULL)
    {
        error("Could not initialize connection to database");
    }

    //connect to the database
    if(mysql_real_connect(conn,server,user,password,database,0,NULL,0) == NULL)
    {
        error("Could not connect to the database");
    }

    printf("Connected to MySQL database: %s\n", database);

    //query the database for all data in the customers table
    query = "SELECT * FROM customers";

    rc = mysql_query(conn,query);

    //check if query was successful
    if(rc != 0)
    {
        error("Could not query the database");
    }

    //get the results of the query
    MYSQL_RES *result = mysql_use_result(conn);

    //display the data
    printf("--------------------------------------------------------\n");
    printf("|  ID\t|  Name\t|  Email\t\t|  Phone Number\t|\n");
    display_data(result);

    //free the result set
    mysql_free_result(result);

    //close the connection
    mysql_close(conn);

    return 0;
}