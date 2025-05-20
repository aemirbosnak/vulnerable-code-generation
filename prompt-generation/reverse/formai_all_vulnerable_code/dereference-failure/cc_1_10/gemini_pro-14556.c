//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 32
#define MAX_TASK_CMD_LEN 128

typedef struct {
	char name[MAX_TASK_NAME_LEN];
	char cmd[MAX_TASK_CMD_LEN];
	time_t next_run_time;
	int interval; // in seconds
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, char *cmd, int interval) {
	if (num_tasks >= MAX_TASKS) {
		fprintf(stderr, "Error: Too many tasks\n");
		return;
	}

	strcpy(tasks[num_tasks].name, name);
	strcpy(tasks[num_tasks].cmd, cmd);
	tasks[num_tasks].next_run_time = time(NULL) + interval;
	tasks[num_tasks].interval = interval;
	num_tasks++;
}

void remove_task(char *name) {
	int i;

	for (i = 0; i < num_tasks; i++) {
		if (strcmp(tasks[i].name, name) == 0) {
			memmove(&tasks[i], &tasks[i + 1], sizeof(task_t) * (num_tasks - i - 1));
			num_tasks--;
			return;
		}
	}

	fprintf(stderr, "Error: Task not found\n");
}

void run_task(task_t *task) {
	pid_t pid;

	pid = fork();
	if (pid == 0) {
		execlp("/bin/sh", "sh", "-c", task->cmd, NULL);
		fprintf(stderr, "Error: Failed to execute task '%s': %s\n", task->name, strerror(errno));
		exit(1);
	} else if (pid < 0) {
		fprintf(stderr, "Error: Failed to fork: %s\n", strerror(errno));
	}
}

void handle_signal(int signum) {
	int i;

	for (i = 0; i < num_tasks; i++) {
		if (tasks[i].next_run_time <= time(NULL)) {
			run_task(&tasks[i]);
			tasks[i].next_run_time = time(NULL) + tasks[i].interval;
		}
	}

	alarm(1);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s config_file\n", argv[0]);
		return 1;
	}

	FILE *fp;
	char line[1024];
	char *task_name, *task_cmd, *task_interval;

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "Error: Could not open config file '%s': %s\n", argv[1], strerror(errno));
		return 1;
	}

	while (fgets(line, sizeof(line), fp) != NULL) {
		if (line[0] == '#' || line[0] == '\n') {
			continue;
		}

		task_name = strtok(line, " ");
		task_cmd = strtok(NULL, " ");
		task_interval = strtok(NULL, " ");
		if (task_name == NULL || task_cmd == NULL || task_interval == NULL) {
			fprintf(stderr, "Error: Invalid config line: '%s'\n", line);
			continue;
		}

		add_task(task_name, task_cmd, atoi(task_interval));
	}

	fclose(fp);

	signal(SIGALRM, handle_signal);
	alarm(1);

	while (1) {
		pause();
	}

	return 0;
}