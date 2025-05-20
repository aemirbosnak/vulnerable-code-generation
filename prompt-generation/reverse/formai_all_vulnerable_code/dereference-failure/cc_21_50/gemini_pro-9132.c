//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    char *hostname = "smtp.gmail.com";
    int port = 587;
    char *username = "your_email_address";
    char *password = "your_password";
    char *recipient = "recipient@example.com";
    char *subject = "Test Email";
    char *body = "Hello, this is a test email.";

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL)
    {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Read the SMTP server's greeting
    char buffer[1024];
    if (recv(sock, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the EHLO command
    sprintf(buffer, "EHLO %s\r\n", hostname);
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sock, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Start TLS
    sprintf(buffer, "STARTTLS\r\n");
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sock, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the EHLO command again
    sprintf(buffer, "EHLO %s\r\n", hostname);
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sock, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Authenticate with the SMTP server
    sprintf(buffer, "AUTH LOGIN\r\n");
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sock, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the username
    sprintf(buffer, "%s\r\n", username);
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sock, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the password
    sprintf(buffer, "%s\r\n", password);
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sock, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: %s\r\n", username);
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sock, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO: %s\r\n", recipient);
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sock, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sock, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the email body
    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sock, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(sock, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sock, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}