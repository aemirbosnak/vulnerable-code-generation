//FormAI DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Entry {
    char *date;
    char *title;
    char *content;
};

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    struct Entry *diary[365];
    int numEntries = 0;

    int choice;
    printf("Welcome to your Digital Diary\n");
    do {
        printf("\nChoose an option:\n");
        printf("1. Add an entry\n");
        printf("2. View an entry\n");
        printf("3. Exit\n");
        
        printf("Enter your choice (1, 2, or 3): ");
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Try again.\n");
            continue;
        }
        
        switch (choice) {
            case 1: {
                if (numEntries >= 365) {
                    printf("Sorry, your diary is full.\n");
                } else {
                    struct Entry *newEntry = malloc(sizeof(struct Entry));
                    printf("Enter the date in the format dd/mm/yyyy: ");
                    char buffer[11];
                    if (scanf("%10s", buffer) != 1) {
                        clearInputBuffer();
                        printf("Invalid input. Try again.\n");
                        free(newEntry);
                        break;
                    }
                    newEntry->date = strdup(buffer);
                    clearInputBuffer();
                    
                    printf("Enter the title: ");
                    char titleBuffer[101];
                    if (fgets(titleBuffer, 101, stdin) == NULL) {
                        printf("Error reading input. Please try again.\n");
                        free(newEntry->date);
                        free(newEntry);
                        break;
                    }
                    titleBuffer[strlen(titleBuffer) - 1] = '\0';  // remove newline character
                    newEntry->title = strdup(titleBuffer);
                    
                    printf("Enter the content:\n");
                    size_t contentSize = 101;
                    char *content = malloc(contentSize * sizeof(char));
                    if (getline(&content, &contentSize, stdin) == -1) {
                        printf("Error reading input.\n");
                        free(newEntry->date);
                        free(newEntry->title);
                        free(newEntry);
                        free(content);
                        break;
                    }
                    newEntry->content = strdup(content);
                    
                    diary[numEntries] = newEntry;
                    numEntries++;
                    printf("Entry added.\n");
                }
                break;
            }
            case 2: {
                printf("Enter the date of the entry you want to view in the format dd/mm/yyyy: ");
                char buffer[11];
                if (scanf("%10s", buffer) != 1) {
                    clearInputBuffer();
                    printf("Invalid input. Try again.\n");
                    break;
                }
            
                for (int i = 0; i < numEntries; i++) {
                    if (strcmp(diary[i]->date, buffer) == 0) {
                        printf("Title: %s\n", diary[i]->title);
                        printf("Content: %s\n", diary[i]->content);
                        break;
                    }
                    if (i == numEntries - 1) {
                        printf("Entry not found.\n");
                    }
                }
                
                break;
            }
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    for (int i = 0; i < numEntries; i++) {
        free(diary[i]->date);
        free(diary[i]->title);
        free(diary[i]->content);
        free(diary[i]);
    }
    
    return 0;
}