//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct {
    char name[20];
    char email[50];
} email_info;

typedef struct {
    int size;
    email_info *list;
} mailing_list;

void initialize_mailing_list(mailing_list *ml) {
    ml->size = 0;
    ml->list = NULL;
}

void add_email_to_list(mailing_list *ml, char *name, char *email) {
    if (ml->size >= MAX_EMAILS) {
        printf("Mailing list is full!\n");
        return;
    }

    email_info new_email = {.name = name,.email = email };
    ml->list[ml->size++] = new_email;
}

void remove_email_from_list(mailing_list *ml, char *email) {
    for (int i = 0; i < ml->size; i++) {
        if (strcmp(ml->list[i].email, email) == 0) {
            for (int j = i; j < ml->size - 1; j++) {
                ml->list[j] = ml->list[j+1];
            }
            ml->size--;
            return;
        }
    }

    printf("Email not found in the mailing list!\n");
}

int check_if_email_exists(mailing_list *ml, char *email) {
    for (int i = 0; i < ml->size; i++) {
        if (strcmp(ml->list[i].email, email) == 0) {
            return 1;
        }
    }

    return 0;
}

void display_mailing_list(mailing_list *ml) {
    for (int i = 0; i < ml->size; i++) {
        printf("%s: %s\n", ml->list[i].name, ml->list[i].email);
    }
}

void send_email_to_all(mailing_list *ml, char *message) {
    for (int i = 0; i < ml->size; i++) {
        printf("Sending email to: %s\n", ml->list[i].email);
    }
}

int search_for_email(mailing_list *ml, char *email) {
    for (int i = 0; i < ml->size; i++) {
        if (strcmp(ml->list[i].email, email) == 0) {
            return 1;
        }
    }

    return 0;
}

void display_size_of_mailing_list(mailing_list *ml) {
    printf("Size of mailing list: %d\n", ml->size);
}

int main() {
    mailing_list ml;
    initialize_mailing_list(&ml);

    add_email_to_list(&ml, "Alice", "alice@example.com");
    add_email_to_list(&ml, "Bob", "bob@example.com");
    add_email_to_list(&ml, "Charlie", "charlie@example.com");

    remove_email_from_list(&ml, "Alice");

    if (check_if_email_exists(&ml, "Bob")) {
        printf("Bob's email address is still in the list!\n");
    } else {
        printf("Bob's email address has been removed from the list!\n");
    }

    display_mailing_list(&ml);

    send_email_to_all(&ml, "Hello, everyone! How are you doing?");

    if (search_for_email(&ml, "Charlie")) {
        printf("Charlie's email address is in the list!\n");
    } else {
        printf("Charlie's email address is not in the list!\n");
    }

    display_size_of_mailing_list(&ml);

    return 0;
}