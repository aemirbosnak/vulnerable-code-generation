//FormAI DATASET v1.0 Category: Database simulation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Surreal Database Simulation
// The database is a collection of dreams, each with its own unique and surreal content.
// The records are stored as linked lists of dream structures.

// dream structure
typedef struct dream{
    char content[100];
    char symbol[20];
    int length;
    struct dream *next;
} Dream;

// display dream function
void display_dream(Dream *d){
    printf("-------------------------\n");
    printf("Symbol: %s\n", d->symbol);
    printf("Content: %s\n", d->content);
    printf("Length: %d\n", d->length);
}

// display all dreams function
void display_all_dreams(Dream *head){
    Dream *current = head;
    while(current != NULL){
        display_dream(current);
        current = current->next;
    }
}

int main(){
    srand(time(NULL));
    Dream *head = NULL;
    Dream *tail = NULL;

    // add dreams to the database
    for(int i=0; i<10; i++){
        Dream *new_dream = (Dream*)malloc(sizeof(Dream));

        // generate a random symbol
        char symbols[5][20] = {"∞", "☂", "▼", "≤", "♡"};
        int symbol_index = rand() % 5;
        strcpy(new_dream->symbol, symbols[symbol_index]);

        // generate a random content
        char contents[10][100] = {"I was riding a giant snail through the desert.",
                                  "I was shopping for clouds at a supermarket.",
                                  "I was having a tea party with aliens.",
                                  "I was floating in a sea of jellybeans.",
                                  "I was painting a portrait of a talking tree.",
                                  "I was dancing with a giant banana.",
                                  "I was playing hide and seek with a purple elephant.",
                                  "I was climbing a staircase made of rainbow.",
                                  "I was swimming in a pool of melted cheese.",
                                  "I was petting a dragon with soft fur."};
        int content_index = rand() % 10;
        strcpy(new_dream->content, contents[content_index]);

        // calculate length of content
        new_dream->length = strlen(new_dream->content);

        // set the next pointer to NULL
        new_dream->next = NULL;

        // add the new dream to the linked list
        if(head == NULL){
            head = new_dream;
            tail = new_dream;
        }
        else{
            tail->next = new_dream;
            tail = new_dream;
        }
    }

    // display all dreams
    printf("All Dreams:\n");
    display_all_dreams(head);

    return 0;
}