//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int virus_detected = 0;
    DIR *d;
    struct dirent *dir;

    // Open current directory
    d = opendir(".");

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            char *file_name = dir->d_name;

            // Check if file extension is .exe
            char *file_extension = strrchr(file_name, '.');
            if (file_extension && strcmp(file_extension, ".exe") == 0)
            {
                // Open file in read mode
                FILE *file = fopen(file_name, "rb");

                if (file)
                {
                    // Read first 2 bytes of file
                    char buffer[2];
                    fread(buffer, sizeof(char), 2, file);

                    // Check if first 2 bytes are MZ (magic number for EXE files)
                    if (buffer[0] == 'M' && buffer[1] == 'Z')
                    {
                        printf("Virus detected in file: %s\n", file_name);
                        virus_detected = 1;
                    }

                    fclose(file);
                }
            }
        }

        closedir(d);

        if (!virus_detected)
        {
            printf("Congratulations! Your system is virus-free.\n");
        }
    }

    return 0;
}