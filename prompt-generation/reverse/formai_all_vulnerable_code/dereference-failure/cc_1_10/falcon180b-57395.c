//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define SERVER_PORT 25
#define SERVER_ADDR "127.0.0.1"
#define USERNAME "testuser"
#define PASSWORD "testpassword"

int main()
{
    int sock, ret, val;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    char username[64] = USERNAME;
    char password[64] = PASSWORD;
    char *auth_str = NULL;
    int auth_len = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDR, &server_addr.sin_addr);

    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1)
    {
        printf("Error connecting to server\n");
        return 1;
    }

    auth_str = (char *)malloc(64 * 2 + 1);
    snprintf(auth_str, 64 * 2 + 1, "LOGIN %s %s", username, password);
    auth_len = strlen(auth_str);

    send(sock, auth_str, auth_len, 0);

    while (1)
    {
        memset(buffer, 0, BUF_SIZE);
        ret = recv(sock, buffer, BUF_SIZE, 0);
        if (ret <= 0)
        {
            printf("Error receiving data\n");
            break;
        }

        printf("%s", buffer);
    }

    close(sock);
    free(auth_str);
    return 0;
}