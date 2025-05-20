//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Function to scan the file for viruses
int scan_file(char *filename){
    FILE *fp = fopen(filename, "r");
    int virus_count = 0;
    char virus[15][10] = {"trojan", "worm", "keylogger", "ransomware", "spyware", "adware", "rootkit", "backdoor", "malware", "virus", "botnet", "ad injector", "browser hijacker", "fake antivirus", "fileless malware"};

    if(fp != NULL) {
        char word[100];
        while(fscanf(fp, "%s", word) != EOF) {
            for(int i = 0; i < 15; i++){
                if(strstr(word, virus[i]) != NULL){
                    printf("Virus Detected: %s\n", virus[i]);
                    virus_count++;
                }
            }
        }
        fclose(fp);
    }
    return virus_count;
}

// Function to scan the directory for files to scan
void scan_directory(char *dirpath) {
    struct dirent *dir;
    DIR *d;
    d = opendir(dirpath);
    if(d) {
        while ((dir = readdir(d)) != NULL) {
            char filename[100];
            if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..")==0){
                continue;
            }
            sprintf(filename, "%s/%s", dirpath, dir->d_name);
            if(dir->d_type == DT_DIR) {
                scan_directory(filename);    // call this function recursively to scan subdirectories
            } else {
                int virus_count = scan_file(filename);
                if(virus_count == 0){
                    printf("%s: No viruses found!\n", filename);
                }
            }
        }
        closedir(d);
    }
}

int main() {
    char dirpath[100];
    printf("Please enter directory path to scan for viruses: ");
    scanf("%s", dirpath);
    scan_directory(dirpath);
    printf("Scan complete!\n");
    return 0;
}