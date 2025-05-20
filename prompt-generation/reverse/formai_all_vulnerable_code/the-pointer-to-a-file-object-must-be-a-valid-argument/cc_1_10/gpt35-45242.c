//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_LINES 1000
#define MAX_FILE_NAME_LEN 256
#define MAX_LINE_LEN 256

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    int file_size;
} file_data;

void scan_folder(char* folder_path, file_data* files, int* count) {
  /* recursive function to scan the folder and subfolders for files */

  char command[MAX_LINE_LEN];
  sprintf(command,"ls -p %s", folder_path);

  FILE* fd = popen(command, "r");  /* run ls command */

  char line[MAX_LINE_LEN];
  while( fgets(line, sizeof(line), fd) ) {

    char* end_char = line + strlen(line) - 1;  /* get rid of newline character */
    if( *end_char == '\n' ) {
      *end_char = '\0';
    }

    if( strcmp(line,"./") == 0 || strcmp(line,"../") == 0 ) {
      continue;  /* ignore hidden folders and parent folders */
    }

    char full_path[MAX_LINE_LEN];
    sprintf(full_path,"%s/%s",folder_path,line);
    char command2[MAX_LINE_LEN];
    sprintf(command2,"stat -c %%s %s", full_path);  /* run stat command */

    FILE* fd2 = popen(command2, "r");
    char size_str[MAX_LINE_LEN];
    fgets(size_str, sizeof(size_str), fd2);  /* get file size */
    files[*count].file_size = atoi(size_str);
    strcpy(files[*count].file_name, full_path);

    if( files[*count].file_size > 0 ){
        (*count)++;
    }

    pclose(fd2);
  }
  pclose(fd);

}

void sort_files_by_size(file_data* files, int count) {
  /* sorting function to sort files by size using bubble sort algorithm */

  for(int i=0; i<count; i++) {
    for(int j=i+1; j<count; j++) {
      if( files[i].file_size < files[j].file_size ) {
        file_data temp = files[i];
        files[i] = files[j];
        files[j] = temp;
      }
    }
  }
}

void display_files_by_size(file_data* files, int count) {
  /* display function to print the file names and sizes */

  for(int i=0; i<count; i++) {
    printf("%s (%d bytes)\n",files[i].file_name,files[i].file_size);
  }
}

int main(int argc, char** argv) {

  if(argc != 2) {
    printf("Usage: disk_space_analyzer <folder_path>\n");
    return 0;
  }

  char folder_path[MAX_LINE_LEN];
  if( realpath(argv[1], folder_path) == NULL ) {
    printf("Error: Invalid Folder Path\n");
    return 0;
  }

  file_data files[MAX_FILES];
  int count = 0;

  scan_folder(folder_path, files, &count);

  sort_files_by_size(files, count);

  display_files_by_size(files, count);

  return 0;
}