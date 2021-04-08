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

char*	tostr(int num){
    char* ret;
    int i;
    int	temp;

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


int	parse(format_t *fmt, const char **str, va_list ap){

    char *ptr;
    int is_var_width;

    is_var_width = 0;
    (*str)++;
    ptr = (char*) *str;
    while (!(strchr(TYPES, *ptr))){
        if ('1' <= *ptr && *ptr <= '9'){
            if (!(is_var_width))
                fmt->width = myatoi(&ptr);
        }
        else {
            if (*ptr == '.'){
                ptr++;
                if (*ptr == '*')
                    fmt->precision = va_arg(ap, int);
                else {
                    fmt->precision = myatoi(&ptr);
                    ptr--;
                }
            }
            else if (*ptr == '0')
                fmt->is_zero_flag = 1;
            else if (*ptr == '-')
                fmt->is_minus_flag = 1;
            else if (*ptr == '*') {
                is_var_width = 1;
                fmt->width = va_arg(ap, int);
            }
            ptr++;
        }
    }
    if (fmt->width < 0)
        fmt->is_minus_flag = 1;
    if (fmt->precision >= 0)
        fmt->is_zero_flag = 0;
    if (fmt->is_minus_flag)
        fmt->is_zero_flag = 0;
    fmt->specifier = *ptr;
    *str = ptr + 1;
    return (0);
}

// %[flags][width][precision][specifier]
// %[0 | -][width | *][precision | *][specifier]
