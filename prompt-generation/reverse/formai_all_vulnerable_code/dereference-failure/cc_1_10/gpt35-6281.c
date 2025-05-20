//FormAI DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct song{
    char title[30];
    char artist[30];
    char album[30];
    double duration;
    int year;
};

struct node{
    struct song s;
    struct node *next;
} *head=NULL;

void add_song(){
    //function to add a new song to the library
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter song title: ");
    scanf("%s",temp->s.title);
    printf("\nEnter song artist: ");
    scanf("%s",temp->s.artist);
    printf("\nEnter song album: ");
    scanf("%s",temp->s.album);
    printf("\nEnter song duration (in minutes): ");
    scanf("%lf",&temp->s.duration);
    printf("\nEnter song release year: ");
    scanf("%d",&temp->s.year);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct node *temp2=head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
    printf("\nSong added to library!\n");
}

void delete_song(){
    //function to delete a song from the library
    if(head==NULL){
        printf("\nMusic library is empty!\n");
        return;
    }
    char title[30];
    printf("\nEnter the title of the song you want to delete: ");
    scanf("%s",title);
    if(strcmp(head->s.title,title)==0){
        struct node *temp=head->next;
        free(head);
        head=temp;
        printf("\nSong deleted from library!\n");
        return;
    }
    struct node *temp2=head;
    while(temp2->next!=NULL && strcmp(temp2->next->s.title,title)!=0){
        temp2=temp2->next;
    }
    if(temp2->next==NULL){
        printf("\nSong not found in library!\n");
        return;
    }
    struct node *temp3=temp2->next->next;
    free(temp2->next);
    temp2->next=temp3;
    printf("\nSong deleted from library!\n");
}

void search_song(){
    //function to search for a particular song in the library
    if(head==NULL){
        printf("\nMusic library is empty!\n");
        return;
    }
    char title[30];
    printf("\nEnter the title of the song to search for: ");
    scanf("%s",title);
    struct node *temp=head;
    while(temp!=NULL){
        if(strcmp(temp->s.title,title)==0){
            printf("\nSong Found\nTitle: %s\nArtist: %s\nAlbum: %s\nDuration: %lf minutes\nYear: %d\n",temp->s.title,temp->s.artist,temp->s.album,temp->s.duration,temp->s.year);
            return;
        }
        temp=temp->next;
    }
    printf("\nSong not found in library!\n");
}

void display_all(){
    //function to display all the songs in the library
    if(head==NULL){
        printf("\nMusic library is empty!\n");
        return;
    }
    struct node *temp=head;
    while(temp!=NULL){
        printf("\nTitle: %s\nArtist: %s\nAlbum: %s\nDuration: %lf minutes\nYear: %d\n",temp->s.title,temp->s.artist,temp->s.album,temp->s.duration,temp->s.year);
        temp=temp->next;
    }
}

int main(){
    int choice;
    do{
        printf("\nWelcome to the Music Library Management System!\n");
        printf("1. Add Song\n2. Delete Song\n3. Search Song\n4. Display All Songs\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: add_song();
                    break;
            case 2: delete_song();
                    break;
            case 3: search_song();
                    break;
            case 4: display_all();
                    break;
            case 5: printf("\nThank you for using the Music Library Management System!\n");
                    break;
            default: printf("\nInvalid choice! Please enter a valid choice.\n");
        }
    }while(choice!=5);
    return 0;
}