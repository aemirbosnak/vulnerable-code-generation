//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LEN 128
#define MAX_LIST_SIZE 100

struct email_addr {
    char *email;
    struct email_addr *next;
};

struct mailing_list {
    struct email_addr *head;
    struct email_addr *tail;
    int size;
};

struct mailing_list *create_mailing_list() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    if (list == NULL) {
        perror("malloc");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void destroy_mailing_list(struct mailing_list *list) {
    struct email_addr *curr = list->head;
    struct email_addr *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr->email);
        free(curr);
        curr = next;
    }
    free(list);
}

int add_email_to_list(struct mailing_list *list, char *email) {
    if (email == NULL || strlen(email) == 0) {
        return -1;
    }
    // Check if the email is already in the list
    struct email_addr *curr = list->head;
    while (curr != NULL) {
        if (strcmp(curr->email, email) == 0) {
            return 0;
        }
        curr = curr->next;
    }
    // Add the email to the end of the list
    struct email_addr *new_email = malloc(sizeof(struct email_addr));
    if (new_email == NULL) {
        perror("malloc");
        return -1;
    }
    new_email->email = strdup(email);
    if (new_email->email == NULL) {
        free(new_email);
        perror("strdup");
        return -1;
    }
    new_email->next = NULL;
    if (list->tail == NULL) {
        list->head = new_email;
        list->tail = new_email;
    } else {
        list->tail->next = new_email;
        list->tail = new_email;
    }
    list->size++;
    return 0;
}

int remove_email_from_list(struct mailing_list *list, char *email) {
    if (email == NULL || strlen(email) == 0) {
        return -1;
    }
    // Find the email in the list
    struct email_addr *prev = NULL;
    struct email_addr *curr = list->head;
    while (curr != NULL) {
        if (strcmp(curr->email, email) == 0) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    // If the email was not found, return an error
    if (curr == NULL) {
        return -1;
    }
    // Remove the email from the list
    if (prev == NULL) {
        list->head = curr->next;
    } else {
        prev->next = curr->next;
    }
    if (curr == list->tail) {
        list->tail = prev;
    }
    free(curr->email);
    free(curr);
    list->size--;
    return 0;
}

int find_email_in_list(struct mailing_list *list, char *email) {
    if (email == NULL || strlen(email) == 0) {
        return -1;
    }
    // Find the email in the list
    struct email_addr *curr = list->head;
    while (curr != NULL) {
        if (strcmp(curr->email, email) == 0) {
            return 0;
        }
        curr = curr->next;
    }
    // If the email was not found, return an error
    return -1;
}

void print_mailing_list(struct mailing_list *list) {
    struct email_addr *curr = list->head;
    while (curr != NULL) {
        printf("%s\n", curr->email);
        curr = curr->next;
    }
}

int main() {
    // Create a mailing list
    struct mailing_list *list = create_mailing_list();
    if (list == NULL) {
        return EXIT_FAILURE;
    }

    // Add some emails to the list
    if (add_email_to_list(list, "example@example.com") != 0) {
        return EXIT_FAILURE;
    }
    if (add_email_to_list(list, "example2@example.com") != 0) {
        return EXIT_FAILURE;
    }
    if (add_email_to_list(list, "example3@example.com") != 0) {
        return EXIT_FAILURE;
    }

    // Print the list
    printf("Mailing list:\n");
    print_mailing_list(list);

    // Find an email in the list
    if (find_email_in_list(list, "example2@example.com") == 0) {
        printf("Found email: example2@example.com\n");
    } else {
        printf("Email not found: example2@example.com\n");
    }

    // Remove an email from the list
    if (remove_email_from_list(list, "example3@example.com") != 0) {
        return EXIT_FAILURE;
    }

    // Print the list again
    printf("Mailing list:\n");
    print_mailing_list(list);

    // Destroy the list
    destroy_mailing_list(list);

    return EXIT_SUCCESS;
}