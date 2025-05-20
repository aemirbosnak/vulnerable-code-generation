//FormAI DATASET v1.0 Category: Database querying ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sqlite3.h>

// Defining the struct to hold the data
struct person {
    int id;
    char name[20];
    int age;
};

int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    struct person p1, p2;
    
    // Open the database file
    rc = sqlite3_open("test.db", &db);

    // Check for any errors
    if(rc){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }else{
        printf("Opened database successfully\n");
    }

    // Create table
    sql = "CREATE TABLE PERSON(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE INT NOT NULL);";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    // Insert data into person table
    sql = "INSERT INTO PERSON(ID, NAME, AGE) VALUES(1, 'Tom', 25);"
          "INSERT INTO PERSON(ID, NAME, AGE) VALUES(2, 'John', 30);"
          "INSERT INTO PERSON(ID, NAME, AGE) VALUES(3, 'Harry', 35);";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    // Querying the database using the SELECT statement
    sql = "SELECT * FROM PERSON WHERE ID = 2;";
    rc = sqlite3_exec(db, sql, callback, (void*)&data, &zErrMsg);

    // Storing the result in a struct variable
    p1.id = atoi(argv[0]);
    strcpy(p1.name, argv[1]);
    p1.age = atoi(argv[2]);

    printf("Query result for person with ID 2:\n");
    printf("Person ID: %d\nName: %s\nAge: %d\n\n", p1.id, p1.name, p1.age);

    // Update the name of person with ID 2
    sql = "UPDATE PERSON SET NAME = 'John Smith' WHERE ID = 2;";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    printf("Name updated successfully\n");

    // Querying the database after update statement
    sql = "SELECT * FROM PERSON WHERE ID = 2;";
    rc = sqlite3_exec(db, sql, callback, (void*)&data, &zErrMsg);

    // Storing the result in a struct variable
    p2.id = atoi(argv[0]);
    strcpy(p2.name, argv[1]);
    p2.age = atoi(argv[2]);

    printf("Query result after update statement:\n");
    printf("Person ID: %d\nName: %s\nAge: %d\n\n", p2.id, p2.name, p2.age);

    // Delete the person with ID 3
    sql = "DELETE FROM PERSON WHERE ID = 3;";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    printf("Person with ID 3 deleted successfully\n");

    // Close the database connection
    sqlite3_close(db);
    
    return 0;
}