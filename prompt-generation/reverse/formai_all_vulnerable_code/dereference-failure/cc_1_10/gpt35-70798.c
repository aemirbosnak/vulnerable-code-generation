//FormAI DATASET v1.0 Category: Database querying ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function for querying database
void queryDatabase(char *databasePath, char *tableName, char *columnName, char *condition){
    // Open database file
    FILE *database = fopen(databasePath, "r");
    if(database == NULL){
        printf("Error opening database file.\n");
        return;
    }

    // Find specified table
    char line[100];
    fgets(line, 100, database);
    while(strcmp(line, tableName) != 0 && !feof(database)){
        fgets(line, 100, database);
    }
    if(feof(database)){
        printf("Table not found.\n");
        fclose(database);
        return;
    }

    // Find specified column
    fgets(line, 100, database);
    char *token = strtok(line, ",");
    while(strcmp(token, columnName) != 0 && token != NULL){
        token = strtok(NULL, ",");
    }
    if(token == NULL){
        printf("Column not found.\n");
        fclose(database);
        return;
    }
    int columnIndex = (int)(token - line)/sizeof(char*);

    // Print matching rows
    while(fscanf(database, "%s", line) != EOF){
        token = strtok(line, ",");
        if(columnIndex == 0 && strcmp(token, condition) == 0){
            printf("%s\n", line);
        }
        else{
            int i = 1;
            while(token != NULL && i <= columnIndex){
                token = strtok(NULL, ",");
                i++;
            }
            if(strcmp(token, condition) == 0){
                printf("%s\n", line);
            }
        }
    }
    fclose(database);
}

int main(){
    char *databasePath = "exampleDatabase.txt";
    char *tableName = "customers";
    char *columnName = "name";
    char *condition = "John";

    printf("Querying database...\n");

    queryDatabase(databasePath, tableName, columnName, condition);

    printf("Done.");
    return 0;
}