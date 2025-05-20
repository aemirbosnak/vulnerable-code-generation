//FormAI DATASET v1.0 Category: File Synchronizer ; Style: automated
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>

//function to recursively traverse through directories and synchronize files
void traverse_dirs(char* src_dir,char* dest_dir,int* sync_count,int* skip_count){
  DIR* src = opendir(src_dir);
  DIR* dest = opendir(dest_dir);

  //check if directories can be opened
  if(src==NULL||dest==NULL){
    printf("Error opening directory: %s\n",strerror(errno));
    exit(EXIT_FAILURE);
  }

  struct dirent* src_entry;
  struct dirent* dest_entry;

  //iterate through all entries in the source directory
  while((src_entry = readdir(src)) != NULL){
    if(strcmp(src_entry->d_name,".")==0||strcmp(src_entry->d_name,"..")==0){
      //skip current and parent directories
      continue;
    }
    //construct full paths for source and destination
    char src_path[1000];
    char dest_path[1000];
    strcpy(src_path,src_dir);
    strcat(src_path,"/");
    strcat(src_path,src_entry->d_name);
    strcpy(dest_path,dest_dir);
    strcat(dest_path,"/");
    strcat(dest_path,src_entry->d_name);
    //check if the source entry is a directory
    if(src_entry->d_type==DT_DIR){
      //if it is, create the corresponding directory in the dest if it doesn't exist
      struct stat st = {0};
      if(stat(dest_path, &st) == -1){
        mkdir(dest_path,0700);
      }
      //recursively traverse the directories
      traverse_dirs(src_path,dest_path,sync_count,skip_count);
    }
    else{
      //if source entry is a file, attempt to open it for reading
      int src_fd = open(src_path,O_RDONLY);
      if(src_fd==-1){
        printf("Error opening file %s: %s\n",src_path,strerror(errno));
        continue;
      }
      //attempt to open destination for writing
      int dest_fd = open(dest_path,O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
      if(dest_fd==-1){
        printf("Error opening file %s: %s\n",dest_path,strerror(errno));
        close(src_fd);
        continue;
      }
      //read source file into buffer and write it to destination file
      char buffer[1024];
      ssize_t num_read;
      ssize_t num_written;
      while((num_read=read(src_fd,buffer,1024))>0){
        num_written=write(dest_fd,buffer,num_read);
        if(num_written!=num_read){
          printf("Error writing to file %s: %s\n",dest_path,strerror(errno));
          close(src_fd);
          close(dest_fd);
          exit(EXIT_FAILURE);
        }
      }
      //compare file sizes to ensure they are the same
      struct stat src_stat;
      struct stat dest_stat;

      if(stat(src_path,&src_stat)==-1){
        printf("Error getting file stats %s: %s\n",src_path,strerror(errno));
        close(src_fd);
        close(dest_fd);
        continue;
      }
      if(stat(dest_path,&dest_stat)==-1){
        printf("Error getting file stats %s: %s\n",dest_path,strerror(errno));
        close(src_fd);
        close(dest_fd);
        continue;
      }
      //if file sizes are equal, synchronization was successful
      if(src_stat.st_size==dest_stat.st_size){
        printf("Synchronized %s and %s\n",src_path,dest_path);
        (*sync_count)++;
      }
      else{
        printf("Skipping %s and %s (sizes do not match)\n",src_path,dest_path);
        (*skip_count)++;
      }
      //close file descriptors
      close(src_fd);
      close(dest_fd);
    }
  }
  //close directories
  closedir(src);
  closedir(dest);
}

int main(int argc, char** argv){
  if(argc!=3){
    printf("Usage: %s <source directory> <destination directory>\n",argv[0]);
    exit(EXIT_FAILURE);
  }

  int sync_count = 0;
  int skip_count = 0;

  traverse_dirs(argv[1],argv[2],&sync_count,&skip_count);

  printf("Synchronization complete. %d files synchronized, %d files skipped.\n",sync_count,skip_count);

  exit(EXIT_SUCCESS);
}