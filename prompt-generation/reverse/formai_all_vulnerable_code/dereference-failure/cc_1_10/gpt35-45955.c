//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to calculate directory size
long long int calculateSize(const char* directory) {
	struct dirent *direntry;
	struct stat statinfo;
	DIR *dir;
	long long int size = 0;

	dir = opendir(directory);

	// Return if directory is invalid or could not be opened
	if (!dir) {
		printf("Could not open directory: %s", directory);
		return -1;
	}

	while ((direntry = readdir(dir)) != NULL) {
		char filepath[1024];

		// Ignore "." and ".." directories
		if (strcmp(direntry->d_name, ".") == 0 || strcmp(direntry->d_name, "..") == 0) {
			continue;
		}

		// Get full file path
		sprintf(filepath, "%s/%s", directory, direntry->d_name);

		if (stat(filepath, &statinfo) == -1) {
			printf("Could not get file info for: %s\n", filepath);
			continue;
		}

		// Directory: recursively calculate its size
		if (S_ISDIR(statinfo.st_mode)) {
			long long int subdirsize = calculateSize(filepath);
			if (subdirsize == -1) {
				continue;
			}
			size += subdirsize;
		}
		// File: add its size
		else if (S_ISREG(statinfo.st_mode)) {
			size += (long long int) statinfo.st_size;
		}
	}

	closedir(dir);

	return size;
}

int main() {
	char directory[1024];

	// Get directory to analyze from user
	printf("Enter the directory to analyze: ");
	fgets(directory, 1024, stdin);
	directory[strlen(directory) - 1] = '\0';

	// Calculate size and print results
	long long int size = calculateSize(directory);
	if (size != -1) {
		printf("Size of directory %s is: %lld bytes\n", directory, size);
	}

	return 0;
}