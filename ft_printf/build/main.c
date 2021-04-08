#include "../ft_printf.h"
#include <inttypes.h>

int main(void)
{
    int d;
    char *s = "%-020.13p";
    int *v = &d;
    //int v = 0x123;
    //char *v = "";

    putchar('|');
    d = ft_printf(s, v);
    putchar('|');
    if (d >= 0)
        printf("\n---%d---\n", d);
    else printf("ERR");

    putchar('|');
    d = printf(s, v);
    putchar('|');
    if (d >= 0)
        printf("\n---%d---\n", d);
    else printf("ERR");
    return 0;
}
