//Falcon-180B DATASET v1.0 Category: Memory management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 100
#define MAX_VAR_LEN 20

typedef struct {
    char *name;
    int value;
} Var;

int numVars = 0;
Var vars[MAX_VARS];

void initVars() {
    for (int i = 0; i < MAX_VARS; i++) {
        vars[i].name = NULL;
        vars[i].value = 0;
    }
    numVars = 0;
}

int addVar(char *name) {
    if (numVars >= MAX_VARS) {
        printf("Error: Maximum number of variables reached.\n");
        return -1;
    }
    char *newName = (char *)malloc(MAX_VAR_LEN * sizeof(char));
    strcpy(newName, name);
    vars[numVars].name = newName;
    vars[numVars].value = 0;
    numVars++;
    return numVars - 1;
}

int setVar(int index, int value) {
    if (index < 0 || index >= numVars) {
        printf("Error: Invalid variable index.\n");
        return -1;
    }
    vars[index].value = value;
    return 0;
}

int getVar(char *name) {
    for (int i = 0; i < numVars; i++) {
        if (strcmp(vars[i].name, name) == 0) {
            return vars[i].value;
        }
    }
    printf("Error: Variable not found.\n");
    return -1;
}

void freeVars() {
    for (int i = 0; i < numVars; i++) {
        free(vars[i].name);
    }
    numVars = 0;
}

int main() {
    initVars();
    int index = addVar("x");
    setVar(index, 5);
    printf("%d\n", getVar("x"));
    freeVars();
    return 0;
}