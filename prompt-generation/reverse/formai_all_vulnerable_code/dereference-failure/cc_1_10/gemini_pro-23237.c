//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

struct element {
    int atomic_number;
    char *name;
    char *symbol;
    double atomic_mass;
    char **electron_configuration;
    int num_electron_configurations;
};

struct periodic_table {
    struct element *elements;
    int num_elements;
};

// Create a new periodic table
struct periodic_table *create_periodic_table() {
    struct periodic_table *table = malloc(sizeof(struct periodic_table));
    table->elements = malloc(sizeof(struct element) * 118);
    table->num_elements = 118;

    // Initialize the elements
    for (int i = 0; i < table->num_elements; i++) {
        table->elements[i].atomic_number = i + 1;
        table->elements[i].name = NULL;
        table->elements[i].symbol = NULL;
        table->elements[i].atomic_mass = 0.0;
        table->elements[i].electron_configuration = NULL;
        table->elements[i].num_electron_configurations = 0;
    }

    // Load the element data from a file
    FILE *fp = fopen("periodic_table.csv", "r");
    if (fp == NULL) {
        perror("Error opening periodic table file");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *atomic_number_str = strtok(line, ",");
        char *name = strtok(NULL, ",");
        char *symbol = strtok(NULL, ",");
        char *atomic_mass_str = strtok(NULL, ",");
        char *electron_configuration = strtok(NULL, ",");

        int atomic_number = atoi(atomic_number_str);
        double atomic_mass = atof(atomic_mass_str);

        // Store the element data in the periodic table
        table->elements[atomic_number - 1].name = strdup(name);
        table->elements[atomic_number - 1].symbol = strdup(symbol);
        table->elements[atomic_number - 1].atomic_mass = atomic_mass;

        // Parse the electron configuration
        char *electron_configuration_tokens = strtok(electron_configuration, " ");
        while (electron_configuration_tokens != NULL) {
            table->elements[atomic_number - 1].electron_configuration = realloc(table->elements[atomic_number - 1].electron_configuration, sizeof(char *) * (table->elements[atomic_number - 1].num_electron_configurations + 1));
            table->elements[atomic_number - 1].electron_configuration[table->elements[atomic_number - 1].num_electron_configurations] = strdup(electron_configuration_tokens);
            table->elements[atomic_number - 1].num_electron_configurations++;
            electron_configuration_tokens = strtok(NULL, " ");
        }
    }

    fclose(fp);

    return table;
}

// Free the memory allocated for the periodic table
void free_periodic_table(struct periodic_table *table) {
    for (int i = 0; i < table->num_elements; i++) {
        free(table->elements[i].name);
        free(table->elements[i].symbol);
        for (int j = 0; j < table->elements[i].num_electron_configurations; j++) {
            free(table->elements[i].electron_configuration[j]);
        }
        free(table->elements[i].electron_configuration);
    }
    free(table->elements);
    free(table);
}

// Print the periodic table
void print_periodic_table(struct periodic_table *table) {
    printf("Periodic Table\n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| Atomic | Name | Symbol | Atomic Mass | Electron Configuration |");
    for (int i = 0; i < table->num_elements; i++) {
        printf("\n| %d | %s | %s | %.3f | ", table->elements[i].atomic_number, table->elements[i].name, table->elements[i].symbol, table->elements[i].atomic_mass);
        for (int j = 0; j < table->elements[i].num_electron_configurations; j++) {
            printf("%s ", table->elements[i].electron_configuration[j]);
        }
        printf("|");
    }
    printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

// Get an element by its atomic number
struct element *get_element_by_atomic_number(struct periodic_table *table, int atomic_number) {
    if (atomic_number < 1 || atomic_number > table->num_elements) {
        return NULL;
    }

    return &table->elements[atomic_number - 1];
}

// Get an element by its name
struct element *get_element_by_name(struct periodic_table *table, char *name) {
    for (int i = 0; i < table->num_elements; i++) {
        if (strcmp(table->elements[i].name, name) == 0) {
            return &table->elements[i];
        }
    }

    return NULL;
}

// Get an element by its symbol
struct element *get_element_by_symbol(struct periodic_table *table, char *symbol) {
    for (int i = 0; i < table->num_elements; i++) {
        if (strcmp(table->elements[i].symbol, symbol) == 0) {
            return &table->elements[i];
        }
    }

    return NULL;
}

// Main function
int main() {
    // Create a periodic table
    struct periodic_table *table = create_periodic_table();

    // Print the periodic table
    print_periodic_table(table);

    // Get an element by its atomic number
    struct element *element = get_element_by_atomic_number(table, 1);
    printf("Element with atomic number 1: %s\n", element->name);

    // Get an element by its name
    element = get_element_by_name(table, "Hydrogen");
    printf("Element with name Hydrogen: %s\n", element->symbol);

    // Get an element by its symbol
    element = get_element_by_symbol(table, "H");
    printf("Element with symbol H: %s\n", element->name);

    // Free the memory allocated for the periodic table
    free_periodic_table(table);

    return 0;
}