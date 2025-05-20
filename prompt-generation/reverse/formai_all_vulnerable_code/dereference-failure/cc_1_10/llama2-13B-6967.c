//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_NAME_LEN 256
#define MAX_PHONE_NUMBER_LEN 32

struct phone_book {
    char name[MAX_NAME_LEN];
    char phone_number[MAX_PHONE_NUMBER_LEN];
};

int main() {
    // Create a shared memory segment for the phone book
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, sizeof(struct phone_book), IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        return 1;
    }

    // Fill the shared memory with some sample data
    struct phone_book *phone_book = shmat(shmid, NULL, 0);
    if (phone_book == NULL) {
        perror("shmat() failed");
        return 1;
    }

    strcpy(phone_book->name, "John Doe");
    strcpy(phone_book->phone_number, "555-1234");

    // Invade the phone book!
    char *name = "Jane Doe";
    char *phone_number = "555-5678";
    strcpy(phone_book->name, name);
    strcpy(phone_book->phone_number, phone_number);

    // Now, let's make some changes to the phone book...
    phone_book->name[0] = 'J';
    phone_book->name[1] = 'e';
    phone_book->name[2] = 'n';
    phone_book->name[3] = 'e';
    phone_book->phone_number[0] = '5';
    phone_book->phone_number[1] = '6';
    phone_book->phone_number[2] = '7';
    phone_book->phone_number[3] = '8';

    // ...and add some new entries!
    struct phone_book new_entry;
    strcpy(new_entry.name, "Bob Smith");
    strcpy(new_entry.phone_number, "555-9012");
    if (shmat(shmid, &new_entry, 0) < 0) {
        perror("shmat() failed");
        return 1;
    }

    // Now, let's check if the shared memory is still valid...
    if (shmctl(shmid, IPC_STAT, NULL) < 0) {
        perror("shmctl() failed");
        return 1;
    }

    // ...and print out the contents of the phone book!
    printf("Phone book contents:\n");
    printf("Name: %s\n", phone_book->name);
    printf("Phone number: %s\n", phone_book->phone_number);
    printf("New entry:\n");
    printf("Name: %s\n", new_entry.name);
    printf("Phone number: %s\n", new_entry.phone_number);

    // Clean up and exit
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}