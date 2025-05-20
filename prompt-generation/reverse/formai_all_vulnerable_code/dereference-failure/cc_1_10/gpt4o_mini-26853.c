//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 25 // Many SMTP servers use port 25
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
}

char* receive_response(int sock) {
    char *response = malloc(BUFFER_SIZE);
    int bytes_received = recv(sock, response, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) error("ERROR on recv");
    response[bytes_received] = '\0'; // Null terminate the string
    return response;
}

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];

    // Exciting greeting for the email client!
    printf("🎉 Welcome to the Simple Email Client! 🎉\n");

    // Step 1: Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) error("Could not create socket");

    // Step 2: Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Assuming local server for testing

    // Step 3: Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
        error("Connection to the server failed!");

    // Receiving server's initial response
    char *response = receive_response(sock);
    printf("Server: %s\n", response);
    free(response);

    // Step 4: Sending HELO command
    send_command(sock, "HELO localhost\r\n");
    response = receive_response(sock);
    printf("Server: %s\n", response);
    free(response);

    // Step 5: Specify sender's email
    char sender[BUFFER_SIZE];
    printf("Enter your email address (sender): ");
    fgets(sender, sizeof(sender), stdin);
    // Remove newline character
    sender[strcspn(sender, "\n")] = 0;

    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", sender);
    send_command(sock, command);
    response = receive_response(sock);
    printf("Server: %s\n", response);
    free(response);

    // Step 6: Specify recipient's email
    char recipient[BUFFER_SIZE];
    printf("Enter the recipient's email address: ");
    fgets(recipient, sizeof(recipient), stdin);
    recipient[strcspn(recipient, "\n")] = 0;

    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", recipient);
    send_command(sock, command);
    response = receive_response(sock);
    printf("Server: %s\n", response);
    free(response);

    // Step 7: Prepare for message data
    send_command(sock, "DATA\r\n");
    response = receive_response(sock);
    printf("Server: %s\n", response);
    free(response);

    // Step 8: Compose email body
    printf("Compose your message (end with a single '.' on a new line):\n");
    char email_body[BUFFER_SIZE * 2] = "";
    char line[BUFFER_SIZE];

    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, ".\n") == 0) {
            break;
        }
        strcat(email_body, line);
    }

    // Step 9: Send email data
    send_command(sock, email_body);
    send_command(sock, "\r\n.\r\n");
    response = receive_response(sock);
    printf("Server: %s\n", response);
    free(response);

    // Step 10: Closing the connection
    send_command(sock, "QUIT\r\n");
    response = receive_response(sock);
    printf("Server: %s\n", response);
    free(response);

    // Step 11: Clean up and close the socket
    close(sock);
    printf("💌 Email sent successfully! Thank you for using the Simple Email Client! 💌\n");
    return 0;
}