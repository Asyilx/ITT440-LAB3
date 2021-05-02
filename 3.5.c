#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int main(void){
void sigint_handler(int sig);
char s[200];

if (signal(SIGINT,sigint_handler)==SIG_ERR){

        perror("signal");
        exit(1);
}

        int n,c;
	printf("Enter a Number to check if it's prime :\n");
	scanf("%d",&n);
	
	for (c=2;c<=n/2; c++){
		if(n%c == 0){
			printf("%d is a composite number.\n",n);
			break;
		}
	}
	if(c==n/2+1){
		printf("%d is Prime Number.\n",n);
		
		return EXIT_SUCCESS;
	}
	if(fgets(s,200,stdin)==NULL){
         perror("gets");
	 return 0;
}

return 0;
}

void sigint_handler(int sig){

printf("This is a special signal handler for process immedietly terminate.\n");
}
