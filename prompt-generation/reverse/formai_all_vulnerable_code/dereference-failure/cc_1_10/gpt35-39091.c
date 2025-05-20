//FormAI DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Subscriber{
    char name[50];
    char email[50];
    bool isActive;
} Subscriber;

Subscriber *database[100];
int numSubscribers = 0;

void addSubscriber(){
    Subscriber *newSubscriber = malloc(sizeof(Subscriber));

    printf("Enter name: ");
    scanf("%s", newSubscriber->name);

    printf("Enter email: ");
    scanf("%s", newSubscriber->email);

    newSubscriber->isActive = true;

    database[numSubscribers] = newSubscriber;
    numSubscribers++;
    printf("Subscriber added successfully!\n");
}

void removeSubscriber(){
    char email[50];
    printf("Enter the email address of the subscriber to remove: ");
    scanf("%s", email);

    bool found = false;
    for(int i = 0; i < numSubscribers; i++){
        if(strcmp(database[i]->email, email) == 0){
            database[i]->isActive = false;
            found = true;
            printf("Subscriber removed successfully!\n");
            break;
        }
    }

    if(!found) printf("Subscriber not found.\n");

}

int countActiveSubscribers(){
    int count = 0;
    for(int i = 0; i < numSubscribers; i++){
        if(database[i]->isActive) count++;
    }

    return count;
}

void printActiveSubscribers(){
    printf("Active subscribers:\n");
    for(int i = 0; i < numSubscribers; i++){
        if(database[i]->isActive) printf("%s (%s)\n", database[i]->name, database[i]->email);
    }
}

int main(){

    while(true){
        int input;
        printf("Mailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Count Active Subscribers\n");
        printf("4. Print Active Subscribers\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &input);

        switch(input){
            case 1:
                addSubscriber();
                break;
            case 2:
                removeSubscriber();
                break;
            case 3:
                printf("Active subscriber count: %d\n", countActiveSubscribers());
                break;
            case 4:
                printActiveSubscribers();
                break;
            case 5:
                exit(0);
        }

        printf("\n");

    }

    return 0;
}