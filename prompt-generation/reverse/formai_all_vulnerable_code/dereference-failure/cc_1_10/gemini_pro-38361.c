//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

typedef struct {
	char *name;
	long long size;
} FileInfo;

int compare_files(const void *a, const void *b) {
	FileInfo *fa = (FileInfo *)a;
	FileInfo *fb = (FileInfo *)b;
	return fa->size > fb->size ? -1 : 1;
}

int main() {
	printf("Let's take a cheerful journey into the depths of your C drive!\n");

	// Declare an array to store file information
	FileInfo files[1000];
	int num_files = 0;

	// Open the root directory
	DIR *dir = opendir("C:\\");

	if (dir == NULL) {
		printf("Oops! We couldn't open the root directory. Are you sure it's there?\n");
		return 1;
	}

	// Iterate through the directory and get file information
	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
			continue;
		}

		char path[512];
		sprintf(path, "C:\\%s", entry->d_name);

		FileInfo file;
		file.name = strdup(path);
		file.size = 0;

		FILE *f = fopen(path, "rb");
		if (f != NULL) {
			fseek(f, 0, SEEK_END);
			file.size = ftell(f);
			fclose(f);
		}

		files[num_files++] = file;
	}

	closedir(dir);

	// Sort the files by size (largest first)
	qsort(files, num_files, sizeof(FileInfo), compare_files);

	// Print a cheerful table of the top 10 largest files
	printf("\nTop 10 Largest Files on Your C Drive:\n");
	printf("----------------------------------------\n");
	printf("| %-30s | %-10s |\n", "Filename", "Size (KB)");
	printf("----------------------------------------\n");
	for (int i = 0; i < 10 && i < num_files; i++) {
		printf("| %-30s | %-10lld |\n", files[i].name, files[i].size / 1024);
	}

	printf("\nEnjoy your newfound disk space awareness! :)\n");

	return 0;
}