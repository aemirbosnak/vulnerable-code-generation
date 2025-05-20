//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define PORT 21
#define BUFFER_SIZE 1024

typedef struct FTPClient {
    char username[256];
    char password[256];
    char host[256];
    int sockfd;
    struct FTPClient *next;
} FTPClient;

FTPClient *ftpClientHead = NULL;

void ftpClientAdd(char *username, char *password, char *host) {
    FTPClient *newClient = (FTPClient *)malloc(sizeof(FTPClient));
    strcpy(newClient->username, username);
    strcpy(newClient->password, password);
    strcpy(newClient->host, host);
    newClient->sockfd = -1;
    newClient->next = NULL;

    if (ftpClientHead == NULL) {
        ftpClientHead = newClient;
    } else {
        FTPClient *tempClient = ftpClientHead;
        while (tempClient->next) {
            tempClient = tempClient->next;
        }
        tempClient->next = newClient;
    }
}

int main() {
    ftpClientAdd("username", "password", "ftp.example.com");
    ftpClientAdd("another_username", "another_password", "ftp.example.com");

    FTPClient *client = ftpClientHead;
    while (client) {
        printf("Username: %s\n", client->username);
        printf("Password: %s\n", client->password);
        printf("Host: %s\n", client->host);
        printf("\n");
        client = client->next;
    }

    return 0;
}