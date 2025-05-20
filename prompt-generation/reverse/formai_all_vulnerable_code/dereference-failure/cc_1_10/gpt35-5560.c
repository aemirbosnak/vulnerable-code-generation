//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* email;
} contact_t;

void* read_csv(char* file_name, size_t* num_contacts) {
    FILE* file = fopen(file_name, "r");
    
    if (!file) {
        printf("Unable to open file.\n");
        return NULL;
    }
    
    char buffer[1024];
    void* contacts = NULL;
    size_t count = 0;
    
    while (fgets(buffer, sizeof(buffer), file)) {
        char* name = strtok(buffer, ",");
        char* email = strtok(NULL, ",");
        
        contact_t* contact = (contact_t*)realloc(contacts, sizeof(contact_t) * (count + 1));
        
        if (!contact) {
            printf("Memory allocation failed.\n");
            free(contacts);
            fclose(file);
            return NULL;
        }
        
        contacts = contact;
        contact[count].name = strdup(name);
        contact[count].email = strdup(email);
        count++;
    }
    
    fclose(file);
    *num_contacts = count;
    return contacts;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please specify the name of the file to be read.\n");
        return 0;
    }
    
    size_t num_contacts;
    contact_t* contacts = read_csv(argv[1], &num_contacts);
    
    if (!contacts) {
        printf("Failed to read Contacts from CSV.\n");
        return 0;
    }
    
    printf("\nContacts\n\n");
    printf("%-20s %-20s\n", "Name", "Email");
    
    for (size_t i = 0; i < num_contacts; i++) {
        printf("%-20s %-20s\n", contacts[i].name, contacts[i].email);
    }
    
    for (size_t i = 0; i < num_contacts; i++) {
        free(contacts[i].name);
        free(contacts[i].email);
    }
    
    free(contacts);
    
    return 0;
}