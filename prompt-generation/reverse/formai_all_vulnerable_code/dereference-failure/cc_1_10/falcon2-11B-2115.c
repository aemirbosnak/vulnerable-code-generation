//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

// Connect to server
int connectToServer(const char* hostname, int port) {
    struct hostent *server;
    struct sockaddr_in addr;
    int s;

    server = gethostbyname(hostname);

    if (server == NULL) {
        fprintf(stderr, "Error: hostname not found\n");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = *((unsigned long*)server->h_addr);

    s = socket(AF_INET, SOCK_STREAM, 0);

    if (s < 0) {
        perror("Error opening socket");
        return -1;
    }

    if (connect(s, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("Error connecting");
        return -1;
    }

    return s;
}

// List directory
void listDirectory(int s, char* dir) {
    char buffer[256];
    char* filename;

    while (1) {
        bzero(buffer, sizeof(buffer));

        if (read(s, buffer, sizeof(buffer)) <= 0)
            break;

        filename = strtok(buffer, "\n");

        while (filename!= NULL) {
            printf("%s\n", filename);

            filename = strtok(NULL, "\n");
        }
    }

    close(s);
}


int main() {
    int s;
    char hostname[] = "example.com";
    int port = 21;

    s = connectToServer(hostname, port);

    if (s < 0) {
        perror("Error connecting to server");
        return -1;
    }

    char dir[] = "/public_html";
    listDirectory(s, dir);

    return 0;
}