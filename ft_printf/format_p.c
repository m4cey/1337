#include "ft_printf.h"

int format_p(format_t fmt, void *val) {

    if (val == NULL) {
        fmt.precision = -1;
        return (format_s(fmt, "(nil)"));
    }
    return (format_x(fmt, (unsigned long int)val, 'a', 1));
}
