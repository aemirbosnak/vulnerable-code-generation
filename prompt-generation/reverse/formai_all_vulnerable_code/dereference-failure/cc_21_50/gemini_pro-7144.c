//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SMTP_PORT 25

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <recipient>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    char *recipient = argv[2];

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
    {
        perror("socket()");
        return EXIT_FAILURE;
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL)
    {
        fprintf(stderr, "gethostbyname(): %s\n", hstrerror(h_errno));
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SMTP_PORT);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect()");
        return EXIT_FAILURE;
    }

    char buffer[1024];
    int bytes_read;

    bytes_read = recv(fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0)
    {
        perror("recv()");
        return EXIT_FAILURE;
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    if (strncmp(buffer, "220", 3) != 0)
    {
        fprintf(stderr, "SMTP server did not respond with a 220 greeting\n");
        return EXIT_FAILURE;
    }

    snprintf(buffer, sizeof(buffer), "EHLO %s\r\n", hostname);
    if (send(fd, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        return EXIT_FAILURE;
    }

    bytes_read = recv(fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0)
    {
        perror("recv()");
        return EXIT_FAILURE;
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    if (strncmp(buffer, "250", 3) != 0)
    {
        fprintf(stderr, "SMTP server did not respond with a 250 EHLO response\n");
        return EXIT_FAILURE;
    }

    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", argv[0]);
    if (send(fd, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        return EXIT_FAILURE;
    }

    bytes_read = recv(fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0)
    {
        perror("recv()");
        return EXIT_FAILURE;
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    if (strncmp(buffer, "250", 3) != 0)
    {
        fprintf(stderr, "SMTP server did not respond with a 250 MAIL FROM response\n");
        return EXIT_FAILURE;
    }

    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", recipient);
    if (send(fd, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        return EXIT_FAILURE;
    }

    bytes_read = recv(fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0)
    {
        perror("recv()");
        return EXIT_FAILURE;
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    if (strncmp(buffer, "250", 3) != 0)
    {
        fprintf(stderr, "SMTP server did not respond with a 250 RCPT TO response\n");
        return EXIT_FAILURE;
    }

    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    if (send(fd, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        return EXIT_FAILURE;
    }

    bytes_read = recv(fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0)
    {
        perror("recv()");
        return EXIT_FAILURE;
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    if (strncmp(buffer, "354", 3) != 0)
    {
        fprintf(stderr, "SMTP server did not respond with a 354 DATA response\n");
        return EXIT_FAILURE;
    }

    snprintf(buffer, sizeof(buffer), "Subject: Test email\r\n\r\nThis is a test email.\r\n.\r\n");
    if (send(fd, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        return EXIT_FAILURE;
    }

    bytes_read = recv(fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0)
    {
        perror("recv()");
        return EXIT_FAILURE;
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    if (strncmp(buffer, "250", 3) != 0)
    {
        fprintf(stderr, "SMTP server did not respond with a 250 DATA response\n");
        return EXIT_FAILURE;
    }

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    if (send(fd, buffer, strlen(buffer), 0) < 0)
    {
        perror("send()");
        return EXIT_FAILURE;
    }

    bytes_read = recv(fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0)
    {
        perror("recv()");
        return EXIT_FAILURE;
    }

    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    if (strncmp(buffer, "221", 3) != 0)
    {
        fprintf(stderr, "SMTP server did not respond with a 221 QUIT response\n");
        return EXIT_FAILURE;
    }

    close(fd);

    return EXIT_SUCCESS;
}