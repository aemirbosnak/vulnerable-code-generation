//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_SUBJECT_LEN 256
#define MAX_MSG_LEN 1024

struct email {
    char from[256];
    char to[256];
    char subject[MAX_SUBJECT_LEN];
    char msg[MAX_MSG_LEN];
};

int main(int argc, char **argv)
{
    // Check arguments
    if (argc != 5) {
        printf("Usage: %s <server> <port> <from> <to>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get server and port
    char *server = argv[1];
    int port = atoi(argv[2]);

    // Get sender and recipient
    char *from = argv[3];
    char *to = argv[4];

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }
    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Create email
    struct email email;
    memset(&email, 0, sizeof(email));
    strncpy(email.from, from, sizeof(email.from));
    strncpy(email.to, to, sizeof(email.to));
    strncpy(email.subject, "My love for thee", sizeof(email.subject));
    strncpy(email.msg, "My dearest Juliet,\n\n"
                       "I write to thee with a heart full of love and longing.\n"
                       "My love for thee is as deep as the ocean and as wide as the sky.\n"
                       "I cannot live without thee, my Juliet.\n\n"
                       "I have sworn to thee my love, and I will never break that oath.\n"
                       "I will love thee forever and always.\n\n"
                       "Thy Romeo", sizeof(email.msg));

    // Send email
    int n = send(sockfd, &email, sizeof(email), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive response
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print response
    printf("%s\n", buf);

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}