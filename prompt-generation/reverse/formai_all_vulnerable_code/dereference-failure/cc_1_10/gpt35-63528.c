//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFF_SIZE 1024

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Usage: %s [hostname] [username] [password]\n", argv[0]);
        exit(1);
    }
    
    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL)
    {
        printf("ERROR: Could not resolve host name %s\n", hostname);
        exit(1);
    }
    
    struct sockaddr_in addr;
    memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(143);
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("ERROR: Failed to open socket\n");
        exit(1);
    }
    
    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        printf("ERROR: Failed to connect to server\n");
        close(sockfd);
        exit(1);
    }
    
    char buff[MAX_BUFF_SIZE];
    int bytes_read;
    memset(buff, 0, MAX_BUFF_SIZE);
    bytes_read = read(sockfd, buff, MAX_BUFF_SIZE);
    printf("%s", buff);
    
    memset(buff, 0, MAX_BUFF_SIZE);
    sprintf(buff, "a01 login %s %s\n", username, password);
    write(sockfd, buff, strlen(buff));
    
    memset(buff, 0, MAX_BUFF_SIZE);
    bytes_read = read(sockfd, buff, MAX_BUFF_SIZE);
    printf("%s", buff);

    memset(buff, 0, MAX_BUFF_SIZE);
    sprintf(buff, "a02 list \"\" *\n");
    write(sockfd, buff, strlen(buff));
    
    memset(buff, 0, MAX_BUFF_SIZE);
    bytes_read = read(sockfd, buff, MAX_BUFF_SIZE);
    printf("%s", buff);

    close(sockfd);
    
    return 0;
}