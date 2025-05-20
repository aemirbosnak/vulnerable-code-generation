//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#define BUFF_SIZE 1024

typedef struct {
    int sock;
    FILE *read;
    FILE *write;
} client_t;

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int create_socket(const char *hostname, int port) {
    struct hostent *he;
    struct sockaddr_in server_addr;
    int tcp_socket;

    if ((he = gethostbyname(hostname)) == NULL) {
        error("ERROR: gethostbyname");
    }

    if ((tcp_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("ERROR: socket");
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(tcp_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR: connect");
    }

    return tcp_socket;
}

void send_cmd(client_t *client, const char *cmd, const char *arg) {
    char buffer[BUFF_SIZE];
    if (arg) {
        sprintf(buffer, "%s %s\r\n", cmd, arg);
    } else {
        sprintf(buffer, "%s\r\n", cmd);
    }
    fputs(buffer, client->write);
    fflush(client->write);
    fgets(buffer, BUFF_SIZE, client->read);
    printf("DEBUG: %s", buffer);
}

int receive_status(client_t *client) {
    char buffer[BUFF_SIZE];
    if (!fgets(buffer, BUFF_SIZE, client->read)) {
        return -1;
    }
    printf("DEBUG: %s", buffer);
    return atoi(buffer);
}

void send_data(client_t *client, const char *data) {
    char buffer[BUFF_SIZE];
    sprintf(buffer, "%s\r\n", data);
    fputs(buffer, client->write);
    fflush(client->write);
    fgets(buffer, BUFF_SIZE, client->read);
    printf("DEBUG: %s", buffer);
}

void receive_data(client_t *client) {
    char buffer[BUFF_SIZE];
    while (fgets(buffer, BUFF_SIZE, client->read)) {
        printf("DEBUG: %s", buffer);
    }
}

int main(int argc, char *argv[]) {
    client_t client;
    int port = 25;

    if (argc < 2) {
        error("ERROR: hostname required");
    }

    if (argc > 2) {
        port = atoi(argv[2]);
    }

    client.sock = create_socket(argv[1], port);
    client.read = fdopen(client.sock, "r");
    client.write = fdopen(client.sock, "w");

    send_cmd(&client, "EHLO", "localhost");
    while (receive_status(&client) == 250) {}

    send_cmd(&client, "MAIL FROM", "<sender@example.com>");
    receive_status(&client);

    send_cmd(&client, "RCPT TO", "<recipient@example.com>");
    receive_status(&client);

    send_cmd(&client, "DATA", NULL);
    receive_status(&client);

    send_data(&client, "From: <sender@example.com>");
    send_data(&client, "To: <recipient@example.com>");
    send_data(&client, "Subject: Testing SMTP");
    send_data(&client, "");
    send_data(&client, "Hello,");
    send_data(&client, "");
    send_data(&client, "This is a test email.");
    send_data(&client, "");
    send_data(&client, ".");
    receive_status(&client);

    send_cmd(&client, "QUIT", NULL);
    receive_status(&client);

    fclose(client.read);
    fclose(client.write);

    return 0;
}