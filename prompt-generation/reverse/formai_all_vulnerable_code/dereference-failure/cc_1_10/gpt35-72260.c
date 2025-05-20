//FormAI DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char email[50];
} email_t;

void add_email(email_t ** list, int * n) {
    printf("Enter email address: ");
    char email[50];
    scanf("%s", email);
    if (*n == 0) {
        *list = (email_t *) malloc(sizeof(email_t));
    } else {
        *list = (email_t *) realloc(*list, (*n + 1) * sizeof(email_t));
    }
    strcpy((*list)[*n].email, email);
    (*n)++;
}

void remove_email(email_t ** list, int * n) {
    if (*n == 0) {
        printf("No emails to remove.\n");
        return;
    }
    printf("Enter index of email to remove: ");
    int index;
    scanf("%d", &index);
    if (index < 0 || index >= *n) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < *n - 1; i++) {
        strcpy((*list)[i].email, (*list)[i + 1].email);
    }
    (*n)--;
    if (*n == 0) {
        free(*list);
        *list = NULL;
    } else {
        *list = (email_t *) realloc(*list, *n * sizeof(email_t));
    }
}

void print_list(email_t * list, int n) {
    if (n == 0) {
        printf("No emails in the list.\n");
        return;
    }
    printf("Email list:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", i, list[i].email);
    }
}

int main() {
    email_t * list = NULL;
    int n = 0;
    while (1) {
        printf("\n");
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Print list\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_email(&list, &n);
                break;
            case 2:
                remove_email(&list, &n);
                break;
            case 3:
                print_list(list, n);
                break;
            case 4:
                if (list != NULL) {
                    free(list);
                }
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}