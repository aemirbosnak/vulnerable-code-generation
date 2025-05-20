//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Var;

int numVars;
Var vars[MAX_VARS];

void addVar(char* name, char* value) {
    numVars++;
    strcpy(vars[numVars-1].name, name);
    strcpy(vars[numVars-1].value, value);
}

int main() {
    FILE* fp;
    char line[MAX_VALUE_LEN];
    char* token;
    int i;

    // Open file
    fp = fopen("metadata.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read file and extract metadata
    numVars = 0;
    while (fgets(line, MAX_VALUE_LEN, fp)!= NULL) {
        token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }
        addVar(token, strtok(NULL, ":"));
    }

    // Print extracted metadata
    printf("Number of variables: %d\n", numVars);
    for (i = 0; i < numVars; i++) {
        printf("Variable %d:\n", i+1);
        printf("  Name: %s\n", vars[i].name);
        printf("  Value: %s\n", vars[i].value);
        printf("\n");
    }

    // Close file
    fclose(fp);

    return 0;
}