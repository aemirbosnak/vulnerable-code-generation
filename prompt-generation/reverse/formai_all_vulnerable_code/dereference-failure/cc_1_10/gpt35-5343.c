//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 25

// Function to send SMTP commands
void sendCommand(int sockfd, char *cmd){
    int n = strlen(cmd);
    write(sockfd, cmd, n);
    printf("SENT: %s", cmd);
}

int main(int argc, char *argv[]){
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Check for command line arguments
    if (argc < 3){
        fprintf(stderr,"Usage: %s hostname sender_address\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        perror("ERROR opening socket");
        exit(1);
    }

    // Get SMTP server information using DNS lookup
    server = gethostbyname(argv[1]);
    if (server == NULL){
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    // Initialize server address struct
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    portno = PORT;

    // Connect to SMTP server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0){
        perror("ERROR connecting");
        exit(1);
    }

    // Read banner from SMTP server
    char buffer[512];
    int n = read(sockfd, buffer, sizeof(buffer));
    printf("RECEIVED: %s", buffer);

    // Send EHLO command
    sendCommand(sockfd, "EHLO localhost\r\n");
    n = read(sockfd, buffer, sizeof(buffer));
    printf("RECEIVED: %s", buffer);

    // Send MAIL FROM command
    char cmd[512];
    sprintf(cmd, "MAIL FROM: <%s>\r\n", argv[2]);
    sendCommand(sockfd, cmd);
    n = read(sockfd, buffer, sizeof(buffer));
    printf("RECEIVED: %s", buffer);

    // Send QUIT command
    sendCommand(sockfd, "QUIT\r\n");
    n = read(sockfd, buffer, sizeof(buffer));
    printf("RECEIVED: %s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}