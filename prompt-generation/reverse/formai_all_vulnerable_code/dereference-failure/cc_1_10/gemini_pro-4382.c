//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: cheerful
// Let's build a cheerful SMTP client!

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

// Helper function to send a command and print the response
int send_command(int sockfd, char* command) {
    if (send(sockfd, command, strlen(command), 0) == -1)
        return -1;  // Send failed
    char response[1024];
    if (recv(sockfd, response, sizeof(response), 0) == -1)
        return -1;  // Receive failed
    printf("%s", response);
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Be optimistic, let's brighten up the world!
    printf("Hello, SMTP world!\n");

    // Create a socket, but let's not be too serious about it ;)
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Set up the server address, let's go on an adventure!
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server, let's make some friends!
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Say hello to the server, let's start a conversation!
    if (send_command(sockfd, "EHLO client\r\n") == -1) {
        perror("send_command");
        return 1;
    }

    // Send the MAIL FROM command, let's be the first to write!
    if (send_command(sockfd, "MAIL FROM: <sender@example.com>\r\n") == -1) {
        perror("send_command");
        return 1;
    }

    // Send the RCPT TO command, let's pick a recipient!
    if (send_command(sockfd, "RCPT TO: <recipient@example.com>\r\n") == -1) {
        perror("send_command");
        return 1;
    }

    // Prepare the email data, let's spread some joy!
    char email_data[] = "Subject: Be Happy!\n\n"
                         "Hello friend,\n"
                         "\n"
                         "Hope this email finds you well. I'm writing to share a little bit of sunshine with you today. Remember, happiness is a choice and it's always within reach. Spread smiles, kindness, and laughter wherever you go. Let's make the world a brighter place, one email at a time!\n"
                         "\n"
                         "Cheers,\n"
                         "Your Cheerful Friend";

    // Send the DATA command, let's start writing!
    if (send_command(sockfd, "DATA\r\n") == -1) {
        perror("send_command");
        return 1;
    }

    // Send the email data, let the joy flow!
    if (send(sockfd, email_data, strlen(email_data), 0) == -1) {
        perror("send");
        return 1;
    }

    // Send the dot, let's wrap it up!
    if (send_command(sockfd, ".\r\n") == -1) {
        perror("send_command");
        return 1;
    }

    // Say goodbye to the server, let's part ways with a smile!
    if (send_command(sockfd, "QUIT\r\n") == -1) {
        perror("send_command");
        return 1;
    }

    // Close the socket, let's not linger!
    close(sockfd);

    // Mission accomplished, let's celebrate with a cheer!
    printf("Email sent! May it bring joy to the recipient!\n");

    return 0;
}