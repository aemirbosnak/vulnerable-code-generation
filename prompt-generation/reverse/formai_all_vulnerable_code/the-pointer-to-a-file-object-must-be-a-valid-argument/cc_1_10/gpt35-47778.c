//FormAI DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 50
#define MAX_PASSWORD_LENGTH 16

struct User {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void writeToFile(struct User users[]) {
    FILE *fp;
    fp = fopen("passwords.txt", "w");
    for(int i=0; i<MAX_USERS; i++) {
        if(users[i].username[0] != '\0' && users[i].password[0] != '\0') {
            fprintf(fp, "%s:%s\n", users[i].username, users[i].password);
        }
    }
    fclose(fp);
}

void readFromFile(struct User users[]) {
    FILE *fp;
    fp = fopen("passwords.txt", "r");
    char buf[256];
    int i = 0;
    while(fgets(buf, 256, fp)) {
        char *p = strchr(buf, ':');
        if(p != NULL) {
            *p = '\0';
            strcpy(users[i].username, buf);
            strcpy(users[i].password, ++p);
            users[i].password[strlen(users[i].password)-1] = '\0';
            i++;
            if(i >= MAX_USERS) {
                break;
            }
        }
    }
    fclose(fp);
}

void addNewUser(struct User users[]) {
    int i = 0;
    while(users[i].username[0] != '\0' && i < MAX_USERS) {
        i++;
    }
    printf("Enter new username: ");
    scanf("%s", users[i].username);
    printf("Enter new password: ");
    scanf("%s", users[i].password);
    printf("New user added successfully.\n");
}

void deleteUser(struct User users[]) {
    char username[MAX_PASSWORD_LENGTH];
    printf("Enter username to delete: ");
    scanf("%s", username);
    int i = 0, found = 0;
    while(i < MAX_USERS) {
        if(strcmp(username, users[i].username) == 0) {
            users[i].username[0] = '\0';
            users[i].password[0] = '\0';
            found = 1;
            printf("User '%s' deleted successfully.\n", username);
            break;
        }
        i++;
    }
    if(!found) {
        printf("User '%s' not found!\n", username);
    }
}

int main() {
    struct User users[MAX_USERS];
    readFromFile(users);
    while(1) {
        printf("\nPassword Management System\n");
        printf("==========================\n");
        printf("1. Add new user\n");
        printf("2. Delete user\n");
        printf("3. Display all users\n");
        printf("4. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addNewUser(users);
                writeToFile(users);
                break;
            case 2:
                deleteUser(users);
                writeToFile(users);
                break;
            case 3:
                for(int i=0; i<MAX_USERS; i++) {
                    if(users[i].username[0] != '\0' && users[i].password[0] != '\0') {
                        printf("%s:%s\n", users[i].username, users[i].password);
                    }
                }
                break;
            case 4:
                writeToFile(users);
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}