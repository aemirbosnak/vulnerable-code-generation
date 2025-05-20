//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0
#define MAX 100
#define PORT "80"

struct hostent *host;
int sock;
char buffer[1024];
char ip[16];
int count = 0;

void scan(char *ip) {
    int port = htons(atoi(PORT));
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = port;
    inet_pton(AF_INET, ip, &server.sin_addr);
    connect(sock, (struct sockaddr *)&server, sizeof(server));
    send(sock, "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: Close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: Close\r\n\r\n"), 0);
    char ch;
    while (recv(sock, &ch, 1, 0) > 0) {
        printf("%c", ch);
    }
    close(sock);
    count++;
}

void *scanner(void *arg) {
    char *ip = (char *) arg;
    scan(ip);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s IP_Address\n", argv[0]);
        exit(0);
    }
    strcpy(ip, argv[1]);
    host = gethostbyname(ip);
    if (host == NULL) {
        printf("Invalid IP Address\n");
        exit(0);
    }
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        exit(0);
    }
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, scanner, (void *) ip);
    pthread_join(thread_id, NULL);
    close(sock);
    printf("Scan Completed. %d hosts found.\n", count);
    return 0;
}