//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define EMAIL_SERVER "mail.example.com"
#define PORT 25

#define MAX_MESSAGE_LENGTH 512
#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char *username;
    char *password;
    char *message;
} email_data_t;

void connect_to_server(int sock);
void send_message(int sock, email_data_t *data);
void recv_message(int sock, email_data_t *data);
void close_connection(int sock);

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, EMAIL_SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    email_data_t data;
    printf("Enter your username: ");
    scanf("%29s", data.username);
    printf("Enter your password: ");
    scanf("%29s", data.password);
    printf("Enter your message: ");
    fgets(data.message, MAX_MESSAGE_LENGTH, stdin);

    send_message(sock, &data);

    recv_message(sock, &data);

    close_connection(sock);

    return 0;
}

void connect_to_server(int sock) {
    char buffer[1024];
    send(sock, "HELO mail.example.com\r\n", 13, 0);
    recv(sock, buffer, 1024, 0);
    printf("Connected to %s\n", buffer);
}

void send_message(int sock, email_data_t *data) {
    char buffer[1024];
    sprintf(buffer, "MAIL FROM: <%s>\r\n", data->username);
    send(sock, buffer, strlen(buffer), 0);

    sprintf(buffer, "RCPT TO: <%s>\r\n", data->username);
    send(sock, buffer, strlen(buffer), 0);

    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);

    printf("Sending message...\n");
    send(sock, data->message, strlen(data->message), 0);

    sprintf(buffer, "\r\n.\r\n");
    send(sock, buffer, strlen(buffer), 0);
}

void recv_message(int sock, email_data_t *data) {
    char buffer[1024];
    recv(sock, buffer, 1024, 0);
    printf("Received message: %s\n", buffer);

    // Parse the received message and extract the sender and recipient
    // information and the message body
    char *message = strtok(buffer, "\r\n");
    char *sender = strtok(NULL, "\r\n");
    char *recipient = strtok(NULL, "\r\n");
    char *body = strtok(NULL, "\r\n");

    // Print the received message
    printf("Sender: %s\nRecipient: %s\nMessage body: %s\n", sender, recipient, body);
}

void close_connection(int sock) {
    char buffer[1024];
    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, 1024, 0);
    close(sock);
}