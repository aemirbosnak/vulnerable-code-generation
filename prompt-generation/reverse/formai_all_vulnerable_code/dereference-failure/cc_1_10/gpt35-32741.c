//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <openssl/md5.h>

#define BLOCKSIZE 1024

void hashFile(char *filename, char *md5str) {
    FILE *fp = fopen(filename, "rb");
    int bytes;
    unsigned char data[BLOCKSIZE];
    unsigned char hash[MD5_DIGEST_LENGTH];
    MD5_CTX mdContext;
    MD5_Init(&mdContext);
    while ((bytes = fread(data, 1, BLOCKSIZE, fp)) != 0) {
        MD5_Update(&mdContext, data, bytes);
    }
    fclose(fp);
    MD5_Final(hash, &mdContext);
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&md5str[i*2], "%02x", (unsigned int)hash[i]);
    }
}

int checkFile(char *filename) {
    char md5str[33];
    hashFile(filename, md5str);
    if (strcmp(md5str, "e8c83e232b64ce94fdd0e2447ef9c357") == 0) {
        printf("Virus detected in file: %s\n", filename);
        return 1;
    }
    return 0;
}

void scanDirectory(char *dir) {
    struct dirent *entry;
    DIR *dp;
    dp = opendir(dir);
    if (dp == NULL) {
        perror("opendir");
        return;
    }
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            char subdir[256];
            sprintf(subdir, "%s/%s", dir, entry->d_name);
            scanDirectory(subdir);
        } else {
            char filename[256];
            sprintf(filename, "%s/%s", dir, entry->d_name);
            checkFile(filename);
        }
    }
    closedir(dp);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }
    scanDirectory(argv[1]);
    printf("Scan complete\n");
    return 0;
}