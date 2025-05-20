//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        exit(1);
    }

    char source_dir[MAX_PATH_LENGTH], dest_dir[MAX_PATH_LENGTH], file_name[MAX_PATH_LENGTH];
    struct stat source_file_stat, dest_file_stat;
    int fd_source, fd_dest;

    strcpy(source_dir, argv[1]);
    strcpy(dest_dir, argv[2]);

    if (stat(source_dir, &source_file_stat) == -1) {
        fprintf(stderr, "Source directory '%s' does not exist.\n", source_dir);
        exit(1);
    }

    if (stat(dest_dir, &dest_file_stat) == -1) {
        mkdir(dest_dir, 0755);
    }

    if (source_file_stat.st_mode & S_IFDIR) {
        DIR *source_dir_ptr = opendir(source_dir);

        if (source_dir_ptr!= NULL) {
            struct dirent *source_dir_entry = readdir(source_dir_ptr);

            while (source_dir_entry!= NULL) {
                strcpy(file_name, source_dir_entry->d_name);

                if (strcmp(file_name, ".")!= 0 && strcmp(file_name, "..")!= 0) {
                    if (stat(file_name, &source_file_stat) == -1) {
                        fprintf(stderr, "File '%s' not found in source directory '%s'.\n", file_name, source_dir);
                        exit(1);
                    }

                    strcpy(dest_dir, source_dir);
                    strcat(dest_dir, "/");
                    strcat(dest_dir, file_name);

                    if (stat(dest_dir, &dest_file_stat) == -1) {
                        if (stat(file_name, &source_file_stat) == -1) {
                            fprintf(stderr, "File '%s' not found in source directory '%s'.\n", file_name, source_dir);
                            exit(1);
                        }

                        if (source_file_stat.st_mode & S_IFDIR) {
                            strcpy(file_name, source_dir);
                            strcat(file_name, "/");
                            strcat(file_name, file_name);

                            fd_source = open(file_name, O_WRONLY | O_CREAT, 0644);

                            if (fd_source == -1) {
                                fprintf(stderr, "Failed to open file '%s' in source directory '%s'.\n", file_name, source_dir);
                                exit(1);
                            }

                            fd_dest = open(dest_dir, O_WRONLY | O_CREAT, 0644);

                            if (fd_dest == -1) {
                                fprintf(stderr, "Failed to open file '%s' in destination directory '%s'.\n", dest_dir, dest_dir);
                                exit(1);
                            }

                            if (source_file_stat.st_mode & S_IFDIR) {
                                if (link(file_name, dest_dir) == -1) {
                                    fprintf(stderr, "Failed to create hard link from '%s' to '%s'.\n", file_name, dest_dir);
                                    exit(1);
                                }
                            }

                            if (fstat(fd_source, &source_file_stat) == -1) {
                                fprintf(stderr, "Failed to stat file '%s' in source directory '%s'.\n", file_name, source_dir);
                                exit(1);
                            }

                            if (fstat(fd_dest, &dest_file_stat) == -1) {
                                fprintf(stderr, "Failed to stat file '%s' in destination directory '%s'.\n", dest_dir, dest_dir);
                                exit(1);
                            }

                            if (source_file_stat.st_mode & S_IFDIR) {
                                if (fstat(fd_source, &source_file_stat)!= -1) {
                                    if (fstat(fd_dest, &dest_file_stat)!= -1) {
                                        if (source_file_stat.st_ino == dest_file_stat.st_ino && source_file_stat.st_dev == dest_file_stat.st_dev) {
                                            close(fd_source);
                                            close(fd_dest);
                                        } else {
                                            fprintf(stderr, "Files '%s' and '%s' have different inode numbers.\n", file_name, dest_dir);
                                            exit(1);
                                        }
                                    }
                                } else {
                                    fprintf(stderr, "Failed to stat file '%s' in source directory '%s'.\n", file_name, source_dir);
                                    exit(1);
                                }
                            } else {
                                close(fd_source);
                                close(fd_dest);
                            }
                        }
                    } else {
                        strcpy(file_name, source_dir);
                        strcat(file_name, "/");
                        strcat(file_name, file_name);

                        if (stat(file_name, &source_file_stat) == -1) {
                            fprintf(stderr, "File '%s' not found in source directory '%s'.\n", file_name, source_dir);
                            exit(1);
                        }

                        strcpy(dest_dir, source_dir);
                        strcat(dest_dir, "/");
                        strcat(dest_dir, file_name);

                        if (stat(dest_dir, &dest_file_stat) == -1) {
                            if (source_file_stat.st_mode & S_IFDIR) {
                                if (mkdir(dest_dir, 0755) == -1) {
                                    fprintf(stderr, "Failed to create directory '%s' in destination directory '%s'.\n", dest_dir, dest_dir);
                                    exit(1);
                                }
                            } else {
                                fd_source = open(file_name, O_WRONLY | O_CREAT, 0644);

                                if (fd_source == -1) {
                                    fprintf(stderr, "Failed to open file '%s' in source directory '%s'.\n", file_name, source_dir);
                                    exit(1);
                                }

                                fd_dest = open(dest_dir, O_WRONLY | O_CREAT, 0644);

                                if (fd_dest == -1) {
                                    fprintf(stderr, "Failed to open file '%s' in destination directory '%s'.\n", dest_dir, dest_dir);
                                    exit(1);
                                }

                                if (source_file_stat.st_mode & S_IFDIR) {
                                    if (link(file_name, dest_dir) == -1) {
                                        fprintf(stderr, "Failed to create hard link from '%s' to '%s'.\n", file_name, dest_dir);
                                        exit(1);
                                    }
                                }

                                if (fstat(fd_source, &source_file_stat) == -1) {
                                    fprintf(stderr, "Failed to stat file '%s' in source directory '%s'.\n", file_name, source_dir);
                                    exit(1);
                                }

                                if (fstat(fd_dest, &dest_file_stat) == -1) {
                                    fprintf(stderr, "Failed to stat file '%s' in destination directory '%s'.\n", dest_dir, dest_dir);
                                    exit(1);
                                }

                                if (source_file_stat.st_mode & S_IFDIR) {
                                    if (fstat(fd_source, &source_file_stat)!= -1) {
                                        if (fstat(fd_dest, &dest_file_stat)!= -1) {
                                            if (source_file_stat.st_ino == dest_file_stat.st_ino && source_file_stat.st_dev == dest_file_stat.st_dev) {
                                                close(fd_source);
                                                close(fd_dest);
                                            } else {
                                                fprintf(stderr, "Files '%s' and '%s' have different inode numbers.\n", file_name, dest_dir);
                                                exit(1);
                                            }
                                        }
                                    } else {
                                        fprintf(stderr, "Failed to stat file '%s' in source directory '%s'.\n", file_name, source_dir);
                                        exit(1);
                                    }
                                } else {
                                    close(fd_source);
                                    close(fd_dest);
                                }
                            }
                        }
                    }

                    source_dir_entry = readdir(source_dir_ptr);
                }
            }

            closedir(source_dir_ptr);
        }
    }
}