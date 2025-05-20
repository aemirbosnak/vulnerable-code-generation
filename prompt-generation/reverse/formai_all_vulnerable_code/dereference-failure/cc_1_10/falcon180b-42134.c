//Falcon-180B DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 32
#define MAX_ADDRESS_LEN 64
#define MAX_PHONE_LEN 16

typedef struct {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    char phone[MAX_PHONE_LEN];
} contact;

contact* read_contacts(FILE* file, int* num_contacts) {
    contact* contacts = NULL;
    int count = 0;
    char line[MAX_ADDRESS_LEN];
    while (fgets(line, sizeof(line), file)) {
        if (count >= *num_contacts) {
            fprintf(stderr, "Error: Too many contacts in file.\n");
            exit(1);
        }
        contact new_contact = { 0 };
        sscanf(line, "%s %s %s", new_contact.name, new_contact.address, new_contact.phone);
        contacts = realloc(contacts, sizeof(contact) * ++count);
        contacts[count - 1] = new_contact;
    }
    return contacts;
}

void write_contacts(FILE* file, int num_contacts, contact* contacts) {
    for (int i = 0; i < num_contacts; i++) {
        fprintf(file, "%s %s %s\n", contacts[i].name, contacts[i].address, contacts[i].phone);
    }
}

void sort_contacts(contact* contacts, int num_contacts, int (*compar)(const void*, const void*)) {
    qsort(contacts, num_contacts, sizeof(contact), compar);
}

int compare_name(const void* a, const void* b) {
    contact* contact_a = (contact*)a;
    contact* contact_b = (contact*)b;
    return strcmp(contact_a->name, contact_b->name);
}

int main() {
    FILE* file = fopen("contacts.txt", "r+");
    if (!file) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(1);
    }
    int num_contacts = 0;
    contact* contacts = read_contacts(file, &num_contacts);
    sort_contacts(contacts, num_contacts, compare_name);
    write_contacts(file, num_contacts, contacts);
    free(contacts);
    fclose(file);
    return 0;
}