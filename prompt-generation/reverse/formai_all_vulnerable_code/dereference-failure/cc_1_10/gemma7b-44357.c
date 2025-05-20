//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_CHECKS 10

typedef struct Check {
    char *name;
    int port;
    struct Check *next;
} Check;

void add_check(Check **head, char *name, int port) {
    Check *new_check = malloc(sizeof(Check));
    new_check->name = strdup(name);
    new_check->port = port;
    new_check->next = NULL;

    if (*head == NULL) {
        *head = new_check;
    } else {
        (*head)->next = new_check;
    }
}

int main() {
    Check *head = NULL;
    add_check(&head, "Server A", 8080);
    add_check(&head, "Server B", 8081);
    add_check(&head, "Server C", 8082);

    for (Check *check = head; check; check = check->next) {
        int sockfd = socket(AF_INET, SOCK_STREAM, htons(check->port));
        if (sockfd == -1) {
            perror("Error creating socket");
            continue;
        }

        char buf[1024];
        int bytes_read = recv(sockfd, buf, 1024, 0);
        if (bytes_read > 0) {
            printf("Check %s is alive, received %d bytes:\n", check->name, bytes_read);
            printf("Message: %s\n", buf);
        } else {
            perror("Error receiving data");
            printf("Check %s is down.\n", check->name);
        }

        close(sockfd);
    }

    return 0;
}