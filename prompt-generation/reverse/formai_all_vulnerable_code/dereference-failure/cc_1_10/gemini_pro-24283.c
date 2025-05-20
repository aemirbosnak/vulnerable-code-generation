//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

struct process_info {
	int pid;
	char name[MAX_STRING_LENGTH];
	char state;
	unsigned long int utime;
	unsigned long int stime;
};

int compare_process_info(const void *a, const void *b) {
	const struct process_info *p1 = (const struct process_info *)a;
	const struct process_info *p2 = (const struct process_info *)b;

	return strcmp(p1->name, p2->name);
}

int main(void) {
	// Get the current working directory.
	char cwd[MAX_STRING_LENGTH];
	if (getcwd(cwd, MAX_STRING_LENGTH) == NULL) {
		perror("getcwd");
		return EXIT_FAILURE;
	}

	// Open the directory containing the process information.
	DIR *dir = opendir("/proc");
	if (dir == NULL) {
		perror("opendir");
		return EXIT_FAILURE;
	}

	// Allocate an array to store the process information.
	struct process_info *processes = malloc(sizeof(struct process_info) * 1024);
	if (processes == NULL) {
		perror("malloc");
		return EXIT_FAILURE;
	}

	// Read the directory and parse the process information.
	int num_processes = 0;
	struct dirent *ent;
	while ((ent = readdir(dir)) != NULL) {
		// Skip the "." and ".." directories.
		if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
			continue;
		}

		// Get the process ID.
		int pid = atoi(ent->d_name);
		if (pid == 0) {
			continue;
		}

		// Read the process status file.
		char filename[MAX_STRING_LENGTH];
		snprintf(filename, MAX_STRING_LENGTH, "/proc/%d/status", pid);
		FILE *file = fopen(filename, "r");
		if (file == NULL) {
			perror("fopen");
			continue;
		}

		// Parse the process status file.
		char buffer[MAX_STRING_LENGTH];
		while (fgets(buffer, MAX_STRING_LENGTH, file) != NULL) {
			// Get the process name.
			if (strncmp(buffer, "Name:", 5) == 0) {
				sscanf(buffer, "Name: %s", processes[num_processes].name);
			}

			// Get the process state.
			if (strncmp(buffer, "State:", 6) == 0) {
				sscanf(buffer, "State: %c", &processes[num_processes].state);
			}

			// Get the process user time.
			if (strncmp(buffer, "Utime:", 6) == 0) {
				sscanf(buffer, "Utime: %lu", &processes[num_processes].utime);
			}

			// Get the process system time.
			if (strncmp(buffer, "Stime:", 6) == 0) {
				sscanf(buffer, "Stime: %lu", &processes[num_processes].stime);
			}
		}

		fclose(file);

		// Store the process information.
		processes[num_processes].pid = pid;
		num_processes++;
	}

	closedir(dir);

	// Sort the process information by name.
	qsort(processes, num_processes, sizeof(struct process_info), compare_process_info);

	// Print the process information.
	printf("PID	Name	State	Utime	Stime\n");
	for (int i = 0; i < num_processes; i++) {
		printf("%d	%s	%c	%lu	%lu\n", processes[i].pid,
			processes[i].name, processes[i].state, processes[i].utime,
			processes[i].stime);
	}

	free(processes);

	return EXIT_SUCCESS;
}