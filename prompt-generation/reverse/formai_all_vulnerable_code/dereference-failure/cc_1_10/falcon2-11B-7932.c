//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[20];
    char value[20];
};

struct entry entries[MAX_ENTRIES];

int main() {
    int choice, num, i;
    char input[20];

    printf("Welcome to the Curios Database Simulation!\n");
    printf("Enter 1 to add an entry\n");
    printf("Enter 2 to view all entries\n");
    printf("Enter 3 to search for an entry\n");
    printf("Enter 4 to exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name: ");
                scanf("%s", input);
                printf("Enter the value: ");
                scanf("%s", input);
                strcpy(entries[num].name, input);
                strcpy(entries[num].value, input);
                num++;
                printf("Entry added successfully!\n");
                break;
            case 2:
                printf("Entries:\n");
                for (i = 0; i < num; i++) {
                    printf("Name: %s, Value: %s\n", entries[i].name, entries[i].value);
                }
                break;
            case 3:
                printf("Enter the name to search for: ");
                scanf("%s", input);
                for (i = 0; i < num; i++) {
                    if (strcmp(input, entries[i].name) == 0) {
                        printf("Entry found!\n");
                        printf("Name: %s, Value: %s\n", entries[i].name, entries[i].value);
                    }
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}