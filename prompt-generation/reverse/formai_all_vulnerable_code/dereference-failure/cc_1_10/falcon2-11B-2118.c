//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: safe
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_MSG_LEN 512
#define MAX_ADDR_LEN 100

int main()
{
    int socket_fd, status;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;
    char msg[MAX_MSG_LEN], addr[MAX_ADDR_LEN];

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        exit(1);
    }

    server = gethostbyname("smtp.example.com");
    if (server == NULL)
    {
        fprintf(stderr, "ERROR: Unknown host\n");
        exit(1);
    }

    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    if ((status = connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))) < 0)
    {
        perror("connect");
        exit(1);
    }

    printf("Enter your email address: ");
    fgets(addr, MAX_ADDR_LEN, stdin);
    addr[strcspn(addr, "\n")] = '\0';

    printf("Enter the recipient's email address: ");
    fgets(addr, MAX_ADDR_LEN, stdin);
    addr[strcspn(addr, "\n")] = '\0';

    printf("Enter the subject: ");
    fgets(msg, MAX_MSG_LEN, stdin);
    msg[strcspn(msg, "\n")] = '\0';

    printf("Enter the message: ");
    fgets(msg, MAX_MSG_LEN, stdin);
    msg[strcspn(msg, "\n")] = '\0';

    if (send(socket_fd, msg, strlen(msg), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    if (recv(socket_fd, msg, MAX_MSG_LEN, 0) < 0)
    {
        perror("recv");
        exit(1);
    }

    printf("Message received: %s\n", msg);

    close(socket_fd);
    return 0;
}