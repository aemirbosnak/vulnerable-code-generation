//FormAI DATASET v1.0 Category: Database simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_DB_SIZE 100 // maximum size of our database
#define MAX_STRING_LENGTH 20 // maximum length of each string

// struct to represent each entry in the database
typedef struct {
    int id;
    char data[MAX_STRING_LENGTH];
} Entry;

Entry database[MAX_DB_SIZE]; // our database array
pthread_mutex_t db_mutex; // mutex lock to ensure thread safety
int db_size = 0; // current size of the database
int next_id = 0; // next available ID for a new database entry

// function to randomly generate a string of characters
void generate_string(char *str, int length) {
    int i;
    for (i = 0; i < length; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    str[length] = '\0';
}

// function to insert a new entry into the database
void insert_entry(char *data) {
    pthread_mutex_lock(&db_mutex); // lock the mutex before accessing the database

    // create a new Entry struct with the provided data and the next available ID
    Entry new_entry;
    new_entry.id = next_id;
    strcpy(new_entry.data, data);

    // add the new entry to the database
    database[db_size] = new_entry;
    db_size++;
    next_id++;

    pthread_mutex_unlock(&db_mutex); // unlock the mutex after accessing the database
}

// function to remove an entry from the database by ID
void remove_entry(int id) {
    pthread_mutex_lock(&db_mutex); // lock the mutex before accessing the database

    // iterate through the database and remove the entry with the provided ID
    int i, j;
    for (i = 0; i < db_size; i++) {
        if (database[i].id == id) {
            // shift all entries after the removed entry down one index
            for (j = i; j < db_size - 1; j++) {
                database[j] = database[j + 1];
            }
            db_size--;
            break;
        }
    }

    pthread_mutex_unlock(&db_mutex); // unlock the mutex after accessing the database
}

// function to print out all entries in the database
void print_database() {
    pthread_mutex_lock(&db_mutex); // lock the mutex before accessing the database

    // iterate through the database and print each entry to the console
    int i;
    printf("Database Contents:\n");
    for (i = 0; i < db_size; i++) {
        printf("ID: %d, Data: %s\n", database[i].id, database[i].data);
    }

    pthread_mutex_unlock(&db_mutex); // unlock the mutex after accessing the database
}

// function to simulate adding entries to the database
void *add_entries(void *args) {
    int i;
    for (i = 0; i < 10; i++) {
        char data[MAX_STRING_LENGTH];
        generate_string(data, MAX_STRING_LENGTH);
        insert_entry(data);
        printf("Added entry with ID %d\n", next_id - 1);
        usleep(1000000); // sleep for 1 second between each insertion
    }
    return NULL;
}

// function to simulate removing entries from the database
void *remove_entries(void *args) {
    int i;
    for (i = 0; i < 5; i++) {
        int id = rand() % next_id;
        remove_entry(id);
        printf("Removed entry with ID %d\n", id);
        usleep(2000000); // sleep for 2 seconds between each removal
    }
    return NULL;
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // initialize the mutex lock
    if (pthread_mutex_init(&db_mutex, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    // create two threads to simulate adding and removing entries from the database
    pthread_t add_thread, remove_thread;
    if (pthread_create(&add_thread, NULL, add_entries, NULL) != 0) {
        printf("Thread creation failed.\n");
        return 1;
    }
    if (pthread_create(&remove_thread, NULL, remove_entries, NULL) != 0) {
        printf("Thread creation failed.\n");
        return 1;
    }

    // wait for both threads to finish executing
    if (pthread_join(add_thread, NULL) != 0) {
        printf("Thread join failed.\n");
        return 1;
    }
    if (pthread_join(remove_thread, NULL) != 0) {
        printf("Thread join failed.\n");
        return 1;
    }

    // print out the final contents of the database
    print_database();

    return 0;
}