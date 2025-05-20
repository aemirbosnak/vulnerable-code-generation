//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to send email using SMTP protocol
int send_email(char *to, char *subject, char *body) {
    int socket_fd, portno, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char sendmail[1024];

    portno = 25;
    server = gethostbyname("smtp.example.com");

    if (server == NULL) {
        fprintf(stderr, "Hostname not found\n");
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    if (connect(socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return -1;
    }

    memset(sendmail, 0, 1024);
    sprintf(sendmail, "Subject: %s\n\n%s", subject, body);

    n = write(socket_fd, sendmail, strlen(sendmail));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }

    close(socket_fd);
    return 0;
}

// Main function
int main() {
    char *to = "example@example.com";
    char *subject = "Test Email";
    char *body = "This is a test email";

    send_email(to, subject, body);
    printf("Email sent successfully!\n");

    return 0;
}