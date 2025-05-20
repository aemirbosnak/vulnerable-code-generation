//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define OPTIMIZER_CONF "/etc/boot_optimizer.conf"

struct config {
    int enable_swap;
    int enable_hugepages;
    int enable_irqbalance;
    int enable_cpupower;
    int enable_iommu;
    int enable_numa;
    int enable_kvm;
    int enable_zfs;
    char *custom_options;
};

struct config read_config(const char *path) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    struct config config = {0};

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }

        char *key, *value;
        key = strtok(line, "=");
        value = strtok(NULL, "\n");

        if (strcmp(key, "enable_swap") == 0) {
            config.enable_swap = atoi(value);
        } else if (strcmp(key, "enable_hugepages") == 0) {
            config.enable_hugepages = atoi(value);
        } else if (strcmp(key, "enable_irqbalance") == 0) {
            config.enable_irqbalance = atoi(value);
        } else if (strcmp(key, "enable_cpupower") == 0) {
            config.enable_cpupower = atoi(value);
        } else if (strcmp(key, "enable_iommu") == 0) {
            config.enable_iommu = atoi(value);
        } else if (strcmp(key, "enable_numa") == 0) {
            config.enable_numa = atoi(value);
        } else if (strcmp(key, "enable_kvm") == 0) {
            config.enable_kvm = atoi(value);
        } else if (strcmp(key, "enable_zfs") == 0) {
            config.enable_zfs = atoi(value);
        } else if (strcmp(key, "custom_options") == 0) {
            config.custom_options = strdup(value);
        }
    }

    fclose(fp);

    return config;
}

void apply_config(const struct config *config) {
    // Enable/disable swap
    if (config->enable_swap) {
        system("swapon /swapfile");
    } else {
        system("swapoff /swapfile");
    }

    // Enable/disable hugepages
    if (config->enable_hugepages) {
        system("echo 1 > /sys/kernel/mm/transparent_hugepage/enabled");
    } else {
        system("echo 0 > /sys/kernel/mm/transparent_hugepage/enabled");
    }

    // Enable/disable irqbalance
    if (config->enable_irqbalance) {
        system("service irqbalance start");
    } else {
        system("service irqbalance stop");
    }

    // Enable/disable cpupower
    if (config->enable_cpupower) {
        system("service cpupower start");
    } else {
        system("service cpupower stop");
    }

    // Enable/disable iommu
    if (config->enable_iommu) {
        system("echo 1 > /sys/kernel/iommu/intel/isolate");
    } else {
        system("echo 0 > /sys/kernel/iommu/intel/isolate");
    }

    // Enable/disable numa
    if (config->enable_numa) {
        system("echo 1 > /sys/kernel/numa_balancing");
    } else {
        system("echo 0 > /sys/kernel/numa_balancing");
    }

    // Enable/disable kvm
    if (config->enable_kvm) {
        system("modprobe kvm");
    } else {
        system("rmmod kvm");
    }

    // Enable/disable zfs
    if (config->enable_zfs) {
        system("modprobe zfs");
    } else {
        system("rmmod zfs");
    }

    // Apply custom options
    if (config->custom_options != NULL) {
        system(config->custom_options);
    }
}

int main(int argc, char **argv) {
    struct config config = read_config(OPTIMIZER_CONF);

    apply_config(&config);

    return 0;
}