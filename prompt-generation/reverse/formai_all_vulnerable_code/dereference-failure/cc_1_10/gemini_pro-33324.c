//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define MAX_LINE 1024

void DieWithError(char *errorMessage) {
    perror(errorMessage);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in servAddr;
    struct hostent *hp;
    char hostname[MAX_LINE];
    char from[MAX_LINE];
    char to[MAX_LINE];
    char subject[MAX_LINE];
    char body[MAX_LINE];
    
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <from> <to> <subject>\n", argv[0]);
        exit(1);
    }
    
    strcpy(hostname, argv[1]);
    strcpy(from, argv[2]);
    strcpy(to, argv[3]);
    strcpy(subject, argv[4]);
    
    // Get server address
    if ((hp = gethostbyname(hostname)) == NULL) {
        herror("gethostbyname");
        exit(1);
    }
    
    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        DieWithError("socket");
    }
    
    // Set address info
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(25);
    memcpy(&servAddr.sin_addr, hp->h_addr, hp->h_length);
    
    // Connect to server
    if (connect(sock, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
        DieWithError("connect");
    }
    // Get welcome message
    char welcome[MAX_LINE];
    if (recv(sock, welcome, MAX_LINE, 0) < 0) {
        DieWithError("recv");
    }
    printf("%s", welcome);
    
    printf("Enter body (finish with single dot):\n");
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stdin) != -1) {
        if (strcmp(line, ".\n") == 0) {
            break;
        }
        strcat(body, line);
    }
    
    // Send email
    char email[MAX_LINE];
    sprintf(email, "MAIL FROM: <%s>\r\n", from);
    send(sock, email, strlen(email), 0);
    
    if (recv(sock, email, MAX_LINE, 0) < 0) {
        DieWithError("recv");
    }
    printf("%s", email);
    
    sprintf(email, "RCPT TO: <%s>\r\n", to);
    send(sock, email, strlen(email), 0);
    
    if (recv(sock, email, MAX_LINE, 0) < 0) {
        DieWithError("recv");
    }
    printf("%s", email);
    
    sprintf(email, "DATA\r\n");
    send(sock, email, strlen(email), 0);
    
    if (recv(sock, email, MAX_LINE, 0) < 0) {
        DieWithError("recv");
    }
    printf("%s", email);
    
    sprintf(email, "Subject: %s\r\n", subject);
    send(sock, email, strlen(email), 0);
    
    sprintf(email, "To: <%s>\r\n", to);
    send(sock, email, strlen(email), 0);
    
    sprintf(email, "From: <%s>\r\n\r\n", from);
    send(sock, email, strlen(email), 0);
    
    sprintf(email, "%s\r\n", body);
    send(sock, email, strlen(email), 0);
    
    sprintf(email, ".\r\n");
    send(sock, email, strlen(email), 0);
    
    if (recv(sock, email, MAX_LINE, 0) < 0) {
        DieWithError("recv");
    }
    printf("%s", email);
    
    // Close connection
    close(sock);
    
    return 0;
}