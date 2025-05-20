//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 100000

char *filenames[MAX_FILES];
int file_sizes[MAX_FILES];
time_t file_timestamps[MAX_FILES];

int main() {
    // Open the log file
    int fd = open("/var/log/auth.log", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Read the log file line by line
    char line[1024];
    int counter=0;
    while (fgets(line, 1024, fd)) {
        // Parse the line
        char *timestamp = strtok(line, " ");
        char *username = strtok(NULL, " ");
        char *action = strtok(NULL, " ");
        char *filename = strtok(NULL, " ");

	if (strstr(line, "authentication failure")) {
		if (counter < MAX_FILES) {
			struct stat buf;
			// Get file size
			stat(filename, &buf);
			if (buf.st_size > MAX_FILE_SIZE) {
			// Check if file is too large
			printf("File %s is too large: %ld bytes\n", filename, buf.st_size);
			continue;
			}
			filenames[counter] = strdup(filename);
			file_sizes[counter] = buf.st_size;
			file_timestamps[counter] = time(NULL);

		}
		printf("User %s failed to authenticate to %s at %s\n", username, filename, timestamp);
	}
	counter++;
    }

    // Close the log file
    close(fd);
        
    // Now check if any files have been modified since the last time we checked
    for (int i = 0; i < counter; i++) {
        struct stat buf;
        stat(filenames[i], &buf);
	
	//Check timestamp
	if (file_timestamps[i] != buf.st_mtime) {
		printf("File %s has been modified since the last time we checked\n", filenames[i]);
	}
	//Check file size
	if (file_sizes[i] != buf.st_size) {
		printf("File %s has been modified since the last time we checked\n", filenames[i]);
	}
    }

    return 0;
}