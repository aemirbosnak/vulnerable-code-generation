//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
 
#define PORT 80
 
int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        fprintf(stderr, "%s: can't resolve %s\n", argv[0], argv[1]);
        exit(EXIT_FAILURE);
    }
 
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port   = htons(PORT)
    };
    memcpy(&addr.sin_addr, host->h_addr_list[0], sizeof(addr.sin_addr));
 
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }
 
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }
 
    char *request = "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\nAccept: */*\r\n\r\n";
    char buffer[4096];
 
    int len = snprintf(buffer, sizeof(buffer), request, argv[1], "Mozilla/5.0 (X11; Linux x86_64; rv:68.0) Gecko/20100101 Firefox/68.0");
 
    if (write(sock, buffer, len) != len) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }
 
    int bytes_read;
    do {
        bytes_read = read(sock, buffer, sizeof(buffer));
        if (bytes_read < 0) {
            perror("read() failed");
            exit(EXIT_FAILURE);
        }
        fwrite(buffer, bytes_read, 1, stdout);
    } while (bytes_read > 0);
 
    close(sock);
 
    return 0;
}