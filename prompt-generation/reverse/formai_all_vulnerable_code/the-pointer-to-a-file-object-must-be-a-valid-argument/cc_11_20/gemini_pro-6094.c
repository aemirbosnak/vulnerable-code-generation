//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: random
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MAX_TASKS 10

typedef struct {
	char *name;
	char *command;
	int interval;
	int last_run;
} task_t;

task_t tasks[MAX_TASKS];

int num_tasks = 0;

int main(int argc, char **argv) {
	int i;
	int fd;
	char buf[1024];
	FILE *fp;
	struct stat st;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s tasks.txt\n", argv[0]);
		exit(1);
	}

	if (stat(argv[1], &st) == -1) {
		fprintf(stderr, "Error: %s: %s\n", argv[1], strerror(errno));
		exit(1);
	}

	if ((fd = open(argv[1], O_RDONLY)) == -1) {
		fprintf(stderr, "Error: %s: %s\n", argv[1], strerror(errno));
		exit(1);
	}

	while (fgets(buf, sizeof(buf), fp) != NULL) {
		char *name, *command, *interval;

		if ((name = strtok(buf, ",")) == NULL) {
			fprintf(stderr, "Error: Invalid task format: %s\n", buf);
			continue;
		}

		if ((command = strtok(NULL, ",")) == NULL) {
			fprintf(stderr, "Error: Invalid task format: %s\n", buf);
			continue;
		}

		if ((interval = strtok(NULL, ",")) == NULL) {
			fprintf(stderr, "Error: Invalid task format: %s\n", buf);
			continue;
		}

		tasks[num_tasks].name = strdup(name);
		tasks[num_tasks].command = strdup(command);
		tasks[num_tasks].interval = atoi(interval);
		tasks[num_tasks].last_run = 0;

		num_tasks++;
	}

	close(fd);

	while (1) {
		for (i = 0; i < num_tasks; i++) {
			if (time(NULL) - tasks[i].last_run >= tasks[i].interval) {
				pid_t pid;

				if ((pid = fork()) == -1) {
					fprintf(stderr, "Error: fork: %s\n", strerror(errno));
					exit(1);
				} else if (pid == 0) {
					execlp(tasks[i].command, tasks[i].command, NULL);
					fprintf(stderr, "Error: execlp: %s\n", strerror(errno));
					exit(1);
				}

				tasks[i].last_run = time(NULL);
			}
		}

		sleep(1);
	}

	return 0;
}