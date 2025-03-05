// 2021 June 2
// Creator: Tran Trung Tin
// Demo using system call fork to create a child process which execute command ls by execlp.
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int n;
    
    // Nhận giá trị n từ người dùng
    printf("Enter a number: ");
    scanf("%d", &n);
  
    /* Fork a child process */
    pid = fork();
  
    if (pid < 0) {
        /* Error occurred */
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        /* Child process: Calculate and print the Collatz sequence */
        
        printf("Child: Collatz sequence for %d is: ", n);
        while (n != 1) {
            printf("%d ", n);
            if (n % 2 == 0) {
                n /= 2; // If n is even, divide by 2
            } else {
                n = 3 * n + 1; // If n is odd, multiply by 3 and add 1
            }
        }
        printf("1\n"); // Final 1 of the sequence
    } else {
        /* Parent process: Just waits for the child process to finish */
        wait(NULL);
        printf("Parent: Child process finished\n");
    }
  
    return 0;
}
