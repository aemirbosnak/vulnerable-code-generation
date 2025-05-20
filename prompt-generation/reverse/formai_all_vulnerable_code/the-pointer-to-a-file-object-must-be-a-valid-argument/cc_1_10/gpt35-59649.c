//FormAI DATASET v1.0 Category: System administration ; Style: detailed
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char command[100];
    if (argc != 2) {
        printf("Usage: %s [ip address]\n", argv[0]);
        return 1;
    }
    // ping the specified IP address
    sprintf(command, "ping -c 3 %s", argv[1]);
    printf("Executing command: %s\n", command);
    system(command);
  
    // check if the httpd process is running
    int running = 0;
    FILE *fp = popen("ps -A | grep httpd | wc -l", "r");
    char buf[64];
    fgets(buf, sizeof(buf), fp);
    if (atoi(buf) > 1) {
        running = 1;
    }
    pclose(fp);
  
    if (running) {
        printf("httpd process is running\n");
    } else {
        printf("httpd process is not running\n");
        // start the httpd process
        system("sudo systemctl start httpd");
    }
  
    // check if the sshd process is running
    running = 0;
    fp = popen("ps -A | grep sshd | wc -l", "r");
    fgets(buf, sizeof(buf), fp);
    if (atoi(buf) > 1) {
        running = 1;
    }
    pclose(fp);
  
    if (running) {
        printf("sshd process is running\n");
    } else {
        printf("sshd process is not running\n");
        // start the sshd process
        system("sudo systemctl start sshd");
    }
  
    // check if the iptables firewall is enabled
    running = 0;
    fp = popen("sudo systemctl status iptables | grep Active | tr -s ' ' | cut -d ' ' -f 3", "r");
    fgets(buf, sizeof(buf), fp);
    if (strstr(buf, "active")) {
        running = 1;
    }
    pclose(fp);
  
    if (running) {
        printf("iptables firewall is enabled\n");
    } else {
        printf("iptables firewall is not enabled\n");
        // enable the iptables firewall
        system("sudo systemctl enable iptables");
        printf("iptables firewall has been enabled\n");
    }
  
    return 0;
}