//FormAI DATASET v1.0 Category: System boot optimizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int start_time = time(NULL); // record start time

    // Prints title and information about program
    printf("C System Boot Optimizer v1.0\n");
    printf("This program will optimize your system boot process by rearranging files.\n");

    // Define system directories
    char *system_dirs[5] = {"system32", "drivers", "temp", "Program Files", "Documents"};
    int num_system_dirs = sizeof(system_dirs)/sizeof(system_dirs[0]);

    // Define file extensions
    char *file_exts[4] = {".exe", ".dll", ".sys", ".ini"};
    int num_file_exts = sizeof(file_exts)/sizeof(file_exts[0]);

    // Generate random seed for shuffling directories and extensions
    srand(time(NULL));

    // Create temporary directory to hold optimized files
    system("mkdir optimized_files");

    // Loop through each system directory
    for(int i = 0; i < num_system_dirs; i++) {
        // Save the original directory path
        char original_dir[100] = "";
        sprintf(original_dir, "mkdir %s_backup", system_dirs[i]);
        system(original_dir);

        // Move all files in directory into temporary directory
        char temp_dir[100] = "";
        sprintf(temp_dir, "mv /%s/* optimized_files", system_dirs[i]);
        system(temp_dir);

        // Loop through each file extension
        for(int j = 0; j < num_file_exts; j++) {
            // Find all files with current extension in temporary directory
            char find_command[100] = "";
            sprintf(find_command, "find optimized_files -name '*%s'", file_exts[j]);

            // Create list of files
            FILE *find_pipe = popen(find_command, "r");
            char file_list[1000] = "";
            while(fgets(file_list, sizeof(file_list), find_pipe)) {
                // Remove newline character from file name
                char *pos;
                if ((pos=strchr(file_list, '\n')) != NULL) {
                    *pos = '\0';
                }

                // Generate random number to append to new file name
                int rand_num = rand() % 1000;

                // Construct new file path
                char new_file_path[100] = "";
                sprintf(new_file_path, "/%s/%s_%d%s", system_dirs[i], system_dirs[i], rand_num, file_exts[j]);

                // Move file into correct directory with new name
                char move_command[100] = "";
                sprintf(move_command, "mv %s %s", file_list, new_file_path);
                system(move_command);
            }
            pclose(find_pipe);
        }
    }

    // Print completion message
    printf("Optimization complete!\n");

    // Calculate and print total execution time
    int end_time = time(NULL);
    int total_time = end_time - start_time;
    printf("Execution time: %d seconds\n", total_time);

    return 0;
}