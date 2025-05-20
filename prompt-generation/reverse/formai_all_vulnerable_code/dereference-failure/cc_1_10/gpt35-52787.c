//FormAI DATASET v1.0 Category: File Synchronizer ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<time.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>

#define BUF_SIZE 1024
#define TIME_SIZE 20

//Function Declarations
void synchronize(char* src, char* dest);
char* get_full_path(char* path, char* name);
void handle_error(char* msg);
void make_dir(char* path);
int copy_file(char* src, char* dest);
void sync_files(char* src, char* dest);
void sync_dirs(char* src, char* dest);

int main(int argc, char* argv[]) {
    if(argc!=3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    synchronize(argv[1], argv[2]);
    printf("File synchronization successful!\n");

    return 0;
}

void synchronize(char* src, char* dest) {
    DIR* dir;
    struct dirent* entry;
    char* full_path;
    struct stat st_buf;

    //Check if source exists
    if((dir=opendir(src))==NULL) {
        handle_error("opendir");
    }

    //Create destination directory if not exists
    make_dir(dest);

    while((entry=readdir(dir))!=NULL) {
        //Ignore "." and ".." directories
        if(strcmp(entry->d_name, ".")==0 || strcmp(entry->d_name, "..")==0) {
            continue;
        }

        //Get full path of source file/dir
        full_path=get_full_path(src, entry->d_name);

        //Get file/dir metadata
        if(stat(full_path, &st_buf)==-1) {
            handle_error("stat");
        }

        //Synchronize files
        if(S_ISREG(st_buf.st_mode)) { //Regular file
            sync_files(full_path, get_full_path(dest, entry->d_name));
        }
        //Synchronize directories
        else if(S_ISDIR(st_buf.st_mode)) { //Directory
            sync_dirs(full_path, get_full_path(dest, entry->d_name));
        }

        free(full_path);
    }

    //Close directory stream
    if(closedir(dir)==-1) {
        handle_error("closedir");
    }
}

char* get_full_path(char* path, char* name) {
    char* full_path=(char*)malloc(sizeof(char)*(strlen(path)+strlen(name)+2));
    if(full_path==NULL) {
        handle_error("malloc");
    }
    sprintf(full_path, "%s/%s", path, name);
    return full_path;
}

void handle_error(char* msg) {
    printf("Error: %s [%s]\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}

void make_dir(char* path) {
    if(mkdir(path, S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH)==-1) {
        if(errno!=EEXIST) { //Ignore if directory already exists
            handle_error("mkdir");
        }
    }
}

int copy_file(char* src, char* dest) {
    FILE* src_file;
    FILE* dest_file;
    char buf[BUF_SIZE];
    size_t bytes_read, bytes_written;

    //Open source file for reading
    if((src_file=fopen(src, "rb"))==NULL) {
        handle_error("fopen");
    }

    //Open destination file for writing
    if((dest_file=fopen(dest, "wb"))==NULL) {
        handle_error("fopen");
    }

    //Copy data from source file to destination file
    while((bytes_read=fread(buf, 1, BUF_SIZE, src_file))>0) {
        bytes_written=fwrite(buf, 1, bytes_read, dest_file);
        if(bytes_written!=bytes_read) {
            handle_error("fwrite");
        }
    }

    //Close the files
    if(fclose(src_file)!=0 || fclose(dest_file)!=0) {
        handle_error("fclose");
    }

    return 0;
}

void sync_files(char* src, char* dest) {
    struct stat st_buf;
    struct tm* time_info;
    char src_time[TIME_SIZE], dest_time[TIME_SIZE];

    //Get metadata of source and destination files
    if(stat(src, &st_buf)==-1 || stat(dest, &st_buf)==-1) {
        handle_error("stat");
    }

    //Get modification time of source file
    time_info=localtime(&st_buf.st_mtime);
    strftime(src_time, TIME_SIZE, "%Y-%m-%d %H:%M:%S", time_info);

    //Get modification time of destination file (if it exists)
    if(stat(dest, &st_buf)==-1) {
        strcpy(dest_time, "NULL");
    }
    else {
        time_info=localtime(&st_buf.st_mtime);
        strftime(dest_time, TIME_SIZE, "%Y-%m-%d %H:%M:%S", time_info);
    }

    //Check which file is more recent
    if(strcmp(src_time, dest_time)>0) { //src file is newer
        printf("Copying %s to %s...\n", src, dest);
        copy_file(src, dest);
    }
    else if(strcmp(src_time, dest_time)<0) { //dest file is newer
        printf("Copying %s to %s...\n", dest, src);
        copy_file(dest, src);
    }
}

void sync_dirs(char* src, char* dest) {
    struct stat st_buf;

    //Check if destination directory exists, else create it
    make_dir(dest);

    //Get metadata of source and destination directories
    if(stat(src, &st_buf)==-1 || stat(dest, &st_buf)==-1) {
        handle_error("stat");
    }

    //Synchronize source and destination directories
    synchronize(src, dest);
}