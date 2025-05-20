//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 30

// Structure to represent a user
typedef struct User {
    char name[NAME_LENGTH];
    struct User *friends[MAX_USERS]; // Array to hold pointers to friends
    int friend_count;
} User;

// Structure to represent the social network
typedef struct SocialNetwork {
    User *users[MAX_USERS];
    int user_count;
} SocialNetwork;

// Function to create a new user
User* createUser(const char* name) {
    User* newUser = (User*)malloc(sizeof(User));
    strncpy(newUser->name, name, NAME_LENGTH);
    newUser->friend_count = 0;
    return newUser;
}

// Function to initialize a social network
SocialNetwork* createSocialNetwork() {
    SocialNetwork* network = (SocialNetwork*)malloc(sizeof(SocialNetwork));
    network->user_count = 0;
    return network;
}

// Function to add a user
void addUser(SocialNetwork* network, const char* name) {
    if (network->user_count >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }
    User* user = createUser(name);
    network->users[network->user_count++] = user;
    printf("User '%s' added successfully.\n", name);
}

// Function to add a friendship
void addFriendship(SocialNetwork* network, const char* name1, const char* name2) {
    User *user1 = NULL, *user2 = NULL;

    for (int i = 0; i < network->user_count; i++) {
        if (strcmp(network->users[i]->name, name1) == 0) user1 = network->users[i];
        if (strcmp(network->users[i]->name, name2) == 0) user2 = network->users[i];
    }

    if (user1 && user2) {
        user1->friends[user1->friend_count++] = user2;
        user2->friends[user2->friend_count++] = user1; // Make it bidirectional
        printf("Friendship established between '%s' and '%s'.\n", name1, name2);
    } else {
        printf("One or both users not found in the network.\n");
    }
}

// Function to print the social network
void printNetwork(SocialNetwork* network) {
    for (int i = 0; i < network->user_count; i++) {
        User* user = network->users[i];
        printf("%s's friends: ", user->name);
        for (int j = 0; j < user->friend_count; j++) {
            printf("%s", user->friends[j]->name);
            if (j < user->friend_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

// Function to free memory used by the network
void freeNetwork(SocialNetwork* network) {
    for (int i = 0; i < network->user_count; i++) {
        free(network->users[i]);
    }
    free(network);
}

int main() {
    SocialNetwork* network = createSocialNetwork();
    int choice;
    char name1[NAME_LENGTH], name2[NAME_LENGTH];

    while (1) {
        printf("\nSocial Network Menu\n");
        printf("1. Add User\n");
        printf("2. Add Friendship\n");
        printf("3. Print Network\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from buffer

        switch (choice) {
            case 1:
                printf("Enter the username to add: ");
                fgets(name1, NAME_LENGTH, stdin);
                name1[strcspn(name1, "\n")] = 0; // Remove the newline character
                addUser(network, name1);
                break;
            case 2:
                printf("Enter the first friend's name: ");
                fgets(name1, NAME_LENGTH, stdin);
                name1[strcspn(name1, "\n")] = 0;

                printf("Enter the second friend's name: ");
                fgets(name2, NAME_LENGTH, stdin);
                name2[strcspn(name2, "\n")] = 0;

                addFriendship(network, name1, name2);
                break;
            case 3:
                printNetwork(network);
                break;
            case 4:
                freeNetwork(network);
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}