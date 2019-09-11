#include <stdio.h>
#include <string.h>
int  main(){
	char str[255];
	while(1){
		printf(">>> ");
		fgets(str, sizeof(str), stdin);
		system(str);
	}
	return 0;
}