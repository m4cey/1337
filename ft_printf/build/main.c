#include "../ft_printf.h"

int main(void)
{
    int d;
    char *s = "%05.3d";
    int v = 22;
    //char *v = "lmao";

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
    printf("%i|", -123);
    return 0;
}
