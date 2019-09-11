#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char s[255];
    while (1)
    {
        printf(">> ");
        fgets(s, sizeof(s), stdin);

        if (s[0] == 'e' && s[1] == 'x' && s[2] == 'i' && s[3] == 't')
        {
            break;
        }

        char command[255], curr_s[255];
        int command_lenght = 0, curr_s_lenght = 0, flag = 0;

        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] == ' ' || s[i] == '\n')
            {
                if (command_lenght != 0)
                {
                    if (flag > 0)
                        command[command_lenght] = ',';
                    else
                        command[command_lenght] = ' ';

                    command_lenght++;
                    flag++;
                }

                for (int j = 0; j < curr_s_lenght; j++)
                {
                    command[command_lenght] = curr_s[j];
                    command_lenght++;
                }

                curr_s_lenght = 0;
            }
            else
            {
                curr_s[curr_s_lenght] = s[i];
                curr_s_lenght++;
            }
        }

        int pid = fork();
        if (pid == 0)
        {
            system(command);
            break;
        }
    }
    return 0;
}