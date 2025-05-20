//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 4096 // Maximum line length of POP3 protocol

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    // Check whether the user has entered the POP3 server hostname and port number
    if (argc != 3) {
        printf("Usage: %s <POP3 server hostname> <POP3 port number>\n", argv[0]);
        exit(1);
    }

    // Convert the POP3 server hostname to IP address
    struct hostent *he;
    if ((he = gethostbyname(argv[1])) == NULL) {
        printf("Error: Invalid POP3 server hostname\n");
        exit(1);
    }

    // Create a TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Cannot create socket\n");
        exit(1);
    }

    // Initialize the server address structure
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr = *((struct in_addr *) he->h_addr);

    // Connect to the POP3 server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("Error: Cannot connect to POP3 server\n");
        exit(1);
    }

    // Read the welcome message from the POP3 server
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send POP3 USER command to the server
    char* command = "USER myusername\r\n";
    write(sockfd, command, strlen(command));

    // Read the response from the server
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send POP3 PASS command to the server
    command = "PASS mypassword\r\n";
    write(sockfd, command, strlen(command));

    // Read the response from the server
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send POP3 STAT command to the server
    command = "STAT\r\n";
    write(sockfd, command, strlen(command));

    // Read the response from the server
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    // Parse the response to get the total number of emails and their total size
    int num_emails, size_emails;
    sscanf(recvline, "+OK %d %d", &num_emails, &size_emails);

    // Loop through the emails and download each one
    for (int i = 1; i <= num_emails; i++) {
        // Send POP3 RETR command to the server
        char command[MAXLINE];
        sprintf(command, "RETR %d\r\n", i);
        write(sockfd, command, strlen(command));

        // Read the response from the server
        n = read(sockfd, recvline, MAXLINE);
        recvline[n] = '\0';
        printf("%s", recvline);

        // Create a file to save the email contents
        char filename[MAXLINE];
        sprintf(filename, "email_%d.txt", i);
        FILE* fp = fopen(filename, "wb");

        // Loop through the email contents and write them to the file
        while (1) {
            n = read(sockfd, recvline, MAXLINE);
            recvline[n] = '\0';
            if (strstr(recvline, ".\r\n") != NULL) {
                break;
            }
            fwrite(recvline, sizeof(char), n, fp);
        }

        // Close the file
        fclose(fp);
    }

    // Send POP3 QUIT command to the server
    command = "QUIT\r\n";
    write(sockfd, command, strlen(command));

    // Read the response from the server
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    // Close the TCP socket
    close(sockfd);

    return 0;
}