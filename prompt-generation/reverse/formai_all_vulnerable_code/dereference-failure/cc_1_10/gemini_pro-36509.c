//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: Ken Thompson
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }
    
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname '%s'\n", argv[1]);
        exit(1);
    }
    
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    memcpy(&addr.sin_addr, host->h_addr_list[0], host->h_length);
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error: could not create socket");
        exit(1);
    }
    
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error: could not connect to host");
        exit(1);
    }
    
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    if (read(sock, buf, sizeof(buf)) == -1) {
        perror("Error: could not read from socket");
        exit(1);
    }
    
    printf("%s\n", buf);
    
    close(sock);
    return 0;
}