//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HTTP_HEADER_SIZE 8192
#define BUFSIZE 4096

//Function to extract hostname and path from the given URL
int parse_url(const char *url, char *hostname, char *path) {
    const char *ptr_start, *ptr_end;

    //Check if the URL starts with "http://"
    if(strncmp(url, "http://", 7)) {
        fprintf(stderr, "URL should start with http://\n");
        return -1;
    }

    //Extract hostname and start of path
    ptr_start = url + 7;
    ptr_end = strpbrk(ptr_start, "/");

    //Copy hostname to the buffer
    if(ptr_end == NULL) {
        strcpy(hostname, ptr_start);
        strcpy(path, "/");
    } else {
        strncpy(hostname, ptr_start, ptr_end - ptr_start);
        strcpy(path, ptr_end);
    }

    return 0;
}

//Function to build HTTP request
void build_http_request(char *http_request, const char *hostname, const char *path) {
    sprintf(http_request, "GET %s HTTP/1.1\r\n", path);
    sprintf(http_request + strlen(http_request), "Host: %s\r\n", hostname);
    sprintf(http_request + strlen(http_request), "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:88.0) Gecko/20100101 Firefox/88.0\r\n");
    sprintf(http_request + strlen(http_request), "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n");
    sprintf(http_request + strlen(http_request), "Connection: close\r\n\r\n");
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    char hostname[256], path[1024];
    struct sockaddr_in servaddr;
    struct hostent *he;

    //Check command line arguments
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    //Parse URL to extract hostname and path
    if(parse_url(argv[1], hostname, path) < 0)
        exit(1);

    //Get host address
    if((he = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "Error: Unable to resolve hostname %s\n", hostname);
        exit(1);
    }

    //Create socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error: Unable to create socket\n");
        exit(1);
    }

    //Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    memcpy(&servaddr.sin_addr, he->h_addr_list[0], he->h_length);

    //Connect to server
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error: Unable to connect to server\n");
        exit(1);
    }

    //Build and send HTTP request
    char http_request[MAX_HTTP_HEADER_SIZE];
    build_http_request(http_request, hostname, path);
    write(sockfd, http_request, strlen(http_request));

    //Print received HTTP response header
    char buf[BUFSIZE];
    char *end_of_header = "\r\n\r\n";
    char *header_end;
    int header_size = 0;
    do {
        n = read(sockfd, buf, BUFSIZE - 1);
        if(n < 0) {
            fprintf(stderr, "Error: Unable to read from socket\n");
            exit(1);
        }
        buf[n] = '\0';
        header_size += n;
        printf("%s", buf);
        header_end = strstr(buf, end_of_header);
    } while(header_end == NULL && header_size < MAX_HTTP_HEADER_SIZE);

    //Print received HTTP response body
    int body_size = 0;
    if(header_end != NULL) {
        header_size = header_end - buf + strlen(end_of_header);
        body_size = n - header_size;
        printf("%.*s", body_size, buf + header_size);
    }
    while((n = read(sockfd, buf, BUFSIZE)) > 0) {
        body_size += n;
        printf("%.*s", n, buf);
    }

    //Close socket
    close(sockfd);

    return 0;
}