//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define SMTP_PORT 25
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
	int sockfd, len;
	char buf[MAX_BUF_SIZE];
	struct sockaddr_in servaddr;
	FILE *fp;

	if (argc != 4) {
		fprintf(stderr, "Usage: %s <host> <sender> <recipient>\n", argv[0]);
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("socket");
		exit(1);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SMTP_PORT);
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
		perror("inet_pton");
		exit(1);
	}

	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		perror("connect");
		exit(1);
	}

	if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
		perror("recv");
		exit(1);
	}
	printf("%s", buf);

	snprintf(buf, MAX_BUF_SIZE, "HELO %s\r\n", argv[0]);
	if (send(sockfd, buf, strlen(buf), 0) < 0) {
		perror("send");
		exit(1);
	}

	if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
		perror("recv");
		exit(1);
	}
	printf("%s", buf);

	snprintf(buf, MAX_BUF_SIZE, "MAIL FROM: <%s>\r\n", argv[2]);
	if (send(sockfd, buf, strlen(buf), 0) < 0) {
		perror("send");
		exit(1);
	}

	if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
		perror("recv");
		exit(1);
	}
	printf("%s", buf);

	snprintf(buf, MAX_BUF_SIZE, "RCPT TO: <%s>\r\n", argv[3]);
	if (send(sockfd, buf, strlen(buf), 0) < 0) {
		perror("send");
		exit(1);
	}

	if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
		perror("recv");
		exit(1);
	}
	printf("%s", buf);

	snprintf(buf, MAX_BUF_SIZE, "DATA\r\n");
	if (send(sockfd, buf, strlen(buf), 0) < 0) {
		perror("send");
		exit(1);
	}

	if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
		perror("recv");
		exit(1);
	}
	printf("%s", buf);

	fp = fopen("message.txt", "r");
	if (fp == NULL) {
		perror("fopen");
		exit(1);
	}

	while ((len = fread(buf, 1, MAX_BUF_SIZE, fp)) > 0) {
		if (send(sockfd, buf, len, 0) < 0) {
			perror("send");
			exit(1);
		}
	}

	fclose(fp);

	snprintf(buf, MAX_BUF_SIZE, ".\r\n");
	if (send(sockfd, buf, strlen(buf), 0) < 0) {
		perror("send");
		exit(1);
	}

	if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
		perror("recv");
		exit(1);
	}
	printf("%s", buf);

	snprintf(buf, MAX_BUF_SIZE, "QUIT\r\n");
	if (send(sockfd, buf, strlen(buf), 0) < 0) {
		perror("send");
		exit(1);
	}

	if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
		perror("recv");
		exit(1);
	}
	printf("%s", buf);

	close(sockfd);
	return 0;
}