//FormAI DATASET v1.0 Category: Password management ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct password{
    char website_name[50];
    char username[50];
    char password[50];
    struct password* next;
}PASSWORD;

PASSWORD* pfirst = NULL;

void display() {
    PASSWORD* ptr = pfirst;
    if (ptr == NULL) {
        printf("The Password Manager is empty\n");
    }
    while (ptr != NULL) {
        printf("\nWebsite Name: %s", ptr->website_name);
        printf("\nUsername: %s", ptr->username);
        printf("\nPassword: %s\n", ptr->password);
        ptr = ptr->next;
    }
}

void insert(char website[], char username[], char password[]) {
    PASSWORD* new_password = (PASSWORD*)malloc(sizeof(PASSWORD));
    strcpy(new_password->website_name, website);
    strcpy(new_password->username, username);
    strcpy(new_password->password, password);
    new_password->next = NULL;

    if (pfirst == NULL) {
        pfirst = new_password;
    }
    else {
        PASSWORD* ptr = pfirst;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_password;
    }
}

void search(char website[]) {
    PASSWORD* ptr = pfirst;
    while (ptr != NULL) {
        if (strcmp(ptr->website_name, website) == 0) {
            printf("\nWebsite Name: %s", ptr->website_name);
            printf("\nUsername: %s", ptr->username);
            printf("\nPassword: %s\n", ptr->password);
            return;
        }
        ptr = ptr->next;
    }
    printf("\nWebsite not found in the Password Manager\n");
}

void delete(char website[]) {
    if (pfirst == NULL) {
        printf("\nThe Password Manager is empty\n");
        return;
    }

    PASSWORD* ptr = pfirst;
    PASSWORD* prev = NULL;

    while (ptr != NULL) {
        if (strcmp(ptr->website_name, website) == 0) {
            if (prev == NULL) {
                pfirst = ptr->next;
            }
            else {
                prev->next = ptr->next;
            }
            printf("\nDeleted Website: %s\n", ptr->website_name);
            free(ptr);
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    printf("\nWebsite not found in the Password Manager\n");
}

int main() {
    int option = 0;
    char website[50], username[50], password[50];

    while (option != 5) {
        printf("\nSelect an option: \n1. Display Password Manager\n2. Insert a new password\n3. Search for a website's password\n4. Delete a website's password\n5. Exit\nOption: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                display();
                break;
            case 2:
                printf("\nEnter Website Name: ");
                scanf("%s", website);
                printf("\nEnter Username: ");
                scanf("%s", username);
                printf("\nEnter Password: ");
                scanf("%s", password);
                insert(website, username, password);
                printf("\nNew Password for %s added to Password Manager\n", website);
                break;
            case 3:
                printf("\nEnter Website Name: ");
                scanf("%s", website);
                search(website);
                break;
            case 4:
                printf("\nEnter Website Name: ");
                scanf("%s", website);
                delete(website);
                break;
            case 5:
                printf("\nThank you for using Password Manager\n");
                exit(0);
                break;
            default:
                printf("\nInvalid option. Please choose again.\n");
                break;
        }
    }

    return 0;
}