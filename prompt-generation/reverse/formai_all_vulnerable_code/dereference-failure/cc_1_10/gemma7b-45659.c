//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 21
#define MAX_BUFFER_SIZE 1024

typedef struct FTPClient
{
    char username[255];
    char password[255];
    char hostname[255];
    int sockfd;
    struct FTPClient* next;
} FTPClient;

FTPClient* ftpClientHead = NULL;

void ftpClient_add(char* username, char* password, char* hostname)
{
    FTPClient* newClient = malloc(sizeof(FTPClient));
    strcpy(newClient->username, username);
    strcpy(newClient->password, password);
    strcpy(newClient->hostname, hostname);
    newClient->sockfd = -1;
    newClient->next = NULL;

    if (ftpClientHead == NULL)
    {
        ftpClientHead = newClient;
    }
    else
    {
        FTPClient* currentClient = ftpClientHead;
        while (currentClient->next)
        {
            currentClient = currentClient->next;
        }
        currentClient->next = newClient;
    }
}

void ftpClient_connect(FTPClient* client)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    client->sockfd = sockfd;

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(client->hostname);

    connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
}

void ftpClient_send(FTPClient* client, char* message)
{
    send(client->sockfd, message, strlen(message) + 1, 0);
}

void ftpClient_receive(FTPClient* client)
{
    char buffer[MAX_BUFFER_SIZE];
    int bytesReceived = recv(client->sockfd, buffer, MAX_BUFFER_SIZE, 0);
    buffer[bytesReceived] = '\0';

    printf("%s\n", buffer);
}

int main()
{
    ftpClient_add("username", "password", "localhost");
    ftpClient_add("another_username", "another_password", "localhost");

    FTPClient* client = ftpClientHead;
    while (client)
    {
        ftpClient_connect(client);
        ftpClient_send(client, "Hello, world!");
        ftpClient_receive(client);
        close(client->sockfd);
        client = client->next;
    }

    return 0;
}