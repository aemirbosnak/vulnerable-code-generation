//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    // Check if user has provided enough arguments
    if (argc != 3) 
    {
        printf("Usage: %s <Server IP> <Port No.>\n", argv[0]);
        exit(1);
    }

    // Create socket and endpoint of communication
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {   
        perror("Error: Unable to create socket");
        exit(1);
    }

    // Set the values in the sockaddr_in structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2])); // Convert string to integer and store as network byte order
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {   
        perror("inet_pton error");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {   
        perror("Error: Unable to connect to POP3 server");
        exit(1);
    }

    // Read the response from server
    if ((n = read(sockfd, recvline, MAXLINE)) < 0)
    {   
        perror("Error: Unable to read response from server");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // Authentication
    char username[MAXLINE], password[MAXLINE];
    printf("Enter username: ");
    fgets(username, MAXLINE, stdin);
    printf("Enter password: ");
    fgets(password, MAXLINE, stdin);
    char authstring[MAXLINE + 6];
    sprintf(authstring, "USER %sPASS %s", username, password);
    if (write(sockfd, authstring, strlen(authstring)) < 0)
    {   
        perror("Error: Unable to auth user");
        exit(1);
    }

    // Quit
    if (write(sockfd, "QUIT\n", strlen("QUIT\n")) < 0)
    {   
        perror("Error: Unable to quit POP3 server");
        exit(1);
    }

    exit(0);
}