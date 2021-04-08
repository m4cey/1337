#include "ft_printf.h"

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
