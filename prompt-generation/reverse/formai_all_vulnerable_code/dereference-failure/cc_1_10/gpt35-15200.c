//FormAI DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct password {
    char name[20];
    char value[50];
    struct password *next;
} Password;

Password *head = NULL;

void add_password(Password **phead, const char *name, const char *value);
void display_password(Password *phead);
void search_password(Password *phead, const char *name);
void delete_password(Password **phead, const char *name);
void change_password(Password *phead, const char *name, const char *value);
void save_passwords(Password *phead);
void load_passwords(Password **phead);
void free_passwords(Password **phead);

int main() {
    int choice;
    char name[20], value[50];
    
    while(1) {
        printf("Password Manager\n");
        printf("1. Add Password\n");
        printf("2. Display Passwords\n");
        printf("3. Search Password\n");
        printf("4. Delete Password\n");
        printf("5. Change Password\n");
        printf("6. Save Passwords\n");
        printf("7. Load Passwords\n");
        printf("8. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter Name: ");
                scanf("%s", name);
                printf("Enter Value: ");
                scanf("%s", value);
                add_password(&head, name, value);
                break;
            case 2:
                display_password(head);
                break;
            case 3:
                printf("\nEnter Name: ");
                scanf("%s", name);
                search_password(head, name);
                break;
            case 4:
                printf("\nEnter Name: ");
                scanf("%s", name);
                delete_password(&head, name);
                break;
            case 5:
                printf("\nEnter Name: ");
                scanf("%s", name);
                printf("Enter Value: ");
                scanf("%s", value);
                change_password(head, name, value);
                break;
            case 6:
                save_passwords(head);
                break;
            case 7:
                load_passwords(&head);
                break;
            case 8:
                free_passwords(&head);
                exit(0);
            default:
                printf("\nInvalid Choice.\n");
                break;
        }
    }
    return 0;
}

void add_password(Password **phead, const char *name, const char *value) {
    if (*phead == NULL) {
        *phead = (Password*)malloc(sizeof(Password));
        strcpy((*phead)->name, name);
        strcpy((*phead)->value, value);
        (*phead)->next = NULL;
    } else {
        add_password(&(*phead)->next, name, value);
    }
}

void display_password(Password *phead) {
    if (phead == NULL) {
        printf("\nNo Passwords Found.\n");
    } else {
        printf("\n%-20s %s\n", "Name", "Value");
        printf("-------------------- --------------------------------------------------\n");
        while(phead != NULL) {
            printf("%-20s %s\n", phead->name, phead->value);
            phead = phead->next;
        }
    }
}

void search_password(Password *phead, const char *name) {
    int i = 0;
    while(phead != NULL) {
        if (strcmp(phead->name, name) == 0) {
            printf("\n%-20s %s\n", "Name", "Value");
            printf("-------------------- --------------------------------------------------\n");
            printf("%-20s %s\n", phead->name, phead->value);
            i++;
        }
        phead = phead->next;
    }
    if (i == 0) {
        printf("\nPassword Not Found.\n");
    }
}

void delete_password(Password **phead, const char *name) {
    if (*phead == NULL) {
        printf("\nPassword Not Found.\n");
    } else if (strcmp((*phead)->name, name) == 0) {
        Password *temp = *phead;
        *phead = (*phead)->next;
        free(temp);
        printf("\nPassword Deleted.\n");
    } else {
        delete_password(&(*phead)->next, name);
    }
}

void change_password(Password *phead, const char *name, const char *value) {
    while(phead != NULL) {
        if (strcmp(phead->name, name) == 0) {
            strcpy(phead->value, value);
            printf("\nPassword Changed.\n");
            return;
        }
        phead = phead->next;
    }
    printf("\nPassword Not Found.\n");
}

void save_passwords(Password *phead) {
    FILE *fp;
    fp = fopen("passwords.txt", "w");
    while(phead != NULL) {
        fprintf(fp, "%s %s\n", phead->name, phead->value);
        phead = phead->next;
    }
    fclose(fp);
    printf("\nPasswords Saved.\n");
}

void load_passwords(Password **phead) {
    FILE *fp;
    char name[20], value[50];
    fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("\nNo Passwords Found.\n");
    } else {
        while(fscanf(fp, "%s %s", name, value) != EOF) {
            add_password(phead, name, value);
        }
    }
    fclose(fp);
    printf("\nPasswords Loaded.\n");
}

void free_passwords(Password **phead) {
    Password *temp;
    while(*phead != NULL) {
        temp = *phead;
        *phead = (*phead)->next;
        free(temp);
    }
}