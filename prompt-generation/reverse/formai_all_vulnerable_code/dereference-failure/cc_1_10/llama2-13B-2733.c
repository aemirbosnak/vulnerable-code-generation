//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>
#include <utime.h>

#define MAX_NAME_LEN 256
#define MAX_PHONE_NUM_LEN 20
#define MAX_ADDRESS_LEN 1024

struct phone_book {
    char name[MAX_NAME_LEN];
    char phone_number[MAX_PHONE_NUM_LEN];
    char address[MAX_ADDRESS_LEN];
};

struct phone_book *phone_book_create(void) {
    struct phone_book *pb = malloc(sizeof(struct phone_book));
    pb->name[0] = '\0';
    pb->phone_number[0] = '\0';
    pb->address[0] = '\0';
    return pb;
}

void phone_book_add(struct phone_book **phone_book, const char *name, const char *phone_number, const char *address) {
    struct phone_book *pb = *phone_book;
    if (pb == NULL) {
        pb = phone_book_create();
        *phone_book = pb;
    }
    strcpy(pb->name, name);
    strcpy(pb->phone_number, phone_number);
    strcpy(pb->address, address);
}

void phone_book_delete(struct phone_book **phone_book, const char *name) {
    struct phone_book *pb = *phone_book;
    if (pb != NULL) {
        if (strcmp(pb->name, name) == 0) {
            free(pb);
            *phone_book = NULL;
        }
    }
}

void phone_book_print(struct phone_book *phone_book) {
    printf("Phone Book:\n");
    printf("Name: %s\n", phone_book->name);
    printf("Phone Number: %s\n", phone_book->phone_number);
    printf("Address: %s\n", phone_book->address);
}

int main(void) {
    struct phone_book *phone_book = phone_book_create();
    phone_book_add(phone_book, "John Doe", "555-1234", "123 Main St");
    phone_book_add(phone_book, "Jane Doe", "555-5678", "456 Elm St");
    phone_book_print(phone_book);
    phone_book_delete(phone_book, "Jane Doe");
    phone_book_print(phone_book);
    return 0;
}