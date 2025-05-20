//FormAI DATASET v1.0 Category: Browser Plugin ; Style: portable
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#elif __linux
#include <dirent.h>
#endif

#ifdef __APPLE__
#include <Cocoa/Cocoa.h>
#endif

// Define the function to check if the browser has any active tabs.
int checkActiveTabs() {
    // Check if the operating system is Windows.
    #ifdef _WIN32
    HWND hwnd = GetForegroundWindow();
    TCHAR title[256];
    // Get the title of the active window.
    GetWindowText(hwnd, title, sizeof(title));
    if (strstr(title, "Google Chrome") != NULL) {
        // Perform a specific task for Google Chrome on Windows.
        printf("Active window is Google Chrome on Windows.\n");
        return 1;
    }
    // Check if the operating system is Linux.
    #elif __linux
    DIR *dir;
    struct dirent *dirEntry;
    // Open the directory that contains information about the active windows.
    dir = opendir("/proc");
    // Loop through all the files in the directory.
    while ((dirEntry = readdir(dir)) != NULL) {
        // Ignore non-numeric entries.
        if (isdigit(*dirEntry->d_name)) {
            char filePath[256];
            FILE *file;
            sprintf(filePath, "/proc/%s/cmdline", dirEntry->d_name);
            // Open the file that contains the command line arguments of the process.
            file = fopen(filePath, "r");
            if (file) {
                char buffer[1024];
                // Read the command line arguments of the process.
                int len = fread(buffer, 1, sizeof(buffer), file);
                fclose(file);
                buffer[len] = '\0';
                // Check if the process is a Google Chrome browser with active tabs.
                if (strstr(buffer, "google-chrome") != NULL && strstr(buffer, "--type=renderer") != NULL) {
                    printf("Active window is Google Chrome on Linux.\n");
                    return 1;
                }
            }
        }
    }
    closedir(dir);
    // Check if the operating system is macOS.
    #elif __APPLE__
    NSWorkspace *workspace = [NSWorkspace sharedWorkspace];
    NSArray *runningApps = [workspace runningApplications];
    for (NSRunningApplication *app in runningApps) {
        if (![app isHidden] && [[app localizedName] isEqual:@"Google Chrome"]) {
            printf("Active window is Google Chrome on macOS.\n");
            return 1;
        }
    }
    #endif
    // If the active window is not a Google Chrome browser with active tabs, return 0.
    printf("Active window is not Google Chrome with active tabs.\n");
    return 0;
}

int main() {
    // Call the function to check if the browser has any active tabs.
    int result = checkActiveTabs();
    printf("Function returned: %d\n", result);
    return 0;
}