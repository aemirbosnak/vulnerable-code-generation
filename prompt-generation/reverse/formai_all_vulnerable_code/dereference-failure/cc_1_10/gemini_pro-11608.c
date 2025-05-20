//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database structure
typedef struct {
    char *name;
    int age;
    char *city;
} Person;

// Database index structure
typedef struct {
    char *field;
    int *values;
    int count;
} Index;

// Create a new database
Person *create_database(int size) {
    Person *database = malloc(sizeof(Person) * size);
    for (int i = 0; i < size; i++) {
        database[i].name = NULL;
        database[i].age = 0;
        database[i].city = NULL;
    }
    return database;
}

// Destroy a database
void destroy_database(Person *database, int size) {
    for (int i = 0; i < size; i++) {
        if (database[i].name != NULL) {
            free(database[i].name);
        }
        if (database[i].city != NULL) {
            free(database[i].city);
        }
    }
    free(database);
}

// Add a person to the database
void add_person(Person *database, int index, char *name, int age, char *city) {
    database[index].name = strdup(name);
    database[index].age = age;
    database[index].city = strdup(city);
}

// Create a new index on a field
Index *create_index(char *field) {
    Index *index = malloc(sizeof(Index));
    index->field = strdup(field);
    index->values = NULL;
    index->count = 0;
    return index;
}

// Destroy an index
void destroy_index(Index *index) {
    if (index->values != NULL) {
        free(index->values);
    }
    free(index->field);
    free(index);
}

// Add a value to an index
void add_index_value(Index *index, int value) {
    index->values = realloc(index->values, sizeof(int) * (index->count + 1));
    index->values[index->count++] = value;
}

// Find all persons with a given value for a field
Person *find_persons_by_index(Person *database, int size, Index *index, int value) {
    Person *results = malloc(sizeof(Person) * size);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(index->field, "name") == 0 && strcmp(database[i].name, (char *) value) == 0) {
            results[count++] = database[i];
        } else if (strcmp(index->field, "age") == 0 && database[i].age == value) {
            results[count++] = database[i];
        } else if (strcmp(index->field, "city") == 0 && strcmp(database[i].city, (char *) value) == 0) {
            results[count++] = database[i];
        }
    }
    return results;
}

// Print a database
void print_database(Person *database, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s, %d, %s\n", database[i].name, database[i].age, database[i].city);
    }
}

// Print an index
void print_index(Index *index) {
    printf("%s: ", index->field);
    for (int i = 0; i < index->count; i++) {
        printf("%d, ", index->values[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create a database
    Person *database = create_database(10);

    // Add persons to the database
    add_person(database, 0, "John", 30, "New York");
    add_person(database, 1, "Jane", 25, "London");
    add_person(database, 2, "Bob", 40, "Paris");
    add_person(database, 3, "Alice", 35, "Berlin");
    add_person(database, 4, "Tom", 28, "Rome");
    add_person(database, 5, "Mary", 32, "Madrid");
    add_person(database, 6, "Dave", 42, "Amsterdam");
    add_person(database, 7, "Susan", 38, "Vienna");
    add_person(database, 8, "Mark", 29, "Prague");
    add_person(database, 9, "Linda", 34, "Budapest");

    // Create indexes on the fields
    Index *name_index = create_index("name");
    Index *age_index = create_index("age");
    Index *city_index = create_index("city");

    // Add values to the indexes
    for (int i = 0; i < 10; i++) {
        add_index_value(name_index, i);
        add_index_value(age_index, database[i].age);
        add_index_value(city_index, i);
    }

    // Print the database
    printf("Database:\n");
    print_database(database, 10);

    // Print the indexes
    printf("\nIndexes:\n");
    print_index(name_index);
    print_index(age_index);
    print_index(city_index);

    // Find persons by index
    Person *results = find_persons_by_index(database, 10, name_index, "John");

    // Print the results
    printf("\nResults:\n");
    print_database(results, 1);

    // Destroy the database
    destroy_database(database, 10);

    // Destroy the indexes
    destroy_index(name_index);
    destroy_index(age_index);
    destroy_index(city_index);

    return 0;
}