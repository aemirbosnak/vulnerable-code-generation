//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EMAIL_LENGTH 5120
#define MAX_PASSWORD_LENGTH 32
#define PORT 25

typedef struct {
    char *email;
    char *password;
} user_t;

typedef struct {
    char *server;
    int port;
} config_t;

int main(int argc, char *argv[]) {
    config_t config;
    user_t user;

    // Parse command line arguments
    if (argc < 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    config.server = argv[1];
    config.port = atoi(argv[2]);

    // Prompt user for email and password
    printf("Enter email: ");
    fgets(user.email, MAX_EMAIL_LENGTH, stdin);
    user.email[strcspn(user.email, "\n")] = 0;

    printf("Enter password: ");
    fgets(user.password, MAX_PASSWORD_LENGTH, stdin);
    user.password[strcspn(user.password, "\n")] = 0;

    // Connect to email server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(config.port);
    inet_pton(AF_INET, config.server, &server_addr.sin_addr);
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send login command
    char login_cmd[1024];
    sprintf(login_cmd, "HELO %s\r\n", user.email);
    send(sock, login_cmd, strlen(login_cmd), 0);

    // Receive server response
    char response[1024];
    recv(sock, response, 1024, 0);

    // Check if login was successful
    if (strstr(response, "250 OK") != NULL) {
        // Send email command
        char email_cmd[1024];
        sprintf(email_cmd, "MAIL FROM:<%s>\r\n", user.email);
        send(sock, email_cmd, strlen(email_cmd), 0);

        // Receive server response
        char email_response[1024];
        recv(sock, email_response, 1024, 0);

        // Check if email was sent successfully
        if (strstr(email_response, "250 OK") != NULL) {
            printf("Email sent successfully\n");
        } else {
            printf("Error sending email: %s\n", email_response);
        }
    } else {
        printf("Error logging in: %s\n", response);
    }

    // Close socket
    close(sock);

    return 0;
}