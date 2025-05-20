//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <alloca.h>

typedef struct Star {
    char name[50];
    char planet[30];
    char email[100];
    struct Star *next;
} Star;

void Subscribe(Star **head, char name[], char planet[], char email[]) {
    Star *new_star = (Star *) malloc(sizeof(Star));

    strcpy(new_star->name, name);
    strcpy(new_star->planet, planet);
    strcpy(new_star->email, email);

    new_star->next = *head;
    *head = new_star;
}

bool Unsubscribe(Star **head, char email[]) {
    Star *current = *head, *prev;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (prev == NULL)
                *head = current->next;
            else
                prev->next = current->next;

            free(current);
            return true;
        }

        prev = current;
        current = current->next;
    }

    return false;
}

void PrintList(Star *head) {
    Star *current = head;

    printf("\n-----StellarMail Subscribers------\n");
    printf("| Name              | Planet      | Email             |\n");
    printf("|--------------------|-------------|--------------------|\n");

    while (current != NULL) {
        printf("| %-20s | %-20s | %-50s |\n", current->name, current->planet, current->email);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    Star *mailing_list = NULL;

    if (argc < 2 || (argc > 2 && strcmp(argv[1], "--help") == 0)) {
        printf("\nUsage : %s [subscribe|unsubscribe] [name] [planet] [email]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "subscribe") == 0 && argc >= 4) {
        Subscribe(&mailing_list, argv[2], argv[3], argv[4]);
        printf("\nSuccessfully subscribed %s from %s to StellarMail!\n", argv[2], argv[3]);
    } else if (strcmp(argv[1], "unsubscribe") == 0 && argc >= 3) {
        if (Unsubscribe(&mailing_list, argv[2]))
            printf("\nSuccessfully unsubscribed %s from StellarMail!\n", argv[2]);
        else
            printf("\n%s is not subscribed to StellarMail.\n", argv[2]);
    } else {
        printf("\nInvalid command. Use --help for more information.\n");
    }

    PrintList(mailing_list);

    return 0;
}