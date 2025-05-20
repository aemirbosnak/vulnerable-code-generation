//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the number of rows and columns in the periodic table
#define NUM_ROWS 17
#define NUM_COLS 18

// Define the table of element names
char **element_names = NULL;

// Define the table of element symbols
char **element_symbols = NULL;

// Define the table of element atomic numbers
int **element_atomic_numbers = NULL;

// Define the table of element properties
double **element_properties = NULL;

void initialize_periodic_table()
{
    // Allocate memory for the tables
    element_names = malloc(NUM_ROWS * sizeof(char *));
    element_symbols = malloc(NUM_ROWS * sizeof(char *));
    element_atomic_numbers = malloc(NUM_ROWS * sizeof(int *));
    element_properties = malloc(NUM_ROWS * sizeof(double *));

    // Initialize the tables
    for (int i = 0; i < NUM_ROWS; i++)
    {
        element_names[i] = malloc(NUM_COLS * sizeof(char));
        element_symbols[i] = malloc(NUM_COLS * sizeof(char));
        element_atomic_numbers[i] = malloc(NUM_COLS * sizeof(int));
        element_properties[i] = malloc(NUM_COLS * sizeof(double));
    }
}

void print_periodic_table()
{
    // Print the table header
    printf("<table>\n");
    printf("<thead>\n");
    printf("<tr>\n");
    printf("<th>Element Name</th>\n");
    printf("<th>Symbol</th>\n");
    printf("<th>Atomic Number</th>\n");
    printf("<th>Properties</th>\n");
    printf("</tr>\n");
    printf("</thead>\n");

    // Print the table data
    for (int i = 0; i < NUM_ROWS; i++)
    {
        printf("<tr>\n");
        printf("<td>%s</td>\n", element_names[i]);
        printf("<td>%s</td>\n", element_symbols[i]);
        printf("<td>%d</td>\n", element_atomic_numbers[i]);
        printf("<td>%f</td>\n", element_properties[i]);
        printf("</tr>\n");
    }

    // Print the table footer
    printf("</table>\n");
}

int main()
{
    initialize_periodic_table();
    print_periodic_table();

    return 0;
}