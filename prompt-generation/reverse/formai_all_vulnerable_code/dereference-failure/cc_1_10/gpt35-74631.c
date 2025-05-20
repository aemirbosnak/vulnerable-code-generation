//FormAI DATASET v1.0 Category: Music Library Management System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Library {
    char song_title[50];
    char artist_name[50];
    int song_release_year;
    float duration;
    struct Library *next;
};

typedef struct Library node;
node *head = NULL;

node* create_node() {
    node *new_node = (node*) malloc(sizeof(node));
    printf("\nEnter the Song Title: ");
    scanf("%[^\n]%*c", new_node->song_title);
    printf("\nEnter the Artist Name: ");
    scanf("%[^\n]%*c", new_node->artist_name);
    printf("\nEnter the Song Release Year: ");
    scanf("%d", &new_node->song_release_year);
    printf("\nEnter the Song Duration (in seconds): ");
    scanf("%f", &new_node->duration);
    new_node->next = NULL;
    return new_node;
}

void add_song() {
    node *new_node = create_node();
    if(head == NULL) {
        head = new_node;
    }
    else {
        node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("\nSong added successfully!");
}

void display_all() {
    if(head == NULL) {
        printf("\nNo songs found in the library!");
    } 
    else {
        node *temp = head;
        printf("\n%-20s%-20s%-20s%-20s", "Song Title", "Artist Name", "Release Year", "Duration");
        while(temp != NULL) {
            printf("\n%-20s%-20s%-20d%-20.2f", temp->song_title, temp->artist_name, temp->song_release_year, temp->duration);
            temp = temp->next;
        }
    }
}

void search_song() {
    if(head == NULL) {
        printf("\nNo songs found in the library!");
    } 
    else {
        char search_title[50];
        printf("\nEnter the Song Title to be searched: ");
        scanf("%[^\n]%*c", search_title);
        node *temp = head;
        int flag = 0;
        while(temp != NULL) {
            if(strcmp(temp->song_title, search_title) == 0) {
                printf("\n%-20s%-20s%-20s%-20s", "Song Title", "Artist Name", "Release Year", "Duration");
                printf("\n%-20s%-20s%-20d%-20.2f", temp->song_title, temp->artist_name, temp->song_release_year, temp->duration);
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if(flag == 0) {
            printf("\nSong not found in the library!");
        }
    }
}

void update_song() {
    if(head == NULL) {
        printf("\nNo songs found in the library!");
    } 
    else {
        char update_title[50];
        printf("\nEnter the Song Title to be updated: ");
        scanf("%[^\n]%*c", update_title);
        node *temp = head;
        int flag = 0;
        while(temp != NULL) {
            if(strcmp(temp->song_title, update_title) == 0) {
                printf("\nEnter the updated Song Title: ");
                scanf("%[^\n]%*c", temp->song_title);
                printf("\nEnter the updated Artist Name: ");
                scanf("%[^\n]%*c", temp->artist_name);
                printf("\nEnter the updated Song Release Year: ");
                scanf("%d", &temp->song_release_year);
                printf("\nEnter the updated Song Duration (in seconds): ");
                scanf("%f", &temp->duration);
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if(flag == 0) {
            printf("\nSong not found in the library!");
        }
        else {
            printf("\nSong updated successfully!");
        }
    }
}

void delete_song() {
    if(head == NULL) {
        printf("\nNo songs found in the library!");
    } 
    else {
        char delete_title[50];
        printf("\nEnter the Song Title to be deleted: ");
        scanf("%[^\n]%*c", delete_title);
        node *temp1 = head;
        node *temp2 = NULL;
        int flag = 0;
        while(temp1 != NULL) {
            if(strcmp(temp1->song_title, delete_title) == 0) {
                if(temp1 == head) {
                    head = head->next;
                    flag = 1;
                    break;
                }
                else {
                    temp2->next = temp1->next;
                    flag = 1;
                    break;
                }
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if(flag == 0) {
            printf("\nSong not found in the library!");
        }
        else {
            printf("\nSong deleted successfully!");
        }
    }
}

int main() {
    int choice;
    do {
        printf("\n---------------------------");
        printf("\nMusic Library Management System");
        printf("\n---------------------------");
        printf("\n1. Add a song to the Library");
        printf("\n2. Display all songs in the Library");
        printf("\n3. Search for a song");
        printf("\n4. Update a song");
        printf("\n5. Delete a song");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                add_song();
                break;
            }
            case 2: {
                display_all();
                break;
            }
            case 3: {
                search_song();
                break;
            }
            case 4: {
                update_song();
                break;
            }
            case 5: {
                delete_song();
                break;
            }
            case 6: {
                printf("\nThanks for using Music Library Management System!");
                exit(0);
            }
            default: {
                printf("\nInvalid choice! Please enter a valid choice (1-6).");
            }
        }
    }while(choice != 6);
    return 0;
}