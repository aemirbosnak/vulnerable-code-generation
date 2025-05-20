//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_NAME_LEN 256
#define MAX_PHONE_LEN 16
#define MAX_CONTACTS 100

struct contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
};

struct contact_list {
    struct contact contacts[MAX_CONTACTS];
    int num_contacts;
};

struct phone_book {
    struct contact_list contacts;
    int listen_fd;
};

struct phone_book *phone_book_create() {
    struct phone_book *phone_book = malloc(sizeof(*phone_book));
    if (!phone_book) {
        return NULL;
    }
    memset(phone_book, 0, sizeof(*phone_book));
    return phone_book;
}

void phone_book_destroy(struct phone_book *phone_book) {
    if (!phone_book) {
        return;
    }
    close(phone_book->listen_fd);
    free(phone_book);
}

int phone_book_add_contact(struct phone_book *phone_book, const char *name, const char *phone) {
    if (!phone_book || !name || !phone || phone_book->contacts.num_contacts >= MAX_CONTACTS) {
        return -1;
    }
    strcpy(phone_book->contacts.contacts[phone_book->contacts.num_contacts].name, name);
    strcpy(phone_book->contacts.contacts[phone_book->contacts.num_contacts].phone, phone);
    phone_book->contacts.num_contacts++;
    return 0;
}

int phone_book_get_contact(struct phone_book *phone_book, const char *name, char *phone) {
    if (!phone_book || !name || !phone) {
        return -1;
    }
    for (int i = 0; i < phone_book->contacts.num_contacts; i++) {
        if (strcmp(phone_book->contacts.contacts[i].name, name) == 0) {
            strcpy(phone, phone_book->contacts.contacts[i].phone);
            return 0;
        }
    }
    return -1;
}

int phone_book_listen(struct phone_book *phone_book, const char *port) {
    if (!phone_book || !port) {
        return -1;
    }
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int sfd, optval = 1;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    if (getaddrinfo(NULL, port, &hints, &result) != 0) {
        return -1;
    }
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sfd == -1) {
            continue;
        }
        if (setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
            close(sfd);
            continue;
        }
        if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == -1) {
            close(sfd);
            continue;
        }
        break;
    }
    if (rp == NULL) {
        return -1;
    }
    freeaddrinfo(result);
    if (listen(sfd, SOMAXCONN) == -1) {
        close(sfd);
        return -1;
    }
    phone_book->listen_fd = sfd;
    return 0;
}

void *phone_book_handle_connection(void *arg) {
    struct phone_book *phone_book = (struct phone_book *)arg;
    int connfd = *(int *)arg;
    char buf[1024];
    char *name, *phone;
    int len;

    while ((len = read(connfd, buf, sizeof(buf))) > 0) {
        buf[len] = '\0';
        name = strtok(buf, " ");
        phone = strtok(NULL, " ");
        if (!name || !phone) {
            continue;
        }
        if (strcmp(name, "add") == 0) {
            phone_book_add_contact(phone_book, name, phone);
        } else if (strcmp(name, "get") == 0) {
            if (phone_book_get_contact(phone_book, name, phone) == 0) {
                write(connfd, phone, strlen(phone));
            }
        }
    }
    close(connfd);
    return NULL;
}

int main(int argc, char **argv) {
    struct phone_book *phone_book = phone_book_create();
    if (!phone_book) {
        return EXIT_FAILURE;
    }
    if (phone_book_listen(phone_book, "8080") == -1) {
        phone_book_destroy(phone_book);
        return EXIT_FAILURE;
    }
    while (1) {
        int connfd;
        socklen_t addrlen;
        struct sockaddr_in addr;
        pthread_t thread;
        addrlen = sizeof(addr);
        connfd = accept(phone_book->listen_fd, (struct sockaddr *)&addr, &addrlen);
        if (connfd == -1) {
            continue;
        }
        pthread_create(&thread, NULL, phone_book_handle_connection, (void *)&connfd);
    }
    phone_book_destroy(phone_book);
    return EXIT_SUCCESS;
}