//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define BACKLOG 10

struct client {
    int fd;
    char *email;
    struct client *next;
};

struct mailing_list {
    struct client *head;
    struct client *tail;
    int count;
};

struct mailing_list mailing_list;

void add_client(int fd, char *email) {
    struct client *new_client = malloc(sizeof(struct client));
    if (new_client == NULL) {
        perror("malloc");
        exit(1);
    }
    new_client->fd = fd;
    new_client->email = strdup(email);
    new_client->next = NULL;
    if (mailing_list.head == NULL) {
        mailing_list.head = new_client;
        mailing_list.tail = new_client;
    } else {
        mailing_list.tail->next = new_client;
        mailing_list.tail = new_client;
    }
    mailing_list.count++;
}

void remove_client(int fd) {
    struct client *current = mailing_list.head;
    struct client *previous = NULL;
    while (current != NULL) {
        if (current->fd == fd) {
            if (previous == NULL) {
                mailing_list.head = current->next;
            } else {
                previous->next = current->next;
            }
            if (current == mailing_list.tail) {
                mailing_list.tail = previous;
            }
            free(current->email);
            free(current);
            mailing_list.count--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void send_all(char *message) {
    struct client *current = mailing_list.head;
    while (current != NULL) {
        send(current->fd, message, strlen(message), 0);
        current = current->next;
    }
}

void *client_thread(void *arg) {
    int fd = (int) arg;
    char buffer[1024];
    int n;
    while ((n = recv(fd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        if (strncmp(buffer, "SUBSCRIBE", 9) == 0) {
            char *email = strtok(buffer + 10, " ");
            add_client(fd, email);
            send(fd, "SUBSCRIBED\n", 11, 0);
        } else if (strncmp(buffer, "UNSUBSCRIBE", 11) == 0) {
            remove_client(fd);
            send(fd, "UNSUBSCRIBED\n", 13, 0);
        } else if (strncmp(buffer, "SEND", 4) == 0) {
            char *message = strtok(buffer + 5, "\n");
            send_all(message);
        }
    }
    if (n == 0) {
        remove_client(fd);
    } else {
        perror("recv");
    }
    close(fd);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    if (bind(s, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(s, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        int fd = accept(s, NULL, NULL);
        if (fd == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("accept");
                exit(1);
            }
        }

        pthread_t thread;
        pthread_create(&thread, NULL, client_thread, (void *) fd);
    }

    close(s);
    return 0;
}