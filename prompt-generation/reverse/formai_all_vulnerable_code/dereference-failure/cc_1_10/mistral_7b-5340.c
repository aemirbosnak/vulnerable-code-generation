//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBSCRIBERS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_to_list(char *name, char *email) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Our hearts are full, we cannot accept another love.\n");
        return;
    }
    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    num_subscribers++;
}

void remove_from_list(char *name) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            memmove(&subscribers[i], &subscribers[i + 1], sizeof(Subscriber) * (num_subscribers - i - 1));
            num_subscribers--;
            printf("You have been unsubscribed from our mailing list. Our hearts will always remember you.\n");
            return;
        }
    }
    printf("We're sorry, but we could not find your name on our list.\n");
}

void send_love_letter(char *name, char *message) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            printf("Dear %s,\n", subscribers[i].name);
            printf("%s\n", message);
            printf("Yours truly,\nOur mailing list\n");
            printf("To %s,\n", subscribers[i].email);
            printf("%s\n", message);
            return;
        }
    }
    printf("We're sorry, but we could not find your email address on our list.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [add|remove|letter] [name] [email]\n", argv[0]);
        return 1;
    }

    char command = argv[1][0];
    if (command == 'a') {
        add_to_list(argv[2], argv[3]);
    } else if (command == 'r') {
        remove_from_list(argv[2]);
    } else if (command == 'l') {
        char message[100] = "Our hearts beat for you, dear.";
        send_love_letter(argv[2], message);
    } else {
        printf("Invalid command.\n");
        return 1;
    }

    return 0;
}