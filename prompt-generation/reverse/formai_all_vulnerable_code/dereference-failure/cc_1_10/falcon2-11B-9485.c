//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 25

int main() {
    // Create a socket
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send email
    printf("Enter the recipient email address: ");
    char recipient[256];
    fgets(recipient, 256, stdin);
    recipient[strcspn(recipient, "\n")] = '\0';

    printf("Enter the subject of the email: ");
    char subject[256];
    fgets(subject, 256, stdin);
    subject[strcspn(subject, "\n")] = '\0';

    printf("Enter the body of the email: ");
    char body[4096];
    fgets(body, 4096, stdin);
    body[strcspn(body, "\n")] = '\0';

    // Send email
    if (sendmail(sockfd, recipient, subject, body) < 0) {
        perror("ERROR sending email");
        exit(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}

int sendmail(int sockfd, char *recipient, char *subject, char *body) {
    int len = strlen(body);

    if (len > 0 && (body[len - 1] == '\n' || body[len - 1] == '\r')) {
        body[len - 1] = '\0';
    }

    int n = write(sockfd, recipient, strlen(recipient));
    if (n < 0) {
        perror("ERROR writing recipient");
        return -1;
    }

    n = write(sockfd, " ", 1);
    if (n < 0) {
        perror("ERROR writing space");
        return -1;
    }

    n = write(sockfd, subject, strlen(subject));
    if (n < 0) {
        perror("ERROR writing subject");
        return -1;
    }

    n = write(sockfd, " ", 1);
    if (n < 0) {
        perror("ERROR writing space");
        return -1;
    }

    n = write(sockfd, body, strlen(body));
    if (n < 0) {
        perror("ERROR writing body");
        return -1;
    }

    return 0;
}