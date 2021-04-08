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

    if (str == NULL || *str == NULL)
        return (0);
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

char*	ltoa(long int num) {
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
        ret[0] = '0';
    while (num > 0){
        ret[--i] = '0' + num % 10;
        num = num / 10;
    }
    return (ret);
}

unsigned int power(unsigned int base, unsigned int exponent) {
    unsigned int ret;

    ret = 1;
    while (0 < exponent) {
        ret *= base;
        exponent--;
    }
    return (ret);
}

char*	utoh(unsigned int num, int alpha_offset) {
    char* ret;
    unsigned int i;
    unsigned int j;
    unsigned int	temp;

    i = 0;
    j = 0;
    temp = num;
    while (temp > 0){
        temp = temp / 16;
        i++;
    }
    i += num == 0;
    if (!(ret = malloc(i + 1)))
        return (NULL);
    ret[i] = 0;
    while (j++ < i){
        temp = num / power(16 , i - j);
        if (temp < 10)
            ret[j - 1] = '0' + temp;
        else
            ret[j - 1] = alpha_offset + temp - 10;
        num = num % power(16, i - j);
    }
    return (ret);
}
