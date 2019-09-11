/* Explanation:
    When i=0, there are became 2 processers(2^1)
    When i=1, each process make 1 more, so there are 2 new processers are made(2^2 amount of all processers)
    When i=n, amount of all processers is 2^n, in my case is 32
*/

int main()
{
    for (int i = 0; i < 4; i++)
    {
        fork();
        sleep(5);
    }
    return 0;
}