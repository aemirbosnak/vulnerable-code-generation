//FormAI DATASET v1.0 Category: System process viewer ; Style: systematic
#include <stdio.h> 
#include <stdlib.h> 
#include <dirent.h> 
#include <string.h> 

int main(void) 
{ 
    DIR *dir; //DIR structure from dirent.h
    struct dirent *dptr; //dirent structure
    char *pid = NULL; 
    char path[50], buf[1024]; //path and buffer
    FILE *fp; //file pointer
    
    dir = opendir("/proc/"); //opens /proc/ directory
    
    if (dir == NULL) 
    { 
        printf("\nError opening directory!"); 
        exit(1); 
    } 
    
    printf("\nPID\tPROCESS"); //column headers
    
    while ((dptr = readdir(dir)) != NULL) 
    { 
        if (strcmp(dptr->d_name, ".") && strcmp(dptr->d_name, "..")) //checks if directory is not "." or ".."
        { 
            pid = dptr->d_name; 
            
            //creates path for cmdline file
            sprintf(path, "/proc/%s/cmdline", pid); 
            
            fp = fopen(path, "r"); //opens cmdline file 
            
            //reads content of cmdline file
            if (fp != NULL) 
            { 
                fgets(buf, 1024, fp); 
                
                //prints process id and process name
                printf("\n%s\t%s", pid, buf); 
                
                fclose(fp); //closes file pointer
            } 
        } 
    } 

    closedir(dir); //closes directory
    
    return 0; 
}