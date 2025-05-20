//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 256

struct rule {
	char *src_ip;
	char *dst_ip;
	int src_port;
	int dst_port;
	int protocol;
	int action;
};

struct firewall {
	struct rule rules[MAX_RULES];
	int num_rules;
};

int load_rules(struct firewall *fw, char *filename) {
	FILE *fp;
	char line[MAX_RULE_LEN];
	int i = 0;

	fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("fopen");
		return -1;
	}

	while (fgets(line, MAX_RULE_LEN, fp) != NULL) {
		if (line[0] == '#') {
			continue;
		}

		fw->rules[i].src_ip = strtok(line, " ");
		fw->rules[i].dst_ip = strtok(NULL, " ");
		fw->rules[i].src_port = atoi(strtok(NULL, " "));
		fw->rules[i].dst_port = atoi(strtok(NULL, " "));
		fw->rules[i].protocol = atoi(strtok(NULL, " "));
		fw->rules[i].action = atoi(strtok(NULL, " "));

		i++;
	}

	fw->num_rules = i;

	fclose(fp);

	return 0;
}

int check_rule(struct rule *rule, struct sockaddr_in *src_addr, struct sockaddr_in *dst_addr) {
	int match = 1;

	if (rule->src_ip != NULL && strcmp(rule->src_ip, inet_ntoa(src_addr->sin_addr)) != 0) {
		match = 0;
	}

	if (rule->dst_ip != NULL && strcmp(rule->dst_ip, inet_ntoa(dst_addr->sin_addr)) != 0) {
		match = 0;
	}

	if (rule->src_port != 0 && rule->src_port != src_addr->sin_port) {
		match = 0;
	}

	if (rule->dst_port != 0 && rule->dst_port != dst_addr->sin_port) {
		match = 0;
	}

	if (rule->protocol != 0 && rule->protocol != src_addr->sin_family) {
		match = 0;
	}

	return match;
}

int main(int argc, char **argv) {
	struct firewall fw;
	struct sockaddr_in src_addr, dst_addr;
	int sockfd, newsockfd, i;
	socklen_t addrlen;
	char buffer[1024];

	if (argc < 2) {
		printf("Usage: %s <rules file>\n", argv[0]);
		return 1;
	}

	if (load_rules(&fw, argv[1]) != 0) {
		return 1;
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("socket");
		return 1;
	}

	memset(&src_addr, 0, sizeof(src_addr));
	src_addr.sin_family = AF_INET;
	src_addr.sin_addr.s_addr = INADDR_ANY;
	src_addr.sin_port = htons(80);

	if (bind(sockfd, (struct sockaddr *)&src_addr, sizeof(src_addr)) < 0) {
		perror("bind");
		return 1;
	}

	listen(sockfd, 5);

	while (1) {
		addrlen = sizeof(dst_addr);
		newsockfd = accept(sockfd, (struct sockaddr *)&dst_addr, &addrlen);
		if (newsockfd < 0) {
			perror("accept");
			continue;
		}

		for (i = 0; i < fw.num_rules; i++) {
			if (check_rule(&fw.rules[i], &src_addr, &dst_addr)) {
				if (fw.rules[i].action == 0) {
					close(newsockfd);
					break;
				}
			}
		}

		if (i == fw.num_rules) {
			while (read(newsockfd, buffer, sizeof(buffer)) > 0) {
				write(newsockfd, buffer, strlen(buffer));
			}
		}

		close(newsockfd);
	}

	close(sockfd);

	return 0;
}