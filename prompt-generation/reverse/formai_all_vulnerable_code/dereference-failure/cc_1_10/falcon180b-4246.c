//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float weight;
} User;

void createUser(User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight: ");
    scanf("%f", &user->weight);
}

void displayUser(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %.2f kg\n", user.weight);
}

void updateUser(User *user) {
    printf("Enter your new weight: ");
    scanf("%f", &user->weight);
}

void deleteUser(User *user) {
    printf("Deleting user %s...\n", user->name);
    free(user);
}

void menu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Create a new user\n");
    printf("2. Display user information\n");
    printf("3. Update user weight\n");
    printf("4. Delete a user\n");
    printf("5. Exit\n");
}

int main() {
    User user;
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createUser(&user);
                printf("User created successfully!\n");
                break;
            case 2:
                displayUser(user);
                break;
            case 3:
                updateUser(&user);
                printf("User weight updated successfully!\n");
                break;
            case 4:
                deleteUser(&user);
                printf("User deleted successfully!\n");
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while(choice!= 5);

    return 0;
}