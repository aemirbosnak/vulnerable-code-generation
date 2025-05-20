//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 25
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr_in server_address;
} SMTPClient;

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

SMTPClient* create_smtp_client(const char *hostname) {
    SMTPClient *client = malloc(sizeof(SMTPClient));
    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket < 0)
        error("Error opening socket");

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL)
        error("No such host");

    memset(&client->server_address, 0, sizeof(client->server_address));
    client->server_address.sin_family = AF_INET;
    memcpy(&client->server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    client->server_address.sin_port = htons(PORT);

    if (connect(client->socket, (struct sockaddr *)&client->server_address, sizeof(client->server_address)) < 0)
        error("Connection to server failed");
    
    return client;
}

void send_command(SMTPClient *client, const char *cmd) {
    char buffer[BUFFER_SIZE];
    
    write(client->socket, cmd, strlen(cmd));
    write(client->socket, "\r\n", 2);  // SMTP commands end with CRLF

    // Read server response
    memset(buffer, 0, BUFFER_SIZE);
    read(client->socket, buffer, BUFFER_SIZE - 1);
    printf("Server: %s", buffer);
}

void smtp_init(SMTPClient *client) {
    send_command(client, "HELO example.com");
}

void smtp_mail(SMTPClient *client, const char *from) {
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "MAIL FROM:<%s>", from);
    send_command(client, command);
}

void smtp_rcpt(SMTPClient *client, const char *to) {
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "RCPT TO:<%s>", to);
    send_command(client, command);
}

void smtp_data(SMTPClient *client, const char *data) {
    send_command(client, "DATA");
    write(client->socket, data, strlen(data));
    write(client->socket, "\r\n.\r\n", 5);  // End of data
    send_command(client, "QUIT");
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <from> <to>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *hostname = argv[1];
    const char *from = argv[2];
    const char *to = argv[3];

    SMTPClient *client = create_smtp_client(hostname);
    
    smtp_init(client);
    smtp_mail(client, from);
    smtp_rcpt(client, to);
    
    char message[BUFFER_SIZE];
    snprintf(message, BUFFER_SIZE,
             "Subject: Test Email\r\n"
             "Hello,\r\n"
             "This is a test email sent from an SMTP client.\r\n"
             "Best Regards,\r\n"
             "SMTP Client");

    smtp_data(client, message);

    close(client->socket);
    free(client);
    
    return 0;
}