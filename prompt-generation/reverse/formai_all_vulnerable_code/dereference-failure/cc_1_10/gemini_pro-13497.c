//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_MIN 0
#define PORT_MAX 65535

int main(int argc, char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;
	int port;
	int ret;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <ip address> <port number>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("socket()");
		exit(EXIT_FAILURE);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) == -1) {
		perror("inet_pton()");
		exit(EXIT_FAILURE);
	}

	ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if (ret == -1) {
		perror("connect()");
		exit(EXIT_FAILURE);
	}

	printf("Port %d is open on %s\n", atoi(argv[2]), argv[1]);

	close(sockfd);
	exit(EXIT_SUCCESS);
}