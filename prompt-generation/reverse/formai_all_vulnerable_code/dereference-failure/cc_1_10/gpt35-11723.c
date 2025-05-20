//FormAI DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count=0;

struct song {
    int ID;
    char title[50];
    char artist[50];
    int rating;
    struct song *next;
}*head;

void addSong() {
    struct song *temp, *traverse;
    temp = (struct song*)malloc(sizeof(struct song));

    printf("Enter the song ID: ");
    scanf("%d",&temp->ID);
    printf("Enter the song title: ");
    scanf("%s",temp->title);
    printf("Enter the artist name: ");
    scanf("%s",temp->artist);
    printf("Enter the song rating out of 10: ");
    scanf("%d",&temp->rating);
    temp->next = NULL;

    if(head == NULL) {
        head = temp;
    } else {
        traverse = head;
        while(traverse->next!=NULL) {
            traverse = traverse->next;
        }
        traverse->next = temp;
    }
}

void searchSong() {
    struct song *traverse;
    int id, flag=0;
    printf("Enter the song ID to search: ");
    scanf("%d",&id);
    traverse = head;
    while(traverse!=NULL) {
        if(traverse->ID==id) {
            printf("\nDetails of Song ID '%d' : ",id);
            printf("\nTitle: %s",traverse->title);
            printf("\nArtist: %s",traverse->artist);
            printf("\nRating: %d",traverse->rating);
            flag = 1;
            break;
        }
        traverse = traverse->next;
    }
    if(flag == 0) {
        printf("\nSong ID not found!");
    }
}

void removeSong() {
    struct song *temp, *prev;
    int id, flag=0;
    printf("Enter the song ID to remove: ");
    scanf("%d",&id);
    temp = head;
    while(temp!=NULL) {
        if(temp->ID==id) {
            if(temp == head) {
                head = head->next;
            } else {
                prev->next = temp->next;
            }
            printf("\nSong with ID '%d' removed successfully!",id);
            flag = 1;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(flag == 0) {
        printf("\nSong ID not found!");
    } else {
        free(temp);
    }
}

void displayMusicLibrary() {
    struct song *traverse;
    if(head == NULL) {
        printf("\nNo songs found in the library!");
    } else {
        printf("\nDetails of song library: ");
        traverse = head;
        while(traverse!=NULL) {
            printf("\n%d - %s (%s) - Rating: %d/10",traverse->ID,traverse->title,traverse->artist,traverse->rating);
            traverse = traverse->next;
        }
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n\n******* C Music Library : Manage your music library with ease. *******");
        printf("\n1. Add Song");
        printf("\n2. Search Song");
        printf("\n3. Remove Song");
        printf("\n4. Display Music Library");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                addSong();
                count++;
                break;
            case 2:
                searchSong();
                break;
            case 3:
                removeSong();
                count--;
                break;
            case 4:
                displayMusicLibrary();
                break;
            case 5:
                printf("\nThank you for using C Music Library! Goodbye!");
                exit(0);
            default:
                printf("\nInvalid Input. Try Again!");
                break;
        }
    }

    return 0;
}