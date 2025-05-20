//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUF_SIZE 1024

void error(char* msg);

int main(int argc, char* argv[])
{
    if(argc!= 4)
    {
        printf("Usage: %s <ip_address> <username> <password>\n", argv[0]);
        return 1;
    }

    char* ip_address = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1)
    {
        error("socket failed");
    }

    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        error("connect failed");
    }

    char* login_cmd = (char*)malloc(BUF_SIZE);
    sprintf(login_cmd, "USER %s\r\n", username);

    send(sock, login_cmd, strlen(login_cmd), 0);

    char* pass_cmd = (char*)malloc(BUF_SIZE);
    sprintf(pass_cmd, "PASS %s\r\n", password);

    send(sock, pass_cmd, strlen(pass_cmd), 0);

    char buffer[BUF_SIZE];

    while(1)
    {
        memset(buffer, 0, BUF_SIZE);

        if(recv(sock, buffer, BUF_SIZE, 0) == 0)
        {
            break;
        }

        printf("%s", buffer);
    }

    close(sock);

    return 0;
}

void error(char* msg)
{
    printf("Error: %s\n", msg);
    exit(1);
}