//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        fprintf(stderr,"ERROR opening socket\n");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        fprintf(stderr,"ERROR connecting\n");

    n = read(sockfd,buffer,1024);
    if (n < 0) 
        fprintf(stderr,"ERROR reading from socket\n");

    printf("%s\n",buffer);

    char sender[50], recipient[50], subject[100], message[1000];

    printf("To: ");
    fgets(recipient, 50, stdin);
    printf("Subject: ");
    fgets(subject, 100, stdin);
    printf("Message: ");
    fgets(message, 1000, stdin);

    sprintf(sender, "MAIL FROM: <%s>\r\n", argv[3]);
    sprintf(recipient, "RCPT TO: <%s>\r\n", recipient);
    sprintf(subject, "Subject: %s\r\n", subject);
    sprintf(message, "\r\n%s\r\n.\r\n", message);

    char *data[4];
    data[0] = sender;
    data[1] = recipient;
    data[2] = subject;
    data[3] = message;

    for (int i = 0; i < 4; i++) {
        n = write(sockfd, data[i], strlen(data[i]));
        if (n < 0)
            fprintf(stderr,"ERROR writing to socket\n");
        memset(buffer, 0, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer)-1);
        if (n < 0) 
            fprintf(stderr,"ERROR reading from socket\n");
        printf("%s\n",buffer);
    }

    close(sockfd);
    return 0;
}