//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <openssl/md5.h>

#define VIRUS_SIGNATURES 4
#define MAX_FILEPATH_LENGTH 256

const char *virus_signatures[VIRUS_SIGNATURES] = {
    "fd86be6fc1f6846d99bb784019b971f5",
    "942de0a7e0a65f4a9b7e02763d6a1783",
    "d41d8cd98f00b204e9800998ecf8427e",
    "26e8acb9c56c7dac7ba9966adf3ab8b9"
};

struct file_data {
    char filepath[MAX_FILEPATH_LENGTH];
    char md5_signature[MD5_DIGEST_LENGTH * 2 + 1];
};

void generate_md5_signature(const char *filepath, char *md5_signature)
{
    unsigned char c[MD5_DIGEST_LENGTH];
    int i;

    FILE *file = fopen(filepath, "rb");
    MD5_CTX mdContext;

    MD5_Init(&mdContext);
    const size_t buff_size = 1024;
    unsigned char buffer[buff_size];

    int bytes;

    while ((bytes = fread(buffer, 1, buff_size, file)) != 0) {
        MD5_Update(&mdContext, buffer, bytes);
    }

    MD5_Final(c, &mdContext);

    for (i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(md5_signature + 2 * i, "%02x", c[i]);
    }

    fclose(file);
}

int is_virus(const char *md5_signature)
{
    int i;
    for(i = 0; i < VIRUS_SIGNATURES; i++) {
        if (strcmp(md5_signature, virus_signatures[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int scan_file(const char *filepath, struct file_data *data)
{
    generate_md5_signature(filepath, data->md5_signature);
    memcpy(data->filepath, filepath, strlen(filepath) + 1);

    return is_virus(data->md5_signature);
}

int scan_directory(const char *path)
{
    DIR *dir = opendir(path);

    if (dir == NULL) {
        return 0;
    }

    struct dirent *direntry;

    int is_infected = 0;

    while ((direntry = readdir(dir)) != NULL) {
        if (strcmp(direntry->d_name, ".") == 0 || strcmp(direntry->d_name, "..") == 0) {
            continue;
        }

        char filepath[MAX_FILEPATH_LENGTH];
        snprintf(filepath, MAX_FILEPATH_LENGTH, "%s/%s", path, direntry->d_name);

        struct file_data data;
        int result = scan_file(filepath, &data);

        if (result == 1) {
            printf("Virus detected in file %s with MD5 signature %s\n", data.filepath, data.md5_signature);
            is_infected = 1;
        }

        if (direntry->d_type == DT_DIR) {
            int sub_infected = scan_directory(filepath);
            if (sub_infected == 1) {
                is_infected = 1;
            }
        }
    }

    closedir(dir);

    return is_infected;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    int result = scan_directory(argv[1]);

    if (result == 0) {
        printf("No viruses detected\n");
    }

    return 0;
}