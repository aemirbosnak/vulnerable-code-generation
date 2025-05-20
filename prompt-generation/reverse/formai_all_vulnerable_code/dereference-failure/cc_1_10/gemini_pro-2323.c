//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define MAX_VOTES 100

struct client {
    int sockfd;
    char name[100];
    int voted;
};

struct vote {
    char candidate[100];
    int count;
};

struct client clients[MAX_CLIENTS];
struct vote votes[MAX_VOTES];

int num_clients = 0;
int num_votes = 0;

int listenfd;

pthread_mutex_t clients_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t votes_lock = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int sockfd = *(int *)arg;
    free(arg);

    char buf[1024];
    int n;

    while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
        buf[n] = '\0';

        if (strncmp(buf, "REGISTER", 8) == 0) {
            char name[100];
            sscanf(buf, "REGISTER %s", name);

            pthread_mutex_lock(&clients_lock);
            clients[num_clients].sockfd = sockfd;
            strcpy(clients[num_clients].name, name);
            clients[num_clients].voted = 0;
            num_clients++;
            pthread_mutex_unlock(&clients_lock);

            write(sockfd, "REGISTERED", 11);
        } else if (strncmp(buf, "VOTE", 4) == 0) {
            char candidate[100];
            sscanf(buf, "VOTE %s", candidate);

            if (clients[sockfd].voted == 0) {
                pthread_mutex_lock(&votes_lock);
                int found = 0;
                for (int i = 0; i < num_votes; i++) {
                    if (strcmp(votes[i].candidate, candidate) == 0) {
                        votes[i].count++;
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    strcpy(votes[num_votes].candidate, candidate);
                    votes[num_votes].count = 1;
                    num_votes++;
                }
                pthread_mutex_unlock(&votes_lock);

                clients[sockfd].voted = 1;

                write(sockfd, "VOTED", 6);
            } else {
                write(sockfd, "ALREADY_VOTED", 14);
            }
        } else if (strncmp(buf, "RESULTS", 7) == 0) {
            char results[1024];
            sprintf(results, "RESULTS");

            pthread_mutex_lock(&votes_lock);
            for (int i = 0; i < num_votes; i++) {
                sprintf(results, "%s %s %d", results, votes[i].candidate, votes[i].count);
            }
            pthread_mutex_unlock(&votes_lock);

            write(sockfd, results, strlen(results));
        } else {
            write(sockfd, "INVALID_COMMAND", 15);
        }
    }

    close(sockfd);

    return NULL;
}

int main() {
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        int *sockfd = malloc(sizeof(int));
        socklen_t len = sizeof(struct sockaddr_in);

        *sockfd = accept(listenfd, (struct sockaddr *)&servaddr, &len);
        if (*sockfd == -1) {
            perror("accept");
            continue;
        }

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, sockfd);
    }

    close(listenfd);

    return 0;
}