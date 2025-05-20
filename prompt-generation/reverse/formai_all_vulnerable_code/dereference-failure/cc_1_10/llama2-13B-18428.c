//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <arpa/nameser.h>

#define MAX_EMAIL_LENGTH 512
#define MAX_USERNAME_LENGTH 64
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char *username;
    char *password;
    char *email;
} user_info_t;

int main() {
    int sock;
    struct sockaddr_in server_addr;
    user_info_t user_info;

    // Initialize socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8025);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Read username and password from user
    printf("Enter your username: ");
    fgets(user_info.username, MAX_USERNAME_LENGTH, stdin);
    printf("Enter your password: ");
    fgets(user_info.password, MAX_PASSWORD_LENGTH, stdin);

    // Send login request to server
    send(sock, "LOGIN\0", 6, 0);

    // Receive response from server
    char response[1024];
    recv(sock, response, 1024, 0);

    // Check response for success or failure
    if (strcmp(response, "LOGIN SUCCESS\0") == 0) {
        printf("Login successful\n");

        // Send email request to server
        char email[MAX_EMAIL_LENGTH];
        printf("Enter your email: ");
        fgets(email, MAX_EMAIL_LENGTH, stdin);
        send(sock, "SEND EMAIL\0", 9, email);

        // Receive email response from server
        recv(sock, response, 1024, 0);

        // Check response for success or failure
        if (strcmp(response, "EMAIL SENT SUCCESS\0") == 0) {
            printf("Email sent successfully\n");
        } else {
            printf("Email sending failed\n");
        }
    } else {
        printf("Login failed\n");
    }

    // Close socket
    close(sock);

    return 0;
}