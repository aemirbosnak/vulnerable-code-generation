//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The game is afoot! */

#define MAX_ATTEMPTS 3

int main(void) {
    int attempts = 0;
    char* username = (char*)malloc(20 * sizeof(char));
    char* password = (char*)malloc(20 * sizeof(char));
    strcpy(username, "sherlock");
    strcpy(password, "elementary");

    printf("Welcome to the Intrusion Detection System. Please enter your username and password.\n");

    while (attempts < MAX_ATTEMPTS) {
        char* u_input = (char*)malloc(20 * sizeof(char));
        char* p_input = (char*)malloc(20 * sizeof(char));
        printf("Username: ");
        scanf("%s", u_input);
        printf("Password: ");
        scanf("%s", p_input);

        if (strcmp(u_input, username) == 0 && strcmp(p_input, password) == 0) {
            printf("Access granted. Intrusion detection system is now active.\n");
            break;
        } else {
            printf("Incorrect username or password. %d attempt(s) remaining.\n", MAX_ATTEMPTS - attempts - 1);
        }
        attempts++;
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("The game is up. Intrusion detected. Alerting authorities.\n");
        /* Notify authorities of attempted intrusion */
    }

    /* Intrusion detection system is running */
    printf("ID System running...\n");

    /* Main ID logic */
    while (1) {
        /* Placeholder logic */
        printf("Monitoring network traffic...\n");
        printf("Analyzing packets...\n");
        printf("No suspicious activity detected.\n");
    }

    return 0;
}
/* Elementary, my dear Watson. */