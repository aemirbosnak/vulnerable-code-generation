//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/* function declarations */
void analyzeDir(char *path, int level, long *sizeArr, char **nameArr);

/* main function */
int main(int argc, char *argv[]) {
    char *path;
    int level = 0;
    long *sizeArr;
    char **nameArr;
    int i;
    
    /* get the directory path from the command line argument*/
    if (argc != 2)
    {
        printf("Please provide a directory path as argument.\n");
        return 0;
    }
    path = argv[1];
    
    /* allocate memory for the size and name arrays */
    sizeArr = (long *) malloc(sizeof(long));
    nameArr = (char **) malloc(sizeof(char *));
    
    /* call the analyzeDir function to analyze the given directory */
    analyzeDir(path, level, sizeArr, nameArr);
    
    /* print the results */
    for(i = 0; i < level-1; i++) {
        printf("|   ");
    }
    printf("|__ %s (%ld bytes)\n", nameArr[level-1], sizeArr[level-1]);
    
    /* free the memory */
    free(sizeArr);
    free(nameArr);
    
    return 0;
}

/* function to analyze the directory */
void analyzeDir(char *path, int level, long *sizeArr, char **nameArr) {
    DIR *dir;
    struct dirent *ent;
    struct stat st;
    char *newpath;
    int i;
    
    /* open the directory */
    if ((dir = opendir(path)) != NULL) {
        /* iterate through the contents of the directory */
        while ((ent = readdir(dir)) != NULL) {
            /* check if the content is a directory */
            if (ent->d_type == DT_DIR) {
                /* ignore . and .. directories */
                if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                    continue;
                }
                
                /* allocate memory for the new path */
                newpath = (char *) malloc((strlen(path) + strlen(ent->d_name) + 2) * sizeof(char));
                sprintf(newpath, "%s/%s", path, ent->d_name);
                
                /* get the size of the directory */
                sizeArr[level] = 0;
                nameArr[level] = ent->d_name;
                analyzeDir(newpath, level+1, sizeArr, nameArr);
                
                /* free the memory */
                free(newpath);
            }
            else {
                /* get the file size */
                newpath = (char *) malloc((strlen(path) + strlen(ent->d_name) + 2) * sizeof(char));
                sprintf(newpath, "%s/%s", path, ent->d_name);
                stat(newpath, &st);
                sizeArr[level] += st.st_size;
                free(newpath);
            }
        }
        closedir(dir);
    }
}