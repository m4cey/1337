#include "../ft_printf.h"

int main(void)
{
    int d;
    char *s = "%u";
    unsigned int v = -1;
    //char *v = NULL;

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
