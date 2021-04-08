#include "../ft_printf.h"
#include <limits.h>

int main(void)
{
    int d;
    char *s = "%d";
    //int *v = &d;
    int v = 0;
    //char *v = "lmaoo";

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
