//FormAI DATASET v1.0 Category: Browser Plugin ; Style: realistic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 100

typedef struct Bookmark {
    char url[MAX_URL_LENGTH];
    char title[50];
    struct Bookmark *next;
} Bookmark;

Bookmark *head = NULL;

void printMenu() {
    printf("\n---- C Browser Plugin ----\n");
    printf("1. Add Bookmark\n");
    printf("2. Delete Bookmark\n");
    printf("3. View Bookmarks\n");
    printf("4. Exit\n");
}

void addBookmark() {
    Bookmark *newBookmark = (Bookmark*)malloc(sizeof(Bookmark));
    printf("\nEnter URL: ");
    scanf("%s", newBookmark->url);
    printf("Enter Title: ");
    scanf("%s", newBookmark->title);
    newBookmark->next = head;
    head = newBookmark;
    printf("Bookmark added successfully.\n");
}

bool deleteBookmark(char url[]) {
    Bookmark *current = head;
    Bookmark *previous = NULL;
    while(current != NULL) {
        if(strcmp(current->url, url) == 0) {
            if(previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Bookmark deleted successfully.\n");
            return true;
        }
        previous = current;
        current = current->next;
    }
    printf("Bookmark not found.\n");
    return false;
}

void viewBookmarks() {
    Bookmark *current = head;
    printf("\n---- Bookmarks ----\n");
    while(current != NULL) {
        printf("%s - %s\n", current->title, current->url);
        current = current->next;
    }
}

int main() {
    int choice;
    char url[MAX_URL_LENGTH];
    do {
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addBookmark();
                break;
            case 2:
                printf("\nEnter URL to delete: ");
                scanf("%s", url);
                deleteBookmark(url);
                break;
            case 3:
                viewBookmarks();
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
    return 0;
}