//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define DEFAULT_PORT 8000
#define MAX_PENDING 10
#define MAXLINE 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, const char *argv[]) {
    int sockfd, new_sockfd, server_port;
    struct sockaddr_in server_addr, client_addr;
	socklen_t client_len;
    char buffer[MAXLINE];
    pid_t child_pid;
	
	if (argc < 2) {
		server_port = DEFAULT_PORT;
	} else {
		server_port = atoi(argv[1]);
	}
	
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
	
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(server_port);
	
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("ERROR on binding");
    }
	
    if (listen(sockfd, MAX_PENDING) < 0) {
        error("ERROR on listening");
    }
    fprintf(stdout, "Server is listening on port %d\n", server_port);
	
    while (1) {
        client_len = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (new_sockfd < 0) {
            error("ERROR on accept");
        }
		
        child_pid = fork();
        if (child_pid < 0) {
            error("ERROR on fork");
        }
		
        if (child_pid == 0) {
            close(sockfd);
			struct sockaddr_in remote_server_addr;
			char *remote_ip_address = "www.example.com";
			int remote_port = 80;
			memset(&remote_server_addr, 0, sizeof(remote_server_addr));
			remote_server_addr.sin_family = AF_INET;
			remote_server_addr.sin_port = htons(remote_port);
			
			if (inet_pton(AF_INET, remote_ip_address, &remote_server_addr.sin_addr) <= 0) {
				error("ERROR on inet_pton");
			}
			
			if (connect(new_sockfd, (struct sockaddr *) &remote_server_addr, sizeof(remote_server_addr)) < 0) {
				error("ERROR on connect");
			}
			
			ssize_t n;
			while ((n = read(new_sockfd, buffer, MAXLINE)) > 0) {
				if (write(STDOUT_FILENO, buffer, n) != n) {
					error("ERROR on write to stdout");
				}
				
				if (write(new_sockfd, buffer, n) != n) {
					error("ERROR on write to remote server");
				}
			}
			
			if (n < 0) {
				error("ERROR on read");
			}
			
			close(new_sockfd);
			exit(EXIT_SUCCESS);
        } else {
            close(new_sockfd);
        }
    }
	
    close(sockfd);
	return 0;
}