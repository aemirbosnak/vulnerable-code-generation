//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 256
#define MAX_PHONE_LEN 64
#define MAX_ADDRESS_LEN 256

struct phone_book {
    char *name;
    char *phone;
    char *address;
};

int main() {
    struct phone_book *phone_book = (struct phone_book *)malloc(
        sizeof(struct phone_book) * 10); // allocate memory for 10 phone book entries
    int i;

    // dynamic memory allocation for each entry
    for (i = 0; i < 10; i++) {
        phone_book[i].name = (char *)malloc(MAX_NAME_LEN);
        phone_book[i].phone = (char *)malloc(MAX_PHONE_LEN);
        phone_book[i].address = (char *)malloc(MAX_ADDRESS_LEN);

        // prompt user for entry information
        printf("Enter name: ");
        fgets(phone_book[i].name, MAX_NAME_LEN, stdin);
        printf("Enter phone: ");
        fgets(phone_book[i].phone, MAX_PHONE_LEN, stdin);
        printf("Enter address: ");
        fgets(phone_book[i].address, MAX_ADDRESS_LEN, stdin);
    }

    // print out the phone book entries
    for (i = 0; i < 10; i++) {
        printf("Name: %s\nPhone: %s\nAddress: %s\n",
            phone_book[i].name, phone_book[i].phone, phone_book[i].address);
    }

    // free memory for each entry
    for (i = 0; i < 10; i++) {
        free(phone_book[i].name);
        free(phone_book[i].phone);
        free(phone_book[i].address);
    }

    free(phone_book);
    return 0;
}