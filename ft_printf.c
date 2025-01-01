/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:39:00 by isel-kha          #+#    #+#             */
/*   Updated: 2024/12/28 20:39:05 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_str_char(char format, va_list args)
{
	int		count;
	char	*str;
	char	c;

	count = 0;
	if (format == 's')
	{
		str = va_arg(args, char *);
		count += ft_putstr(str);
	}
	else if (format == 'c')
	{
		c = va_arg(args, int);
		count += ft_putchar(c);
	}
	return (count);
}

static int	handle_ptr(va_list args)
{
	int		count;
	void	*ptr;	

	count = 0;
	ptr = va_arg(args, void *);
	count += ft_printptr(ptr);
	return (count);
}

static int	handle_numbers(char format, va_list args)
{
	int				count;
	int				nbr;
	unsigned int	u_nbr;

	count = 0;
	if (format == 'd' || format == 'i')
	{
		nbr = va_arg(args, int);
		count += ft_putnbr(nbr);
	}
	else if (format == 'u')
	{
		u_nbr = va_arg(args, unsigned int);
		count += ft_putunsigned(u_nbr);
	}
	else if (format == 'x' || format == 'X')
	{
		nbr = va_arg(args, int);
		count += ft_print_x(nbr, format);
	}
	return (count);
}

static int	handle_format(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 's' || *format == 'c')
		count += handle_str_char(*format, args);
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		count += handle_numbers(*format, args);
	else if (*format == '%')
		count += write(1, "%", 1);
	else if (*format == 'p')
		count += handle_ptr(args);
	else if (*format == 'x' || *format == 'X')
		count += handle_numbers(*format, args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
			{
				count += write(1, "%", 1);
				return (count);
			}
			format++;
			count += handle_format(format, args);
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
