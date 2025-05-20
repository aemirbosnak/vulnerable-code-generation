//FormAI DATASET v1.0 Category: File Synchronizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//Global Variables
char *source_dir;
char *dest_dir;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//Struct for file info
typedef struct {
    char *name;
    char *source_path;
    char *dest_path;
    struct stat st;
} file_info;

//Create a file info
file_info *create_file_info(char *name, char *source_dir, char *dest_dir) {
    file_info *info = malloc(sizeof(file_info));
    info->name = strdup(name);
    char source_path[strlen(source_dir) + strlen(name) + 2];
    char dest_path[strlen(dest_dir) + strlen(name) + 2];
    sprintf(source_path, "%s/%s", source_dir, name);
    sprintf(dest_path, "%s/%s", dest_dir, name);
    info->source_path = strdup(source_path);
    info->dest_path = strdup(dest_path);

    //Get file status info
    if(stat(source_path, &info->st) == -1) {
        perror(source_path);
        free(info->name);
        free(info->source_path);
        free(info->dest_path);
        free(info);
        return NULL;
    }

    return info;
}

//Free a file info
void free_file_info(file_info *info) {
    free(info->name);
    free(info->source_path);
    free(info->dest_path);
    free(info);
}

//Copy a file from source to destination
void copy_file(char *source_path, char *dest_path) {
    int source_fd, dest_fd;
    char buf[BUFSIZ];
    ssize_t len;
    mode_t mode;
    off_t offset = 0;

    //Open source file
    source_fd = open(source_path, O_RDONLY);
    if(source_fd == -1) {
        perror(source_path);
        return;
    }

    //Get file mode
    struct stat st;
    if(stat(source_path, &st) == -1) {
        perror(source_path);
        close(source_fd);
        return;
    }
    mode = st.st_mode;

    //Create destination file
    dest_fd = creat(dest_path, mode);
    if(dest_fd == -1) {
        perror(dest_path);
        close(source_fd);
        return;
    }

    //Copy contents of source file to destination file
    while((len = pread(source_fd, buf, BUFSIZ, offset)) > 0) {
        ssize_t written = pwrite(dest_fd, buf, len, offset);
        if(written != len) {
            if(written == -1) {
                perror(dest_path);
            } else {
                fprintf(stderr, "%s: partial write (%ld/%ld)\n", dest_path, written, len);
            }
            close(source_fd);
            close(dest_fd);
            return;
        }
        offset += len;
    }

    //Close files
    close(source_fd);
    close(dest_fd);
}

//Copy a file if it does not exist or is outdated
void copy_if_needed(file_info *info) {
    pthread_mutex_lock(&mutex);

    //Check if file already exists in destination directory
    struct stat dest_st;
    if(stat(info->dest_path, &dest_st) == 0) {
        //Check if source file is newer than destination file
        if(info->st.st_mtim.tv_sec > dest_st.st_mtim.tv_sec) {
            copy_file(info->source_path, info->dest_path);
        }
    } else {
        copy_file(info->source_path, info->dest_path);
    }

    pthread_mutex_unlock(&mutex);
}

//Process a directory recursively
void process_directory(char *source_dir, char *dest_dir) {
    DIR *dirp;
    struct dirent *de;

    //Open source directory
    dirp = opendir(source_dir);
    if(dirp == NULL) {
        perror(source_dir);
        return;
    }

    //Process each file in directory
    while((de = readdir(dirp)) != NULL) {
        if(de->d_type == DT_REG) {
            //Create file info
            file_info *info = create_file_info(de->d_name, source_dir, dest_dir);
            if(info == NULL) {
                continue;
            }

            //Check if file needs to be copied
            copy_if_needed(info);

            //Free file info
            free_file_info(info);
        } else if(de->d_type == DT_DIR) {
            //Skip "." and ".." directories
            if(strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
                continue;
            }

            //Process subdirectory recursively
            char source_subdir[strlen(source_dir) + strlen(de->d_name) + 2];
            char dest_subdir[strlen(dest_dir) + strlen(de->d_name) + 2];
            sprintf(source_subdir, "%s/%s", source_dir, de->d_name);
            sprintf(dest_subdir, "%s/%s", dest_dir, de->d_name);
            process_directory(source_subdir, dest_subdir);
        }
    }

    //Close directory
    closedir(dirp);
}

//Thread function
void *process_directory_thread(void *arg) {
    char *source_dir = ((char **)arg)[0];
    char *dest_dir = ((char **)arg)[1];
    process_directory(source_dir, dest_dir);
    return NULL;
}

//Main function
int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Usage: %s source_dir dest_dir\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    source_dir = argv[1];
    dest_dir = argv[2];

    //Process directories in separate threads
    pthread_t thread1, thread2;
    char *args1[] = {source_dir, dest_dir};
    char *args2[] = {dest_dir, source_dir};
    pthread_create(&thread1, NULL, process_directory_thread, args1);
    pthread_create(&thread2, NULL, process_directory_thread, args2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}