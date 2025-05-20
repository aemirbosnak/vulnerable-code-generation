//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 50

void romanticize(char *name, char *message);

int main() {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    printf("What is your name, my love? ");
    scanf("%19s", name);

    printf("What is your message, my heart? ");
    scanf("%49s", message);

    romanticize(name, message);

    printf("Your name, my dear, is as beautiful as a rose.\nYour message, my love, is as sweet as a kiss.\n");

    return 0;
}

void romanticize(char *name, char *message) {
    char *name_romanticized = malloc(strlen(name) * 2);
    char *message_romanticized = malloc(strlen(message) * 2);

    for (int i = 0; i < strlen(name); i++) {
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u') {
            name_romanticized[i] = name[i] + 1;
        } else {
            name_romanticized[i] = name[i];
        }
    }

    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == 'a' || message[i] == 'e' || message[i] == 'i' || message[i] == 'o' || message[i] == 'u') {
            message_romanticized[i] = message[i] + 1;
        } else {
            message_romanticized[i] = message[i];
        }
    }

    printf("Your name, my dear, is now %s\n", name_romanticized);
    printf("Your message, my love, is now %s\n", message_romanticized);

    free(name_romanticized);
    free(message_romanticized);
}