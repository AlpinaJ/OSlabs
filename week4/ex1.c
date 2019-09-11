#include <stdio.h>

int main(){
    int n=10;
    int pid=fork();
    if(pid != 0)
		printf("hello from parent %d - %d\n", pid, n);
	else{
		printf("Hello from child %d - %d\n", pid,n);		
	}
    return 0;
}