//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[32];
    char phone[16];
} phone_entry;

phone_entry phone_book[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *name, char *phone) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }

    strcpy(phone_book[num_entries].name, name);
    strcpy(phone_book[num_entries].phone, phone);
    num_entries++;
}

void remove_entry(char *name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            for (; i < num_entries - 1; i++) {
                phone_book[i] = phone_book[i + 1];
            }

            num_entries--;
            return;
        }
    }

    printf("Entry not found!\n");
}

void print_phone_book() {
    int i;

    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].phone);
    }
}

int main() {
    char input[80];
    char *name, *phone;

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "add", 3) == 0) {
            name = strtok(input + 4, " ");
            phone = strtok(NULL, "\n");
            add_entry(name, phone);
        } else if (strncmp(input, "remove", 6) == 0) {
            name = strtok(input + 7, "\n");
            remove_entry(name);
        } else if (strncmp(input, "print", 5) == 0) {
            print_phone_book();
        } else if (strncmp(input, "quit", 4) == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}