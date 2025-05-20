//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include<stdio.h>

int main() {
    // Prompt user to input their expected internet speed
    printf("Enter your expected internet speed in Mbps: ");
    float expected_speed;
    scanf("%f", &expected_speed);
    
    // Generate a random internet speed within a certain range to simulate fluctuations
    float min_speed = expected_speed * 0.8;
    float max_speed = expected_speed * 1.2;
    float actual_speed = (rand() % (int)(max_speed - min_speed + 1)) + min_speed;
    
    // Determine if the actual speed is within an acceptable range
    if (actual_speed >= expected_speed * 0.9 && actual_speed <= expected_speed * 1.1) {
        printf("Your internet speed of %.1f Mbps is within the expected range.", actual_speed);
    } else {
        printf("Your internet speed of %.1f Mbps is outside the expected range.", actual_speed);
        
        // Immediately begin running tests to ensure security
        printf("\nInitiating security measures...");
        int num_tests_failed = 0;
        
        // Test the ping to the router to ensure it's running securely
        printf("\nTesting ping to router...");
        int router_ping = (rand() % 10) + 1;
        if (router_ping > 2) {
            printf("Secure.");
        } else {
            printf("Insecure!");
            num_tests_failed++;
        }
        
        // Test the speed to an external server to ensure no malware is slowing down the connection
        printf("\nTesting speed to external server...");
        float ext_speed = (rand() % (int)(expected_speed - 0.5)) + 0.5;
        if (ext_speed >= actual_speed) {
            printf("Secure.");
        } else {
            printf("Insecure!");
            num_tests_failed++;
        }
        
        // Test for any suspicious traffic on the network
        printf("\nScanning for suspicious traffic...");
        int num_suspicious = (rand() % 4) + 1;
        if (num_suspicious == 0) {
            printf("No suspicious traffic detected.");
        } else {
            printf("%d instances of suspicious traffic detected!", num_suspicious);
            num_tests_failed++;
        }
        
        // If enough tests fail, take drastic action
        if (num_tests_failed >= 2) {
            printf("\nYour internet connection has been compromised. Disconnect immediately!");
            exit(1);
        } else {
            printf("\nAll tests passed! Your internet connection is secure.");
        }
    }
    
    return 0;
}