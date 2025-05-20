//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Donald Knuth
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define SERV_PORT 110

static void usage(char *name)
{
	fprintf(stderr, "usage: %s <IP address> <user> <password>\n", name);
	exit(EXIT_FAILURE);
}

static void fatal_err(int err, char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(err));
	exit(EXIT_FAILURE);
}

static int pop3_connect(const char *ip, int port)
{
	struct sockaddr_in servaddr;
	int sockfd;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		fatal_err(errno, "socket");

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0)
		fatal_err(errno, "inet_pton");

	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		fatal_err(errno, "connect");

	return sockfd;
}

static void pop3_auth(int sockfd, const char *user, const char *pass)
{
	char buf[4096];
	char *cur;
	int len;

	len = sprintf(buf, "USER %s\r\n", user);
	if (send(sockfd, buf, len, 0) < len)
		fatal_err(errno, "send");
	if (recv(sockfd, buf, sizeof(buf), 0) <= 0)
		fatal_err(errno, "recv");
	if (strncmp(buf, "+OK", 3) != 0)
		fatal_err(ENOTCONN, "wrong response");

	len = sprintf(buf, "PASS %s\r\n", pass);
	if (send(sockfd, buf, len, 0) < len)
		fatal_err(errno, "send");
	if (recv(sockfd, buf, sizeof(buf), 0) <= 0)
		fatal_err(errno, "recv");
	if (strncmp(buf, "+OK", 3) != 0)
		fatal_err(ENOTCONN, "wrong response");

	fprintf(stdout, "Authentication successful.\n");
}

static void pop3_list(int sockfd)
{
	char buf[4096];
	char *cur;
	int len;

	if (send(sockfd, "LIST\r\n", 6, 0) < 6)
		fatal_err(errno, "send");
	while ((len = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
		if (strncmp(buf, "+OK", 3) == 0)
			break;
		cur = buf;
		while (len) {
			if (*cur == '\n')
				printf("  %s", cur + 1);
			cur++;
			len--;
		}
	}
	if (len <= 0)
		fatal_err(errno, "recv");

	fprintf(stdout, "Listing complete.\n");
}

static void pop3_retr(int sockfd, int msgid)
{
	char buf[4096];
	char *cur;
	int len;
	char filename[256] = {0};
	FILE *fp;
	int total = 0;

	snprintf(filename, sizeof(filename), "msg%d.txt", msgid);
	if ((fp = fopen(filename, "w")) == NULL)
		fatal_err(errno, "fopen");
	if (send(sockfd, "RETR %d\r\n", 10, 0) < 10)
		fatal_err(errno, "send");
	while ((len = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
		if (strncmp(buf, "+OK", 3) == 0)
			break;
		if (strncmp(buf, ".", 1) == 0)
			break;
		fwrite(buf, 1, len, fp);
		total += len;
	}
	fclose(fp);
	if (len <= 0)
		fatal_err(errno, "recv");

	fprintf(stdout, "Message %d retrieved (%d bytes).\n", msgid, total);
}

static void pop3_dele(int sockfd, int msgid)
{
	char buf[4096];
	int len;

	if (send(sockfd, "DELE %d\r\n", 10, 0) < 10)
		fatal_err(errno, "send");
	if (recv(sockfd, buf, sizeof(buf), 0) <= 0)
		fatal_err(errno, "recv");
	if (strncmp(buf, "+OK", 3) != 0)
		fatal_err(ENOTCONN, "wrong response");

	fprintf(stdout, "Message %d deleted.\n", msgid);
}

static void pop3_quit(int sockfd)
{
	char buf[4096];
	int len;

	if (send(sockfd, "QUIT\r\n", 6, 0) < 6)
		fatal_err(errno, "send");
	if (recv(sockfd, buf, sizeof(buf), 0) <= 0)
		fatal_err(errno, "recv");
	if (strncmp(buf, "+OK", 3) != 0)
		fatal_err(ENOTCONN, "wrong response");

	fprintf(stdout, "Connection closed.\n");
}

int main(int argc, char *argv[])
{
	int sockfd;

	if (argc != 4)
		usage(argv[0]);

	if ((sockfd = pop3_connect(argv[1], SERV_PORT)) < 0)
		exit(EXIT_FAILURE);

	pop3_auth(sockfd, argv[2], argv[3]);
	pop3_list(sockfd);
	pop3_retr(sockfd, 1);
	pop3_dele(sockfd, 1);
	pop3_quit(sockfd);

	exit(EXIT_SUCCESS);
}