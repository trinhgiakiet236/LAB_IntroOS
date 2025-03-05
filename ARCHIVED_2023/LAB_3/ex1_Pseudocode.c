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
    printf("Enter a number: ");
    scanf("%d", &n);

 
    pid = fork();
    
    if (pid < 0) {
  
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) {
         int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        printf("Child: The sum of numbers from 1 to %d is %d\n", n, sum);
        
    } else {
       
        
        printf("Parent: The divisors of %d are: ", n);
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                printf("%d ", i);
            }
        }
        printf("\n");

   
        wait(NULL);
    }
    
    return 0;
}
