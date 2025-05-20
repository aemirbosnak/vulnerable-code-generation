//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_HOSTS 10
#define MONITOR_INTERVAL 60

typedef struct Host {
    char name[256];
    int port;
    struct Host *next;
} Host;

Host *host_list = NULL;

void add_host(char *name, int port) {
    Host *new_host = malloc(sizeof(Host));
    strcpy(new_host->name, name);
    new_host->port = port;
    new_host->next = NULL;

    if (host_list == NULL) {
        host_list = new_host;
    } else {
        Host *curr_host = host_list;
        while (curr_host->next) {
            curr_host = curr_host->next;
        }
        curr_host->next = new_host;
    }
}

int main() {
    add_host("localhost", 80);
    add_host("google.com", 80);
    add_host("facebook.com", 80);

    int i = 0;
    while (1) {
        for (Host *curr_host = host_list; curr_host; curr_host = curr_host->next) {
            int sockfd = socket(AF_INET, SOCK_STREAM, htons(curr_host->port));
            if (sockfd == -1) {
                perror("Error creating socket");
                continue;
            }

            char msg[1024] = "Are you alive?";
            send(sockfd, msg, strlen(msg), 0);

            char resp[1024] = "";
            recv(sockfd, resp, 1024, 0);

            printf("%s: %s\n", curr_host->name, resp);
        }

        sleep(MONITOR_INTERVAL);
    }
}