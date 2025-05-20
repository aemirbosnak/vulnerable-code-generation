//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define constants
#define MAX_PASSWORD_LENGTH 50
#define INITIAL_PASSWORD_CAPACITY 10

// Define data structures
typedef struct {
    char* buffer;
    int capacity;
    int length;
} Password;

typedef struct {
    Password* passwords;
    int size;
    int capacity;
    pthread_mutex_t mutex;
} PasswordDatabase;

// Define functions
void init_password(Password* p) {
    p->buffer = malloc(INITIAL_PASSWORD_CAPACITY * sizeof(char));
    p->capacity = INITIAL_PASSWORD_CAPACITY;
    p->length = 0;
}

void add_char(Password* p, char c) {
    if (p->length >= p->capacity - 1) {
        p->capacity *= 2;
        p->buffer = realloc(p->buffer, p->capacity * sizeof(char));
    }
    p->buffer[p->length] = c;
    p->length++;
}

void add_password(PasswordDatabase* db, Password* p) {
    pthread_mutex_lock(&db->mutex);
    if (db->size >= db->capacity) {
        db->capacity *= 2;
        db->passwords = realloc(db->passwords, db->capacity * sizeof(Password));
    }
    db->passwords[db->size] = *p;
    db->size++;
    pthread_mutex_unlock(&db->mutex);
}

void* input_thread(void* arg) {
    PasswordDatabase* db = (PasswordDatabase*) arg;
    char c;
    Password p;
    init_password(&p);
    printf("Enter password (press enter to submit):\n");
    while ((c = getchar()) != '\n') {
        add_char(&p, c);
    }
    add_password(db, &p);
    printf("Password added to database!\n");
    return NULL;
}

void* output_thread(void* arg) {
    PasswordDatabase* db = (PasswordDatabase*) arg;
    while (1) {
        pthread_mutex_lock(&db->mutex);
        printf("Current passwords in database:\n");
        for (int i = 0; i < db->size; i++) {
            printf("%s\n", db->passwords[i].buffer);
        }
        pthread_mutex_unlock(&db->mutex);
        sleep(5);
    }
    return NULL;
}

int main() {
    PasswordDatabase db;
    db.passwords = malloc(INITIAL_PASSWORD_CAPACITY * sizeof(Password));
    db.size = 0;
    db.capacity = INITIAL_PASSWORD_CAPACITY;
    pthread_mutex_init(&db.mutex, NULL);

    pthread_t input_thread_id, output_thread_id;

    pthread_create(&input_thread_id, NULL, input_thread, &db);
    pthread_create(&output_thread_id, NULL, output_thread, &db);

    pthread_join(input_thread_id, NULL);
    pthread_join(output_thread_id, NULL);

    pthread_mutex_destroy(&db.mutex);
    free(db.passwords);

    return 0;
}