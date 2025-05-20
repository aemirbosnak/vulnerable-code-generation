//FormAI DATASET v1.0 Category: Database querying ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct to represent a mathematical equation */
struct Equation {
    char name[20];  // name of the equation
    int num_variables; // number of variables in the equation
    char variables[10][20]; // array of variables in the equation
    char expression[100]; // mathematical expression of the equation
};

/* Define a struct to represent a database of equations */
struct EquationDB {
    struct Equation *equations; // array of equations
    int num_equations; // number of equations in the database
};

/* Function to print an equation */
void print_equation(struct Equation *e) {
    printf("%s: %s = %s\n", e->name, e->expression, e->variables[0]);
    // assumes the equation only has one variable
}

/* Function to create a new equation */
struct Equation *create_equation(char *name, char *expression, char *variable_list) {
    struct Equation *e = malloc(sizeof(struct Equation));
    strcpy(e->name, name);
    strcpy(e->expression, expression);
    char *token = strtok(variable_list, ",");
    int i = 0;
    while (token != NULL) {
        strcpy(e->variables[i], token);
        token = strtok(NULL, ",");
        i++;
    }
    e->num_variables = i;
    return e;
}

/* Function to initialize a database of equations */
void init_equation_db(struct EquationDB *db) {
    struct Equation *e1 = create_equation("Pythagorean Theorem", "a*a + b*b = c*c", "a,b,c");
    struct Equation *e2 = create_equation("Distance Formula", "d = sqrt(pow((x1-x2),2) + pow((y1-y2),2))", "x1,y1,x2,y2,d");
    db->equations = malloc(2 * sizeof(struct Equation));
    db->equations[0] = *e1;
    db->equations[1] = *e2;
    db->num_equations = 2;
}

/* Function to search for an equation by name */
struct Equation *search_equation_by_name(struct EquationDB *db, char *name) {
    for (int i = 0; i < db->num_equations; i++) {
        if (strcmp(db->equations[i].name, name) == 0) {
            return &db->equations[i];
        }
    }
    return NULL;
}

int main() {
    /* Initialize database of equations */
    struct EquationDB db;
    init_equation_db(&db);
    
    /* Query the user for an equation name */
    char name[20];
    printf("Enter an equation name: ");
    scanf("%s", name);
    
    /* Search for the equation in the database */
    struct Equation *e = search_equation_by_name(&db, name);
    
    /* If equation is found, print it */
    if (e != NULL) {
        print_equation(e);
    } else {
        printf("Equation not found.\n");
    }
    
    return 0;
}