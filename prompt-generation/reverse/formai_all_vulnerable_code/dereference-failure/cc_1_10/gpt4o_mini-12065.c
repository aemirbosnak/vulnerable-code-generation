//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_EMAIL_LENGTH 100
#define CONFIG_FILE "mlm_config.txt"

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int member_count;
    char list_name[50];
} MailingList;

void load_config(MailingList *list) {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (file) {
        fscanf(file, "ListName: %s\n", list->list_name);
        fscanf(file, "MaxMembers: %d\n", &list->member_count);
        fclose(file);
    } else {
        printf("Config file not found. Using default values.\n");
        strcpy(list->list_name, "Default Mailing List");
        list->member_count = 0;
    }
}

void display_members(const MailingList *list) {
    if (list->member_count == 0) {
        printf("No members in the mailing list.\n");
        return;
    }
    printf("Members of '%s':\n", list->list_name);
    for (int i = 0; i < list->member_count; i++) {
        printf("%d. %s\n", i + 1, list->members[i].email);
    }
}

int add_member(MailingList *list, const char *email) {
    if (list->member_count >= MAX_MEMBERS) {
        printf("Mailing list is full!\n");
        return 0;
    }
    strcpy(list->members[list->member_count++].email, email);
    return 1;
}

int remove_member(MailingList *list, const char *email) {
    for (int i = 0; i < list->member_count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            for (int j = i; j < list->member_count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->member_count--;
            return 1;
        }
    }
    printf("Email '%s' not found in the mailing list.\n", email);
    return 0;
}

void save_members(const MailingList *list) {
    FILE *file = fopen("members.txt", "w");
    if (!file) {
        printf("Error saving members.\n");
        return;
    }
    for (int i = 0; i < list->member_count; i++) {
        fprintf(file, "%s\n", list->members[i].email);
    }
    fclose(file);
}

void load_members(MailingList *list) {
    FILE *file = fopen("members.txt", "r");
    if (!file) {
        printf("No previous members found.\n");
        return;
    }
    char email[MAX_EMAIL_LENGTH];
    while (fscanf(file, "%s\n", email) != EOF) {
        add_member(list, email);
    }
    fclose(file);
}

void show_menu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Member\n");
    printf("2. Remove Member\n");
    printf("3. Show Members\n");
    printf("4. Save Members\n");
    printf("5. Load Members\n");
    printf("6. Exit\n");
}

int main() {
    MailingList list;
    load_config(&list);

    int choice;
    char email[MAX_EMAIL_LENGTH];

    load_members(&list);
    
    do {
        show_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character left in the buffer

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // remove newline
                if (add_member(&list, email)) {
                    printf("Email '%s' added successfully.\n", email);
                }
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // remove newline
                if (remove_member(&list, email)) {
                    printf("Email '%s' removed successfully.\n", email);
                }
                break;
            case 3:
                display_members(&list);
                break;
            case 4:
                save_members(&list);
                break;
            case 5:
                load_members(&list);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}