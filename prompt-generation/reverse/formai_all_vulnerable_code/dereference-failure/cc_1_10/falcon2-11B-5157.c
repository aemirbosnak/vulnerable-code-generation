//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_HOST "your_pop3_server_hostname"
#define SERVER_PORT 110

struct pop3_message {
    char *subject;
    char *body;
};

struct pop3_client {
    int socket;
    struct sockaddr_in server_address;
    char buffer[4096];
};

void pop3_connect(struct pop3_client *client) {
    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket == -1) {
        fprintf(stderr, "Failed to create socket\n");
        exit(1);
    }

    struct hostent *server = gethostbyname(SERVER_HOST);
    if (server == NULL) {
        fprintf(stderr, "Failed to resolve server hostname\n");
        exit(1);
    }

    memcpy(&client->server_address, server->h_addr_list[0], sizeof(client->server_address));
}

void pop3_disconnect(struct pop3_client *client) {
    close(client->socket);
}

void pop3_send_command(struct pop3_client *client, const char *command) {
    int n = strlen(command) + 1;
    strcpy(client->buffer, command);
    send(client->socket, client->buffer, n, 0);
}

void pop3_receive_response(struct pop3_client *client, struct pop3_message *response) {
    int n = 0;
    while (n > 0) {
        n = recv(client->socket, client->buffer + n, 4096, 0);
        if (n == -1) {
            fprintf(stderr, "Failed to receive response\n");
            exit(1);
        }

        if (strstr(client->buffer, "OK")!= NULL) {
            break;
        }
    }

    char *subject = strstr(client->buffer, "Subject: ");
    char *body = strstr(client->buffer, "Message-ID: ");

    response->subject = strdup(subject + 7);
    response->body = strdup(body + 12);
}

int main() {
    struct pop3_client client;
    struct pop3_message response;

    pop3_connect(&client);

    pop3_send_command(&client, "USER testuser");
    pop3_send_command(&client, "PASS password");

    pop3_receive_response(&client, &response);

    printf("Received message: %s\n", response.body);

    pop3_disconnect(&client);

    return 0;
}