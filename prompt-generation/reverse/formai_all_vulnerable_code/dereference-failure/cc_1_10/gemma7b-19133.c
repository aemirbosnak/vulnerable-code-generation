//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FTPClient
{
    char hostname[256];
    int port;
    char username[256];
    char password[256];
    int socketfd;
    char buffer[MAX_BUFFER_SIZE];
    struct FTPClient* next;
} FTPClient;

FTPClient* ftpClientHead = NULL;

void ftpClientAdd(char* hostname, int port, char* username, char* password)
{
    FTPClient* newClient = (FTPClient*)malloc(sizeof(FTPClient));
    strcpy(newClient->hostname, hostname);
    newClient->port = port;
    strcpy(newClient->username, username);
    strcpy(newClient->password, password);
    newClient->socketfd = -1;
    newClient->next = NULL;

    if (ftpClientHead == NULL)
    {
        ftpClientHead = newClient;
    }
    else
    {
        FTPClient* lastClient = ftpClientHead;
        while (lastClient->next)
        {
            lastClient = lastClient->next;
        }
        lastClient->next = newClient;
    }
}

void ftpClientConnect(FTPClient* client)
{
    client->socketfd = socket(AF_INET, SOCK_STREAM, htons(client->port));
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(client->port);
    inet_aton(client->hostname, &serverAddr.sin_addr);

    connect(client->socketfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
}

void ftpClientSend(FTPClient* client, char* message)
{
    send(client->socketfd, message, strlen(message), 0);
}

void ftpClientReceive(FTPClient* client)
{
    char* buffer = malloc(MAX_BUFFER_SIZE);
    int bytesRead = recv(client->socketfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);
    free(buffer);
}

int main()
{
    ftpClientAdd("localhost", 21, "username", "password");
    ftpClientConnect(ftpClientHead);
    ftpClientSend(ftpClientHead, "Hello, world!");
    ftpClientReceive(ftpClientHead);

    return 0;
}