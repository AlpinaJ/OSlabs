#include <stdio.h>
#include <string.h>
int  main(){
	char s[255];
	while(1){
		printf(">> ");
		fgets(s, sizeof(s), stdin);

        if (s[0] == 'e' && s[1] == 'x' && s[2] == 'i' && s[3] == 't') {
            break;
        }
		system(s);
	}
	return 0;
}