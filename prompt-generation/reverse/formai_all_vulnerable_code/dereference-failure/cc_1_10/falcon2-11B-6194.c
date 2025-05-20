//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    SSL *ssl;
    FILE *fp;
    char *filename = "filename.txt";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    portno = htons(25);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = portno;
    serv_addr.sin_addr.s_addr = inet_addr("smtp.gmail.com");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    SSL_library_init();
    SSL_load_error_strings();
    ssl = SSL_new(SSLv23_client_method());
    if (SSL_connect(ssl) <= 0) {
        perror("ERROR connecting");
        exit(1);
    }
    SSL_write(ssl, "EHLO example.com\r\n", 12);
    SSL_write(ssl, "MAIL FROM:<sender@example.com>\r\n", 28);
    SSL_write(ssl, "RCPT TO:<receiver@example.com>\r\n", 20);
    SSL_write(ssl, "DATA\r\n", 5);
    SSL_write(ssl, "Subject: Test Email\r\n", 20);
    SSL_write(ssl, "This is a test email. \r\n.", 28);
    SSL_write(ssl, "\r\n.\r\n", 5);
    SSL_write(ssl, "QUIT\r\n", 6);
    SSL_shutdown(ssl);
    SSL_free(ssl);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    n = fread(buffer, 1, 1024, fp);
    if (n <= 0) {
        printf("Error reading file\n");
        exit(1);
    }

    SSL_write(ssl, buffer, n);
    fclose(fp);

    printf("Email Sent Successfully\n");

    close(sockfd);
    return 0;
}