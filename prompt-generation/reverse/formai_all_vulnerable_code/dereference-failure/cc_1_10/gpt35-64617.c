//FormAI DATASET v1.0 Category: Database querying ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <mysql/mysql.h>

#define DBHOST "localhost"
#define DBUSER "root"
#define DBPASS "root"
#define DBNAME "mydb"

void error_fatal(MYSQL *mysql)
{
    fprintf(stderr, "%s\n", mysql_error(mysql));
    mysql_close(mysql);
    exit(1);    
}

void execute_query(MYSQL *mysql, char *query, void (*callback_function)(MYSQL *mysql, MYSQL_RES *result))
{
    int status = mysql_query(mysql, query);    
    if(status != 0) {
        error_fatal(mysql);
    } else {
        MYSQL_RES *result = mysql_store_result(mysql);        
        if(result == NULL) {
            fprintf(stderr, "No results\n");
        } else {            
            callback_function(mysql, result);
            mysql_free_result(result);
        }        
    }    
}

void print_result(MYSQL *mysql, MYSQL_RES *result)
{    
    if(result != NULL) {
        int num_fields = mysql_num_fields(result);
        
        MYSQL_ROW row;
        while((row = mysql_fetch_row(result))) {        
            for(int i = 0; i < num_fields; i++) {
                if(row[i] != NULL) {
                    printf("%s ", row[i]);
                } else {
                    printf("NULL ");
                }
            }
            putchar('\n');
        }    
    }    
}

void async_query(MYSQL *mysql, char *query)
{
    pid_t pid = fork();
    if(pid == -1) {
        error_fatal(mysql);
    } else if(pid == 0) {
        execute_query(mysql, query, print_result);
        exit(0);
    }        
}

int main(int argc, char **argv)
{
    MYSQL *mysql = mysql_init(NULL);
    if(mysql == NULL) {
        error_fatal(mysql);
    }
    
    if(mysql_real_connect(mysql, DBHOST, DBUSER, DBPASS, DBNAME, 0, NULL, 0) == NULL) {
        error_fatal(mysql);
    }
        
    async_query(mysql, "SELECT * FROM customers WHERE city='London'");
    async_query(mysql, "SELECT * FROM orders WHERE orderDate > '2003-01-01'");
    async_query(mysql, "SELECT * FROM products WHERE category='Confections'");
    
    while(wait(NULL) > 0);
    
    mysql_close(mysql);
    return 0;
}