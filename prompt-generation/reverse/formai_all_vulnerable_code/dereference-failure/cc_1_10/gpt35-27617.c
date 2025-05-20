//FormAI DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

//Function to check if a given string is numeric
int isNumeric(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if (!isdigit(s[i]))
            return 0;
    }
    return 1;
}

//Function to parse the contents of the /proc directory
void parseProcDirectory() {
    DIR* dirp;
    struct dirent* dp;
    char path[100], pid[10];

    //Open the /proc directory
    dirp = opendir("/proc");
    if (dirp == NULL) {
        printf("Error opening /proc directory\n");
        return;
    }

    //Loop through each directory within /proc
    while ((dp = readdir(dirp)) != NULL) {
        //Check if the directory is a numeric value (i.e represents a PID)
        if (isNumeric(dp->d_name)) {
            //Copy the PID into the pid[] array
            strcpy(pid, dp->d_name);
            //Create the full path to the cmdline file
            sprintf(path, "/proc/%s/cmdline", pid);
            //Open the cmdline file
            FILE* fp = fopen(path, "r");
            if (fp != NULL) {
                //Read contents of file into buffer
                char buf[1024];
                int len = fread(buf, sizeof(char), sizeof(buf), fp);
                //Check if there was anything read from the file
                if (len > 0) {
                    //Replace any null characters with spaces
                    for (int i = 0; i < len; i++) {
                        if (buf[i] == '\0')
                            buf[i] = ' ';
                    }
                    //Output PID and contents of cmdline file
                    printf("PID: %s  CMD: %s\n", pid, buf);
                }
                fclose(fp);
            }
        }
    }
    closedir(dirp);
}

int main() {
    //Clear the screen
    system("clear");
    //Loop indefinitely
    while (1) {
        //Clear the screen and display message
        system("clear");
        printf("=============================================================\n\n");
        printf("\t\tSYSTEM PROCESS VIEWER\n\n");
        printf("=============================================================\n\n");
        //Call function to parse the /proc directory
        parseProcDirectory();
        //Wait 2 seconds before running again
        sleep(2);
    }
    return 0;
}