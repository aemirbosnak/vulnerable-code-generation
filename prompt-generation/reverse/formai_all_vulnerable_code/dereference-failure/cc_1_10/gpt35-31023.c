//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#define PORT 25

void send_message(int sockfd, char* message);
void receive_response(int sockfd);

int main(int argc, char* argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent* server;

    // Check for required arguments 
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname sender recipient\n", argv[0]);
        exit(1);
    }

    // Get server IP address based on the hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: Could not connect to server\n");
        exit(1);
    }

    printf("Connected to server %s\n", argv[1]);

    // Send HELLO message
    char helo_msg[256];
    snprintf(helo_msg, sizeof(helo_msg), "HELO %s\r\n", argv[1]);
    send_message(sockfd, helo_msg);
    receive_response(sockfd);

    // Send MAIL FROM message
    char mail_from_msg[256];
    snprintf(mail_from_msg, sizeof(mail_from_msg), "MAIL FROM: <%s>\r\n", argv[2]);
    send_message(sockfd, mail_from_msg);
    receive_response(sockfd);

    // Send RCPT TO message
    char rcpt_to_msg[256];
    snprintf(rcpt_to_msg, sizeof(rcpt_to_msg), "RCPT TO: <%s>\r\n", argv[3]);
    send_message(sockfd, rcpt_to_msg);
    receive_response(sockfd);

    // Send DATA message
    send_message(sockfd, "DATA\r\n");
    receive_response(sockfd);

    // Send email content
    char email_content[1024];
    printf("Enter email content (end with a single dot on a line): ");
    fflush(stdout);
    
    //Read email content
    char line[256];
    while (fgets(line, sizeof(line), stdin)) {
        if (strcmp(line, ".\n") == 0) {
            break;
        }

        strcat(email_content, line);
    }

    // Send email content
    send_message(sockfd, email_content);
    send_message(sockfd, ".\r\n");
    receive_response(sockfd);

    // Send QUIT message
    send_message(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    // Close socket
    close(sockfd);

    return 0;
}

void send_message(int sockfd, char* message)
{
    int n = strlen(message);
    if (write(sockfd, message, n) < 0) {
        fprintf(stderr, "Error: Could not send message\n");
        exit(1);
    }
}

void receive_response(int sockfd)
{
    char buffer[1024];
    int n;

    if ((n = read(sockfd, buffer, sizeof(buffer) - 1)) < 0) {
        fprintf(stderr, "Error: Could not receive response\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("%s", buffer);
}