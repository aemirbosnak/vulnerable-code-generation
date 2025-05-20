//FormAI DATASET v1.0 Category: Log analysis ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr,"Usage: %s <log_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* log_file = fopen(argv[1], "r");
    if (log_file == NULL)
    {
        fprintf(stderr, "Failed to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, log_file)) != -1)
    {
        char* suspicious_keywords[] = {"hack", "malware", "backdoor", "exploit", "rootkit"};
        int num_suspicious = sizeof(suspicious_keywords) / sizeof(char*);
        int contains_suspicious = 0;

        for (int i = 0; i < num_suspicious; i++)
        {
            if (strstr(line, suspicious_keywords[i]) != NULL)
            {
                contains_suspicious = 1;
                break;
            }
        }

        if (contains_suspicious)
        {
            // Log file contains suspicious activity!
            printf("ALERT: Log file %s contains suspicious activity!\n", argv[1]);
            printf("Suspicious line: %s", line);
            
            // Overwrite file with zeros to prevent data recovery
            long file_size;
            char* buffer;
            fseek(log_file, 0, SEEK_END);
            file_size = ftell(log_file);
            rewind(log_file);
            buffer = (char*) malloc(sizeof(char) * file_size);
            fread(buffer, 1, file_size, log_file);
            memset(buffer, 0, file_size);
            fseek(log_file, 0, SEEK_SET);
            fwrite(buffer, 1, file_size, log_file);
            free(buffer);

            // Send email to admin
            system("echo \"ALERT: Log file contains suspicious activity!\" | mail -s \"Security Alert!\" admin@example.com");
        }
    }

    fclose(log_file);
    if (line)
        free(line);

    return 0;
}