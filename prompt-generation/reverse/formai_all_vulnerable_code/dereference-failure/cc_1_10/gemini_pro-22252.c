//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// A simple database structure
typedef struct {
    int id;
    char *name;
    int age;
} Person;

// A global database
Person *database = NULL;
int num_records = 0;

// A mutex to protect the database
pthread_mutex_t database_mutex = PTHREAD_MUTEX_INITIALIZER;

// A function to insert a new record into the database
void insert_record(Person *person) {
    // Lock the database
    pthread_mutex_lock(&database_mutex);

    // Allocate memory for the new record
    database = realloc(database, sizeof(Person) * (num_records + 1));

    // Copy the new record into the database
    database[num_records] = *person;

    // Increment the number of records
    num_records++;

    // Unlock the database
    pthread_mutex_unlock(&database_mutex);
}

// A function to delete a record from the database
void delete_record(int id) {
    // Lock the database
    pthread_mutex_lock(&database_mutex);

    // Find the record to delete
    int i;
    for (i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            break;
        }
    }

    // If the record was found, delete it
    if (i < num_records) {
        // Shift the records after the deleted record to the left
        for (int j = i; j < num_records - 1; j++) {
            database[j] = database[j + 1];
        }

        // Decrement the number of records
        num_records--;
    }

    // Unlock the database
    pthread_mutex_unlock(&database_mutex);
}

// A function to update a record in the database
void update_record(Person *person) {
    // Lock the database
    pthread_mutex_lock(&database_mutex);

    // Find the record to update
    int i;
    for (i = 0; i < num_records; i++) {
        if (database[i].id == person->id) {
            break;
        }
    }

    // If the record was found, update it
    if (i < num_records) {
        database[i] = *person;
    }

    // Unlock the database
    pthread_mutex_unlock(&database_mutex);
}

// A function to print the database
void print_database() {
    // Lock the database
    pthread_mutex_lock(&database_mutex);

    // Print the records in the database
    for (int i = 0; i < num_records; i++) {
        printf("%d %s %d\n", database[i].id, database[i].name, database[i].age);
    }

    // Unlock the database
    pthread_mutex_unlock(&database_mutex);
}

// A function to simulate a client thread
void *client_thread(void *arg) {
    // Get the client's ID
    int client_id = *(int *)arg;

    // Generate a random record
    Person person;
    person.id = client_id;
    person.name = malloc(10);
    sprintf(person.name, "Client %d", client_id);
    person.age = rand() % 100;

    // Insert the record into the database
    insert_record(&person);

    // Print the database
    print_database();

    // Delete the record from the database
    delete_record(client_id);

    // Print the database
    print_database();

    // Update the record in the database
    person.age = rand() % 100;
    update_record(&person);

    // Print the database
    print_database();

    return NULL;
}

// The main function
int main() {
    // Create a pool of client threads
    int num_clients = 10;
    pthread_t clients[num_clients];
    int client_ids[num_clients];

    // Create the client threads
    for (int i = 0; i < num_clients; i++) {
        client_ids[i] = i;
        pthread_create(&clients[i], NULL, client_thread, &client_ids[i]);
    }

    // Join the client threads
    for (int i = 0; i < num_clients; i++) {
        pthread_join(clients[i], NULL);
    }

    return 0;
}