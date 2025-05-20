//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25

struct knight {
    char name[20];
    int sword;
};

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char message[256];
    char smtp_reply[256];
    char greeting[] = "Greetings, noble SMTP server! Thy humble servant, Sir ";
    char from[] = "From: Sir Coder@KingdomOfCode.realm\r\n";
    char to[] = "To: Lady Email@Gmail.com\r\n";
    char subject[] = "Subject: A message from thy lord\r\n";
    char rcpt_to[] = "Rcpt to: Lady Email@Gmail.com\r\n";
    char data[] = "Data\r\n";
    char sendmail[] = "MAIL FROM:<Sir Coder@KingdomOfCode.realm>\r\n";
    char enddata[] = ".\r\n.";
    char quit[] = "QUIT\r\n";

    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        exit(1);
    }

    strcpy(message, argv[1]);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Error converting IP to binary form");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    // Greet the SMTP server
    write(sockfd, greeting, strlen(greeting) + strlen(argv[0]));

    // Send email details
    write(sockfd, from, strlen(from));
    write(sockfd, to, strlen(to));
    write(sockfd, subject, strlen(subject));

    // Receive SMTP server response
    read(sockfd, smtp_reply, 256);
    printf("%s", smtp_reply);

    // Send recipient address
    write(sockfd, rcpt_to, strlen(rcpt_to));

    // Receive SMTP server response
    read(sockfd, smtp_reply, 256);
    printf("%s", smtp_reply);

    // Send message data
    write(sockfd, data, strlen(data));

    // Send message
    write(sockfd, message, strlen(message));

    // Send end of message
    write(sockfd, enddata, strlen(enddata));

    // Quit the SMTP session
    write(sockfd, quit, strlen(quit));

    close(sockfd);
    return 0;
}