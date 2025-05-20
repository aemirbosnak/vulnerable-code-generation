//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(0);
}

void receive(int sock, char *buffer, int size)
{
    int total = 0, n = 0;
    while (total < size)
    {
        n = recv(sock, buffer + total, size - total, 0);
        if (n < 0)
            error("ERROR reading from socket");
        total += n;
    }
}

void send_command(int sock, char *command)
{
    if (send(sock, command, strlen(command), 0) < 0)
        error("ERROR writing to socket");
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "usage: %s hostname port username\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        error("ERROR opening socket");

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    char buffer[BUFFER_SIZE];

    receive(sock, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    send_command(sock, buffer);

    receive(sock, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    snprintf(buffer, BUFFER_SIZE, "PASS ");
    char *password = getpass("Enter your password: ");
    strncat(buffer, password, BUFFER_SIZE - strlen(buffer) - 3);
    strncat(buffer, "\r\n", BUFFER_SIZE - strlen(buffer) - 1);

    send_command(sock, buffer);

    receive(sock, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    send_command(sock, "STAT\r\n");

    receive(sock, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    int num_messages = 0, total_size = 0;
    sscanf(buffer, "+OK %d %d", &num_messages, &total_size);

    for (int i = 1; i <= num_messages; i++)
    {
        snprintf(buffer, BUFFER_SIZE, "TOP %d 0\r\n", i);
        send_command(sock, buffer);

        receive(sock, buffer, BUFFER_SIZE);
        printf("%s\n", buffer);

        char *ptr = strstr(buffer, "\r\n\r\n");
        if (ptr == NULL)
            continue;

        printf("%s", ptr + 4);
    }

    send_command(sock, "QUIT\r\n");

    receive(sock, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    close(sock);

    return 0;
}