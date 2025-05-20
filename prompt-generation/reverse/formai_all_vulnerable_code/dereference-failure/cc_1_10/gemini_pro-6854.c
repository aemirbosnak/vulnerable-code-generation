//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110

struct pop3_server {
    char *ip_address;
    int port;
};

struct pop3_user {
    char *username;
    char *password;
};

struct pop3_message {
    int msg_id;
    char *subject;
    char *body;
};

struct pop3_response {
    int code;
    char *message;
};

struct pop3_client {
    int sockfd;
    struct pop3_server *server;
    struct pop3_user *user;
    struct pop3_message *messages;
    int num_messages;
};

struct pop3_response *pop3_send_command(struct pop3_client *client, char *command) {
    char *response;
    int bytes_received;

    // Send the command to the server
    if (send(client->sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        return NULL;
    }

    // Receive the response from the server
    response = malloc(1024);
    if (recv(client->sockfd, response, 1024, 0) == -1) {
        perror("recv");
        return NULL;
    }

    // Parse the response
    struct pop3_response *res = malloc(sizeof(struct pop3_response));
    res->code = atoi(strtok(response, " "));
    res->message = strtok(NULL, "\r\n");

    return res;
}

int pop3_login(struct pop3_client *client) {
    struct pop3_response *res;

    // Send the USER command
    res = pop3_send_command(client, "USER ");
    if (res->code != 334) {
        return -1;
    }

    // Send the username
    res = pop3_send_command(client, strdup(client->user->username));
    if (res->code != 334) {
        return -1;
    }

    // Send the PASS command
    res = pop3_send_command(client, strdup(client->user->password));
    if (res->code != 235) {
        return -1;
    }

    return 0;
}

int pop3_get_messages(struct pop3_client *client) {
    struct pop3_response *res;

    // Send the LIST command
    res = pop3_send_command(client, "LIST");
    if (res->code != 150) {
        return -1;
    }

    // Parse the message list
    char *line;
    int num_messages = 0;
    while ((line = strtok(NULL, "\r\n"))) {
        num_messages++;
    }

    // Allocate memory for the messages
    client->messages = malloc(sizeof(struct pop3_message) * num_messages);
    client->num_messages = num_messages;

    // Fetch each message
    for (int i = 0; i < num_messages; i++) {
        // Send the RETR command
        res = pop3_send_command(client, strdup(line));
        if (res->code != 150) {
            return -1;
        }

        // Parse the message
        char *subject = strtok(NULL, "\r\n");
        char *body = strtok(NULL, "\r\n.\r\n");

        // Store the message
        client->messages[i].msg_id = i + 1;
        client->messages[i].subject = strdup(subject);
        client->messages[i].body = strdup(body);
    }

    return 0;
}

int pop3_delete_message(struct pop3_client *client, int msg_id) {
    struct pop3_response *res;

    // Send the DELE command
    res = pop3_send_command(client, strdup("DELE "));
    if (res->code != 250) {
        return -1;
    }

    return 0;
}

int pop3_quit(struct pop3_client *client) {
    struct pop3_response *res;

    // Send the QUIT command
    res = pop3_send_command(client, "QUIT");
    if (res->code != 221) {
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        return 1;
    }

    // Create the POP3 client
    struct pop3_client client;
    client.server = malloc(sizeof(struct pop3_server));
    client.user = malloc(sizeof(struct pop3_user));

    // Set the server IP address and port
    client.server->ip_address = strdup(argv[1]);
    client.server->port = POP3_PORT;

    // Set the username and password
    client.user->username = strdup(argv[2]);
    client.user->password = strdup(argv[3]);

    // Connect to the POP3 server
    client.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client.sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(client.server->ip_address);
    server_addr.sin_port = htons(client.server->port);

    if (connect(client.sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Log in to the POP3 server
    if (pop3_login(&client) != 0) {
        fprintf(stderr, "Error logging in to the POP3 server.\n");
        return 1;
    }

    // Get the messages from the POP3 server
    if (pop3_get_messages(&client) != 0) {
        fprintf(stderr, "Error getting messages from the POP3 server.\n");
        return 1;
    }

    // Print the messages
    for (int i = 0; i < client.num_messages; i++) {
        printf("Message %d:\n", client.messages[i].msg_id);
        printf("Subject: %s\n", client.messages[i].subject);
        printf("Body:\n%s\n", client.messages[i].body);
    }

    // Delete the messages from the POP3 server
    for (int i = 0; i < client.num_messages; i++) {
        if (pop3_delete_message(&client, client.messages[i].msg_id) != 0) {
            fprintf(stderr, "Error deleting message %d from the POP3 server.\n", client.messages[i].msg_id);
            return 1;
        }
    }

    // Quit the POP3 server
    if (pop3_quit(&client) != 0) {
        fprintf(stderr, "Error quitting the POP3 server.\n");
        return 1;
    }

    // Clean up
    close(client.sockfd);
    free(client.server);
    free(client.user);
    for (int i = 0; i < client.num_messages; i++) {
        free(client.messages[i].subject);
        free(client.messages[i].body);
    }
    free(client.messages);

    return 0;
}