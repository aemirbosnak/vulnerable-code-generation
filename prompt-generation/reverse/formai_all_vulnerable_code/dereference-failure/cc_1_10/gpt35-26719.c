//FormAI DATASET v1.0 Category: System boot optimizer ; Style: introspective
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

    printf("Welcome to the System Boot Optimizer!\n\n");
    
    // Get the current user running the program
    char *user = getenv("USER");

    // Check if user is root
    if (geteuid() != 0) {
        printf("Please run the program as root.\n");
        exit(1);
    }

    // Check if the user provided a kernel version
    if (argc < 2) {
        printf("Please provide a kernel version.\n");
        exit(1);
    }
    
    char *kernel = argv[1];
    
    // Check if the kernel version is valid
    if (strlen(kernel) != 3 || kernel[0] != '5') {
        printf("Invalid kernel version. Please provide a version of the form '5.x.x'.\n");
        exit(1);
    }
    
    printf("Optimizing system boot for kernel version %s...\n", kernel);
    
    // Remove unneeded services from systemctl
    printf("Removing unneeded systemd services...\n");
    system("systemctl disable network-manager.service");
    system("systemctl disable bluetooth.service");
    system("systemctl disable cups.service");
    system("systemctl disable cups-browsed.service");
    system("systemctl disable remote-fs.target");
    system("systemctl disable gdm.service");

    // Remove unneeded kernel modules from initramfs
    printf("Removing unneeded kernel modules from initramfs...\n");
    system("mv /etc/initramfs-tools/modules /etc/initramfs-tools/modules.backup");
    FILE *modules_file = fopen("/etc/initramfs-tools/modules", "w");
    fprintf(modules_file, "# nghttp2 causes boot delay\n");
    fprintf(modules_file, "# igb causes Intel driver to load before i40e\n");
    fprintf(modules_file, "# md4/md5/sha1 cause boot delay\n");
    fprintf(modules_file, "# crc32c_intel causes boot delay\n");
    fprintf(modules_file, "bpf\n");
    fprintf(modules_file, "i40e\n");
    fprintf(modules_file, "ixgbe\n");
    fclose(modules_file);

    // Recreate initramfs
    printf("Recreating initramfs...\n");
    system("update-initramfs -u");

    printf("System boot optimized for kernel version %s! Enjoy a faster boot time.\n", kernel);

    return 0;
}