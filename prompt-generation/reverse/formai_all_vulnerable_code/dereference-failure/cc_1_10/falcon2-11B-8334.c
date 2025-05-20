//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 1024

typedef struct {
    char *mailbox;
    char *username;
    char *password;
} imap_client_t;

imap_client_t *create_imap_client(const char *mailbox, const char *username, const char *password) {
    imap_client_t *client = malloc(sizeof(imap_client_t));
    if (client == NULL) {
        fprintf(stderr, "Failed to allocate memory for imap_client_t\n");
        exit(1);
    }

    strcpy(client->mailbox, mailbox);
    strcpy(client->username, username);
    strcpy(client->password, password);

    return client;
}

void destroy_imap_client(imap_client_t *client) {
    free(client);
}

int login_to_imap_server(imap_client_t *client) {
    char *response = NULL;
    char *command = "LOGIN ";
    strcat(command, client->username);
    strcat(command, " ");
    strcat(command, client->password);
    strcat(command, "\r\n");

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen() failed");
        return 1;
    }

    response = fgets(response, MAX_MSG_LEN, fp);
    if (response == NULL) {
        fprintf(stderr, "Failed to fetch login response\n");
        return 1;
    }

    pclose(fp);

    if (strcmp(response, "+OK")!= 0) {
        fprintf(stderr, "Invalid login response: %s\n", response);
        return 1;
    }

    return 0;
}

int list_mailboxes(imap_client_t *client) {
    char *command = "LIST \"\"\r\n";
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen() failed");
        return 1;
    }

    char response[MAX_MSG_LEN];
    int i = 0;
    while (fgets(response, MAX_MSG_LEN, fp)!= NULL) {
        if (response[0] == '\\') {
            if (strcmp(response, "\\HasChildren") == 0) {
                printf("%d: %s\n", i, response + 2);
            }
        }
        else {
            printf("%d: %s\n", i, response);
        }
        i++;
    }

    pclose(fp);
    return 0;
}

int main() {
    imap_client_t *client = create_imap_client("INBOX", "username", "password");

    if (login_to_imap_server(client)) {
        destroy_imap_client(client);
        return 1;
    }

    list_mailboxes(client);

    destroy_imap_client(client);

    return 0;
}