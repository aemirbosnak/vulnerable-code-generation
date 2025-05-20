//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Let's connect to an FTP server!
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    // Where are we connecting to?
    printf("Enter the FTP server's IP address or hostname: ");
    scanf("%s", buffer);

    // What port should we use?
    printf("Enter the FTP port number (usually 21): ");
    scanf("%d", &portno);

    // Let's find out more about the server
    server = gethostbyname(buffer);
    if (server == NULL) {
        printf("Couldn't find that server! Are you sure it's a valid hostname or IP address?\n");
        return 1;
    }

    // Create a socket, like a window to the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Oops, couldn't create a socket! Maybe something's wrong with your network settings.\n");
        return 1;
    }

    // Fill in the server's address details
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to the server!
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Hmm, couldn't connect to the server. Maybe it's offline or your firewall is blocking us.\n");
        return 1;
    }

    // Hooray, we're connected! Let's say hello and get a welcome message
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server says: %s\n", buffer);

    // Now let's log in using a silly username and password
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "USER ftpuser");
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server says: %s\n", buffer);

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "PASS ftppassword");
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server says: %s\n", buffer);

    // Let's list the files in the server's current directory
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "LIST");
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    while (recv(sockfd, buffer, sizeof(buffer), 0) > 0) {
        printf("%s", buffer);
    }

    // Time to say goodbye!
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "QUIT");
    send(sockfd, buffer, strlen(buffer), 0);

    // Close the socket, we're all done!
    close(sockfd);

    // And we're done! Hopefully you had a fun little FTP adventure. 😊
    printf("Bye for now!\n");
    return 0;
}