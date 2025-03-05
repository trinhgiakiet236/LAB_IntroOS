// 2021 June 2
// Creator: Tran Trung Tin
// Exercise
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int n;
    
    // Lấy giá trị n vào từ người dùng
    printf("Enter a number: ");
    scanf("%d", &n);

    /* Fork a child process */
    pid = fork();
    
    if (pid < 0) {
        /* Error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) {
        /* Child process: Calculate the sum S */
        
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        printf("Child: The sum of numbers from 1 to %d is %d\n", n, sum);
        
    } else {
        /* Parent process: Calculate the divisors of n */
        
        printf("Parent: The divisors of %d are: ", n);
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                printf("%d ", i);
            }
        }
        printf("\n");

        // Wait for the child process to finish
        wait(NULL);
    }
    
    return 0;
}
