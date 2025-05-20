//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_BOOK_SIZE 100
#define PHONE_NUMBER_LENGTH 10
#define NAME_LENGTH 20

typedef struct phone_book {
    char *names[PHONE_BOOK_SIZE];
    char *phone_numbers[PHONE_BOOK_SIZE][PHONE_NUMBER_LENGTH];
    int size;
} phone_book;

phone_book *create_phone_book(void) {
    phone_book *pb = (phone_book *)malloc(sizeof(phone_book));
    pb->size = PHONE_BOOK_SIZE;
    for (int i = 0; i < PHONE_BOOK_SIZE; i++) {
        pb->names[i] = (char *)malloc(NAME_LENGTH * sizeof(char));
        pb->phone_numbers[i][0] = (char *)malloc(PHONE_NUMBER_LENGTH * sizeof(char));
    }
    return pb;
}

void add_contact(phone_book *pb, char *name, char *phone_number) {
    for (int i = 0; i < pb->size; i++) {
        if (strcmp(pb->names[i], name) == 0) {
            strcpy(pb->phone_numbers[i][0], phone_number);
            return;
        }
    }
    printf("Error: Contact already exists in the phone book.\n");
}

void display_contacts(phone_book *pb) {
    for (int i = 0; i < pb->size; i++) {
        printf("%s %s\n", pb->names[i], pb->phone_numbers[i][0]);
    }
}

int main() {
    srand(time(NULL));
    phone_book *pb = create_phone_book();
    char name[NAME_LENGTH];
    char phone_number[PHONE_NUMBER_LENGTH];
    int i;

    // Add some contacts
    for (i = 0; i < 10; i++) {
        printf("Add contact: ");
        scanf("%s %s", name, phone_number);
        add_contact(pb, name, phone_number);
    }

    // Display all contacts
    display_contacts(pb);

    // Remove some contacts
    for (i = 0; i < 5; i++) {
        printf("Remove contact: ");
        scanf("%s", name);
        for (int j = 0; j < pb->size; j++) {
            if (strcmp(pb->names[j], name) == 0) {
                printf("Removed contact %s %s\n", name, pb->phone_numbers[j][0]);
                for (int k = j; k < pb->size - 1; k++) {
                    strcpy(pb->names[k], pb->names[k + 1]);
                    strcpy(pb->phone_numbers[k][0], pb->phone_numbers[k + 1][0]);
                }
                pb->size--;
                break;
            }
        }
    }

    // Display all contacts again
    display_contacts(pb);

    free(pb);
    return 0;
}