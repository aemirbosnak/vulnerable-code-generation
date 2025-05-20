//FormAI DATASET v1.0 Category: File Synchronizer ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

void sync_files(char *source_dir, char *dest_dir){
	struct dirent *entry;
	DIR *dir = opendir(source_dir);
	if (!dir) {
		return;
	}

	/*Create destination directory if not exists*/
	mkdir(dest_dir, 0777); 

	while ((entry = readdir(dir)) != NULL) {
		char path[1024];
		snprintf(path, sizeof(path), "%s/%s", source_dir, entry->d_name);

		struct stat statbuf;
		stat(path, &statbuf);

		if (S_ISDIR(statbuf.st_mode)) {
			if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) {
				continue;
			}
			char dest_path[1024];
			snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);
			sync_files(path, dest_path); /*Recursive sync for sub-directories*/
		} else {
			char dest_path[1024];
			snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);
			FILE *source_file, *dest_file;
			source_file = fopen(path, "rb");
			if(source_file) { /*check if source file exists*/
				dest_file = fopen(dest_path, "wb");
				if(dest_file) { /*open destination file for writing*/
					char buffer[1024];
					size_t size;
					while ((size = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
						fwrite(buffer, 1, size, dest_file);
					}
					/*Close the files*/
					fclose(source_file);
					fclose(dest_file);
					printf("%s %s\n", path, dest_path);
				}
			}
		}
	}

	closedir(dir);
}

int main(){
	char source_path[]="/home/user/source_directory";
	char dest_path[]="/home/user/destination_directory";	
	sync_files(source_path, dest_path);
	return 0;
}