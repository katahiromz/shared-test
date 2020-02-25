#include <cstdio>
#include <cstring>

#ifdef _MSC_VER
    #pragma comment(linker, "/SECTION:.shared,RWS")
    #pragma data_seg(".shared")
    static int s_counter = 0;
    #pragma data_seg()
#else
    static int s_counter __attribute__((section(".shared"), shared)) = 0;
#endif

int main(void)
{
    printf("s_counter: %d\n", s_counter);
    s_counter++;

    char buf[256];
    for (;;)
    {
        printf("Type quit: ");
        fflush(stdout);
        fgets(buf, 256, stdin);

        if (strstr(buf, "quit") != NULL)
            break;
    }

    s_counter--;
    return 0;
}
