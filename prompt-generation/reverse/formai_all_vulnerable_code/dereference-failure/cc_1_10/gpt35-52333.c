//FormAI DATASET v1.0 Category: Mailing list manager ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to hold info about a subscriber
struct subscriber{
    char name[50];  // Name of subscriber
    char email[50]; // Email ID of subscriber
};

// Function to add a new subscriber to the mailing list
void addSubscriber(struct subscriber *subscribers, int *count){
    char name[50], email[50];
    printf("Enter name:");
    scanf("%s", name);
    printf("Enter email:");
    scanf("%s", email);
    strcpy(subscribers[*count].name, name);
    strcpy(subscribers[*count].email, email);
    *count += 1;
}

// Function to remove a subscriber from the mailing list
int removeSubscriber(struct subscriber *subscribers, int *count){
    char email[50];
    printf("Enter email of subscriber to be removed:");
    scanf("%s", email);
    int i, found = 0;
    for(i=0; i<*count; i++){
        if(strcmp(subscribers[i].email, email)==0){
            found = 1;
            break;
        }
    }
    if(found){
        for(int j=i; j<*count-1; j++){
            subscribers[j] = subscribers[j+1];
        }
        *count -= 1;
        printf("Subscriber %s has been removed.\n", email);
        return 1;
    }
    else{
        printf("Subscriber with email %s not found!\n", email);
        return 0;
    }
}

// Function to print the list of subscribers
void printSubscribers(struct subscriber *subscribers, int count){
    printf("List of subscribers:\n");
    for(int i=0; i<count; i++){
        printf("%s\t%s\n", subscribers[i].name, subscribers[i].email);
    }
}

// Main function
int main(){
    int choice, count = 0, max_count = 100;
    struct subscriber *subscribers = (struct subscriber *) malloc(max_count*sizeof(struct subscriber));
    do{
        printf("\nMenu:\n1. Add Subscriber\n2. Remove Subscriber\n3. Print Subscribers\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                if(count>=max_count){
                    max_count *= 2;
                    subscribers = (struct subscriber *) realloc(subscribers, max_count*sizeof(struct subscriber));
                }
                addSubscriber(subscribers, &count);
                break;
            case 2:
                removeSubscriber(subscribers, &count);
                break;
            case 3:
                printSubscribers(subscribers, count);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!=4);
    free(subscribers);
    return 0;
}