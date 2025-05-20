//FormAI DATASET v1.0 Category: Music Library Management System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Node structure to store music library information
struct music_library{
    char song_name[100];
    char artist_name[100];
    int rating;
    struct music_library* next;
};

// function prototypes
void add_song(struct music_library** headRef);
void display(struct music_library* head);
void search_song(struct music_library* head, char name[]);
void edit_rating(struct music_library* head, char name[], int new_rating);
void delete_song(struct music_library** headRef, char name[]);

int main(){
    struct music_library* head = NULL;
    int choice, new_rating;
    char song_name[100], artist_name[100];

    // display menu options
    while(1){
        printf("\n");
        printf("------C MUSIC LIBRARY MANAGEMENT SYSTEM------\n");
        printf("1. Add song\n");
        printf("2. Display all songs\n");
        printf("3. Search song\n");
        printf("4. Edit song rating\n");
        printf("5. Delete song\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: add_song(&head);
                    break;
            case 2: display(head);
                    break;
            case 3: printf("Enter the name of song to be searched: ");
                    scanf("%s", song_name);
                    search_song(head, song_name);
                    break;
            case 4: printf("Enter the name of song to edit rating: ");
                    scanf("%s", song_name);
                    printf("Enter the new rating: ");
                    scanf("%d", &new_rating);
                    edit_rating(head, song_name, new_rating);
                    break;
            case 5: printf("Enter the name of song to delete: ");
                    scanf("%s", song_name);
                    delete_song(&head, song_name);
                    break;
            case 6: printf("Exiting the program...");
                    exit(0);
                    break;
            default: printf("Invalid choice! Try again.\n");
                     break;
        }
    }

    return 0;
}

// function to add a new song to the music library
void add_song(struct music_library** headRef){
    struct music_library* new_node = (struct music_library*) malloc(sizeof(struct music_library));
    printf("Enter the name of the song: ");
    scanf("%s", new_node->song_name);
    printf("Enter the name of the artist: ");
    scanf("%s", new_node->artist_name);
    printf("Enter the rating (out of 10): ");
    scanf("%d", &new_node->rating);
    new_node->next = *headRef;
    *headRef = new_node;
}

// function to display the entire music library
void display(struct music_library* head){
    if(head == NULL){
        printf("No songs found in the library!\n");
    }
    else{
        printf("-------MUSIC LIBRARY-------\n");
        while(head != NULL){
            printf("Song name: %s\n", head->song_name);
            printf("Artist name: %s\n", head->artist_name);
            printf("Rating: %d/10\n\n", head->rating);
            head = head->next;
        }
    }
}

// function to search for a specific song and display its information
void search_song(struct music_library* head, char name[]){
    struct music_library* temp = head;
    while(temp != NULL){
        if(strcmp(temp->song_name, name) == 0){
            printf("Song name: %s\n", temp->song_name);
            printf("Artist name: %s\n", temp->artist_name);
            printf("Rating: %d/10\n\n", temp->rating);
            return;
        }
        temp = temp->next;
    }
    printf("Song not found!\n");
}

// function to edit the rating of a specific song
void edit_rating(struct music_library* head, char name[], int new_rating){
    struct music_library* temp = head;
    while(temp != NULL){
        if(strcmp(temp->song_name, name) == 0){
            temp->rating = new_rating;
            printf("Rating of song '%s' changed to %d/10 successfully!\n", name, new_rating);
            return;
        }
        temp = temp->next;
    }
    printf("Song not found!\n");
}

// function to delete a specific song from the music library
void delete_song(struct music_library** headRef, char name[]){
    struct music_library* temp = *headRef;
    struct music_library* prev = NULL;
    while(temp != NULL){
        if(strcmp(temp->song_name, name) == 0){
            if(prev == NULL){
                *headRef = temp->next;
            }
            else{
                prev->next = temp->next;
            }
            printf("Song '%s' deleted successfully!\n", name);
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Song not found!\n");
}