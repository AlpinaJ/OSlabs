#include <stdio.h>
#include <string.h>
int main()
{

    printf("Give me a string\n");
    char s[1000],r[1000];
    scanf ("%s",s);

    int rlen=strlen(s)-1;
    for(int i=0;i<strlen(s);i++){
        r[rlen]=s[i];
        rlen--;
    }

    printf("%s",r);
    return 0;
}