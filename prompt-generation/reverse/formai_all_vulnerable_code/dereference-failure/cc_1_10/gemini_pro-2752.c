//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: retro
// Step into the world of retro computing with our SMTP client!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Socket wizardry
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>

// Our trusty SMTP commands
#define HELO "HELO retromail.com\r\n"
#define MAIL_FROM "MAIL FROM: <sender@retromail.com>\r\n"
#define RCPT_TO "RCPT TO: <recipient@retromail.com>\r\n"
#define DATA "DATA\r\n"
#define SUBJECT "Subject: Retro Email\r\n"
#define BODY "Greetings from the past!\n"
#define QUIT "\r\n.\r\nQUIT\r\n"

int main(int argc, char **argv)
{
    // Welcome, traveler!
    printf("Welcome to our SMTP Adventure!\n");

    // Initialize our socket connection
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // Prepare our server's information
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    struct hostent *host = gethostbyname("smtp.retromail.com");
    memcpy(&server.sin_addr.s_addr, host->h_addr, host->h_length);
    server.sin_port = htons(25);

    // Connect to the server
    connect(sock, (struct sockaddr *)&server, sizeof(server));

    // Exchange greetings with the server
    char buffer[1024];
    read(sock, buffer, 1024);
    printf("Server: %s", buffer);
    write(sock, HELO, strlen(HELO));
    read(sock, buffer, 1024);
    printf("Server: %s", buffer);

    // Identify the sender
    write(sock, MAIL_FROM, strlen(MAIL_FROM));
    read(sock, buffer, 1024);
    printf("Server: %s", buffer);

    // Specify the recipient
    write(sock, RCPT_TO, strlen(RCPT_TO));
    read(sock, buffer, 1024);
    printf("Server: %s", buffer);

    // Prepare our email
    write(sock, DATA, strlen(DATA));
    read(sock, buffer, 1024);
    printf("Server: %s", buffer);
    write(sock, SUBJECT, strlen(SUBJECT));
    write(sock, BODY, strlen(BODY));

    // Send our email
    write(sock, QUIT, strlen(QUIT));
    read(sock, buffer, 1024);
    printf("Server: %s", buffer);

    // Close the connection
    close(sock);

    // Farewell, adventurer!
    printf("Your email has been dispatched to the past!\n");

    return 0;
}