//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT        21                      /* FTP TCP Port */
#define MAXBUF      1024                    /* Maximum buffer size */
#define SERVER_ADDR "ftp.example.com"      /* FTP Server Address */

int main()
{
    int sockFd;
    struct sockaddr_in srvAddr;
    char buffer[MAXBUF + 1];

    SSL_CTX *ssl_ctx;
    SSL *client_ssl;

    /* Initialize SSL Library */
    SSL_library_init();
    SSL_load_error_strings();
    ssl_ctx = SSL_CTX_new(SSLv23_client_method());

    /* Create TCP Socket */
    if ((sockFd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error Creating Socket: %s\n", strerror(errno));
        exit(errno);
    }

    /* Connect to FTP Server */
    memset(&srvAddr, 0, sizeof(srvAddr));
    srvAddr.sin_family = AF_INET;
    srvAddr.sin_port = htons(PORT);
    inet_aton(SERVER_ADDR, (struct in_addr *) &srvAddr.sin_addr.s_addr);

    if (connect(sockFd, (struct sockaddr *) &srvAddr, sizeof(srvAddr)) != 0)
    {
        printf("Error Connecting to Server: %s\n", strerror(errno));
        exit(errno);
    }

    /* Create SSL Connection */
    client_ssl = SSL_new(ssl_ctx);
    SSL_set_fd(client_ssl, sockFd);
    if (SSL_connect(client_ssl) == -1)
    {
        printf("Error Establishing SSL Connection: %s\n", strerror(errno));
        exit(errno);
    }

    /* Login to FTP Server */
    SSL_write(client_ssl, "USER username\r\n", strlen("USER username\r\n"));
    SSL_read(client_ssl, buffer, MAXBUF);
    printf("Response: %s", buffer);

    SSL_write(client_ssl, "PASS password\r\n", strlen("PASS password\r\n"));
    SSL_read(client_ssl, buffer, MAXBUF);
    printf("Response: %s", buffer);

    /* Enter Passive Mode and List Files */
    SSL_write(client_ssl, "PASV\r\n", strlen("PASV\r\n"));
    SSL_read(client_ssl, buffer, MAXBUF);
    printf("Response: %s", buffer);

    int i, j, k;
    int dataSockFd;
    struct sockaddr_in dataPortAddr;
    char dataPort[MAXBUF + 1];
    char *ptr, *start_ptr, *end_ptr;
    int port_num[2];

    /* Parse Data Port Number from PASV Response */
    start_ptr = strchr(buffer, '(');
    end_ptr = strchr(buffer, ')');
    ptr = start_ptr + 1;
    j = 0;
    k = 0;
    for (i = 0; i < strlen(ptr); i++)
    {
        if (ptr[i] == ',')
        {
            port_num[k++] = atoi(&ptr[j]);
            j = i + 1;
        }
        if (k == 2)
        {
            port_num[k++] = atoi(&ptr[j]);
            break;
        }
    }
    sprintf(dataPort, "%d.%d.%d.%d", port_num[0], port_num[1], port_num[2], port_num[3]);

    /* Connect to Data Port */
    if ((dataSockFd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error Creating Socket: %s\n", strerror(errno));
        exit(errno);
    }

    memset(&dataPortAddr, 0, sizeof(dataPortAddr));
    dataPortAddr.sin_family = AF_INET;
    dataPortAddr.sin_port = htons(port_num[4] * 256 + port_num[5]);
    inet_aton(dataPort, (struct in_addr *) &dataPortAddr.sin_addr.s_addr);

    if (connect(dataSockFd, (struct sockaddr *) &dataPortAddr, sizeof(dataPortAddr)) != 0)
    {
        printf("Error Connecting to Server: %s\n", strerror(errno));
        exit(errno);
    }

    /* Retrieve FTP Directory Listing */
    SSL_write(client_ssl, "LIST\r\n", strlen("LIST\r\n"));
    SSL_read(client_ssl, buffer, MAXBUF);
    printf("Response: %s", buffer);

    memset(buffer, 0, sizeof(buffer));
    recv(dataSockFd, buffer, MAXBUF, 0);
    printf("%s", buffer);

    /* Close Data Port and SSL Connection */
    SSL_write(client_ssl, "QUIT\r\n", strlen("QUIT\r\n"));
    SSL_read(client_ssl, buffer, MAXBUF);
    printf("Response: %s", buffer);

    SSL_free(client_ssl);
    SSL_CTX_free(ssl_ctx);
    close(dataSockFd);
    close(sockFd);

    return 0;
}