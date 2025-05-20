//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_HOSTS 10
#define MAX_PINGS 5

typedef struct Host {
    char name[256];
    int port;
    int attempts;
    struct Host *next;
} Host;

Host *head = NULL;

void addHost(char *name, int port, int attempts) {
    Host *newHost = malloc(sizeof(Host));
    strcpy(newHost->name, name);
    newHost->port = port;
    newHost->attempts = attempts;
    newHost->next = NULL;

    if (head == NULL) {
        head = newHost;
    } else {
        Host *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newHost;
    }
}

int main() {
    addHost("localhost", 53, 3);
    addHost("192.168.1.1", 80, 5);
    addHost("google.com", 80, 2);

    for (int i = 0; i < MAX_PINGS; i++) {
        for (Host *current = head; current; current = current->next) {
            int attempts = 0;
            while (attempts < current->attempts) {
                int sockfd = socket(AF_INET, SOCK_STREAM, htons(current->port));
                struct sockaddr_in sockAddr;
                sockAddr.sin_family = AF_INET;
                sockAddr.sin_port = htons(current->port);
                sockAddr.sin_addr.s_addr = inet_addr(current->name);

                if (connect(sockfd, (struct sockaddr *)&sockAddr, sizeof(sockAddr)) == 0) {
                    printf("%s is online.\n", current->name);
                    close(sockfd);
                    break;
                } else {
                    attempts++;
                    printf("%s is not responding. Attempts: %d.\n", current->name, attempts);
                }
            }

            if (attempts == current->attempts) {
                printf("%s is offline.\n", current->name);
            }
        }
    }

    return 0;
}