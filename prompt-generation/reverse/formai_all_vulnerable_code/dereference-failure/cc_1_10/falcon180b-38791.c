//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define MAX 100
#define PORT "80"

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    char buffer[1025];
    char ip[16];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    FILE *fp;
    char line[1025];
    char *ptr;

    // Initialize variables
    memset(buffer, '\0', sizeof(buffer));
    memset(&serv_addr, 0, sizeof(serv_addr));
    memset(&cli_addr, 0, sizeof(cli_addr));

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error : Socket creation failed \n");
        exit(0);
    }

    // Set options on socket
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, (char *)&valread, sizeof(int));

    // Connect to server
    server = gethostbyname("www.google.com");
    if (server == NULL)
    {
        printf("Error : No such host \n");
        exit(0);
    }
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(PORT));

    // Send request to server
    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Receive response from server
    while ((valread = read(sockfd, buffer, sizeof(buffer))) > 0)
    {
        buffer[valread] = '\0';
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}