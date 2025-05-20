//FormAI DATASET v1.0 Category: Database querying ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h> //Include MySQL header file

//Function to connect with the database
MYSQL* mysql_connection_setup()
{
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (!conn)
    {
        printf("MySQL initialization failed\n");
        exit(1);
    }
    conn = mysql_real_connect(conn, "localhost", "root", "password", "test_db", 0, NULL, 0);
    if (conn)
    {
        printf("Connection to MySQL database succeeded\n");
    }
    else
    {
        printf("Connection failed\n");
    }
    return conn;
}

//Function for querying the database
void run_query(MYSQL *conn, char *query)
{
    if (mysql_query(conn, query))
    {
        printf("Query Execution Failed: %s", mysql_error(conn));
    }
    else
    {
        printf("Query Executed Successfully\n");
    }
}

int main()
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn = mysql_connection_setup(); //Connect to database
    char query[500];
    
    //Query for creating a table in the database
    sprintf(query, "CREATE TABLE STUDENT (ID INT PRIMARY KEY, NAME VARCHAR(50), AGE INT, GPA FLOAT)");
    run_query(conn, query);
    
    //Inserted values in the table
    sprintf(query, "INSERT INTO STUDENT VALUES(100, 'John', 25, 3.8), (101, 'Jane', 24, 3.6), (102, 'Mary', 26, 3.9), (103, 'Peter', 23, 3.5)");
    run_query(conn, query);
    
    //Query for selecting all rows from the table
    sprintf(query, "SELECT * FROM STUDENT");
    run_query(conn, query);
    
    //Storing the result of SELECT query in MYSQL_RES structure
    res = mysql_store_result(conn);
    
    //Printing the data row by row
    while ((row = mysql_fetch_row(res)) != NULL)
    {
        printf("%s %s %s %s\n", row[0], row[1], row[2], row[3]);
    }
    
    //Freeing the memory occupied by MYSQL_RES structure and closing the connection
    mysql_free_result(res);
    mysql_close(conn);
    return 0;
}