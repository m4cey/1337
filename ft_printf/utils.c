#include "ft_printf.h"

void	print_format(format_t fmt){

    putchar('%');
    if (fmt.is_minus_flag)
        putchar('-');
    if (fmt.is_zero_flag)
        putchar('0');
    if (fmt.width)
        printf("%d", ABS(fmt.width));
    if (fmt.precision >= 0)
        printf(".%d", fmt.precision);
    putchar(fmt.specifier);
    putchar('\n');
    putchar('|');
}

int myatoi(char **str){
    int ret;

    ret = atoi(*str);
    while (**str == '-' || ('0' <= **str && **str <= '9'))
        (*str)++;
    return ret;
}

void putstr(const char *str) {

    if (!str)
        return;
    while (*str) {
        putchar(*str);
        str++;
    }
}

char*	ltoa(long int num){
    char* ret;
    int i;
    long int	temp;

    i = 0;
    num = ABS(num);
    temp = num;
    while (temp > 0){
        temp = temp / 10;
        i++;
    }
    i += num == 0;
    if (!(ret = malloc(i + 1)))
        return (NULL);
    ret[i] = 0;
    if (num == 0)
        ret[0] = '0' + num % 10;
    while (num > 0){
        ret[--i] = '0' + num % 10;
        num = num / 10;
    }
    return (ret);
}
