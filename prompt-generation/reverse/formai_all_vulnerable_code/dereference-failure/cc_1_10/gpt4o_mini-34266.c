//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define MAX_FILENAME_LEN 256

void displayMessage(const char *message) {
    printf("🕵️‍♂️ File Syncer: %s\n", message);
}

int copyFile(const char *sourceFile, const char *destFile) {
    FILE *src = fopen(sourceFile, "rb");
    if (!src) {
        displayMessage("Oops! Can't find the source file! 😢");
        return -1;
    }

    FILE *dst = fopen(destFile, "wb");
    if (!dst) {
        fclose(src);
        displayMessage("Oops! Can't create the destination file! 😬");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    
    displayMessage("💾 Copying... The great file transfer begins!");
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dst);
    }

    fclose(src);
    fclose(dst);
    
    displayMessage("✅ File transfer complete! 🎉");
    return 0;
}

int syncDirectories(const char *srcDir, const char *destDir) {
    DIR *source = opendir(srcDir);
    if (!source) {
        displayMessage("Yikes! Can't open the source directory! 🚪");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(source)) != NULL) {
        if (entry->d_name[0] == '.') {
            // Ignore hidden files and directories (., ..)
            continue;
        }

        char sourcePath[MAX_FILENAME_LEN];
        char destPath[MAX_FILENAME_LEN];

        snprintf(sourcePath, sizeof(sourcePath), "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        struct stat fileInfo;
        if (stat(sourcePath, &fileInfo) == -1) {
            displayMessage("Oops! Couldn't retrieve file info. 🤔");
            continue;
        }

        if (S_ISREG(fileInfo.st_mode)) {
            // It's a regular file, time to copy it
            displayMessage("📝 Found a regular file, time to copy!");
            if (copyFile(sourcePath, destPath) == -1) {
                displayMessage("🙈 Something went wrong with the copying process!");
            }
        } else {
            displayMessage("🧳 Found a surprise! It's a directory! But we don't sync directories. Sorry, little buddy!");
        }
    }

    closedir(source);
    displayMessage("🎈 All files checked! Time to put on party hats! 🎉");
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        displayMessage("🎭 Usage: ./file_syncer <source_directory> <destination_directory>");
        return 1;
    }

    const char *sourceDir = argv[1];
    const char *destDir = argv[2];

    displayMessage("🚀 Starting the grand file synchronization adventure!");

    if (syncDirectories(sourceDir, destDir) == -1) {
        displayMessage("❌ File synchronization failed, please check the above messages!");
        return 1;
    }

    displayMessage("🍾 Synchronization completed successfully! Cheers! 🥳");
    return 0;
}