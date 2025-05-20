//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <string.h>

#define MAX_PHONEBOOK_SIZE 100

struct PhoneBookEntry {
    char name[50];
    char phoneNumber[15];
};

struct PhoneBookEntry phoneBook[MAX_PHONEBOOK_SIZE];
int phoneBookSize = 0;

int main() {
    printf("Phone Book Example Program\n");
    
    printf("1. Add entry\n");
    printf("2. Delete entry\n");
    printf("3. Search entry\n");
    printf("4. Display all entries\n");
    printf("5. Exit\n");
    
    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(phoneBook[phoneBookSize].name, sizeof(phoneBook[phoneBookSize].name), stdin);
                printf("Enter phone number: ");
                fgets(phoneBook[phoneBookSize].phoneNumber, sizeof(phoneBook[phoneBookSize].phoneNumber), stdin);
                
                phoneBookSize++;
                break;
            case 2:
                printf("Enter name to delete: ");
                fgets(phoneBook[--phoneBookSize].name, sizeof(phoneBook[phoneBookSize].name), stdin);
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(phoneBook[--phoneBookSize].name, sizeof(phoneBook[phoneBookSize].name), stdin);
                
                printf("Name: %s\n", phoneBook[--phoneBookSize].name);
                printf("Phone number: %s\n", phoneBook[--phoneBookSize].phoneNumber);
                break;
            case 4:
                printf("Name\t\t\tPhone Number\n");
                
                for (int i = 0; i < phoneBookSize; i++) {
                    printf("%s\t\t\t%s\n", phoneBook[i].name, phoneBook[i].phoneNumber);
                }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}