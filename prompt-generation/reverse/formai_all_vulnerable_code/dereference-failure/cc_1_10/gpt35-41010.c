//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CHAR 1024

void receiveResponse(int sock, char *message) {
    char response[MAX_CHAR];
    memset(response, '\0', MAX_CHAR);
    recv(sock, response, sizeof(response), 0);
    strncpy(message, response, MAX_CHAR);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s server_address server_port email_address\n", argv[0]);
        return 1;
    }

    // Create the socket
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    // Set some paranoid options
    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    setsockopt(client_sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    setsockopt(client_sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

    // Set up the server address
    struct hostent *server;
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(client_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        close(client_sock);
        return 1;
    }

    // Send initial message and wait for response
    char message[MAX_CHAR];
    receiveResponse(client_sock, message);
    printf("Server response: %s\n", message);

    // Send HELO message and wait for response
    char heloMessage[MAX_CHAR];
    sprintf(heloMessage, "HELO %s\r\n", argv[3]);
    send(client_sock, heloMessage, strlen(heloMessage), 0);
    receiveResponse(client_sock, message);
    printf("Server response: %s\n", message);

    // Send MAIL FROM message and wait for response
    char mailFromMessage[MAX_CHAR];
    sprintf(mailFromMessage, "MAIL FROM: <%s>\r\n", argv[3]);
    send(client_sock, mailFromMessage, strlen(mailFromMessage), 0);
    receiveResponse(client_sock, message);
    printf("Server response: %s\n", message);

    // Send RCPT TO message and wait for response
    char rcptToMessage[MAX_CHAR];
    printf("Enter recipient email address: ");
    char recipient[MAX_CHAR];
    fgets(recipient, sizeof(recipient), stdin);
    recipient[strcspn(recipient, "\n")] = 0;
    sprintf(rcptToMessage, "RCPT TO: <%s>\r\n", recipient);
    send(client_sock, rcptToMessage, strlen(rcptToMessage), 0);
    receiveResponse(client_sock, message);
    printf("Server response: %s\n", message);

    // Send DATA message and wait for response
    char dataMessage[MAX_CHAR];
    sprintf(dataMessage, "DATA\r\n");
    send(client_sock, dataMessage, strlen(dataMessage), 0);
    receiveResponse(client_sock, message);
    printf("Server response: %s\n", message);

    // Send email content
    char emailContent[MAX_CHAR];
    printf("Enter email content (End with a . in a new line): \n");
    memset(emailContent, '\0', sizeof(emailContent));
    while(1) {
        char line[MAX_CHAR];
        fgets(line, sizeof(line), stdin);
        if (strstr(line, ".\r\n") != NULL || strstr(line, ".\n") != NULL) {
            break;
        }
        strncat(emailContent, line, sizeof(emailContent) - strlen(emailContent) - 1);
    }
    emailContent[strcspn(emailContent, "\r\n")] = 0;
    send(client_sock, emailContent, strlen(emailContent), 0);
    send(client_sock, "\r\n.\r\n", strlen("\r\n.\r\n"), 0);
    receiveResponse(client_sock, message);
    printf("Server response: %s\n", message);

    // Send QUIT message and wait for response
    char quitMessage[MAX_CHAR];
    sprintf(quitMessage, "QUIT\r\n");
    send(client_sock, quitMessage, strlen(quitMessage), 0);
    receiveResponse(client_sock, message);
    printf("Server response: %s\n", message);

    // Close the socket
    close(client_sock);
    return 0;
}