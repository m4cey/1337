#include "../ft_printf.h"

int main(void)
{
    int d;
    char *s = "%8X";
    int v = 0x123;
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
    //printf("%X", 123);
    printf("%d", power(2, 4));
    return 0;
}
