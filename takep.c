/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:00:16 by isel-kha          #+#    #+#             */
/*   Updated: 2024/12/28 22:41:24 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex(unsigned long num)
{
	char	*hex_chars;
	char	hex[16];
	int		i;
	int		count;

	hex_chars = "0123456789abcdef";
	i = 0;
	count = 0;
	while (num)
	{
		hex[i++] = hex_chars[num % 16];
		num = num / 16;
	}
	while (i-- > 0)
		count += ft_putchar(hex[i]);
	return (count);
}

int	ft_printptr(void *ptr)
{
	unsigned long	addr_number;
	int				count;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	count = 0;
	addr_number = (unsigned long)ptr;
	count += write(1, "0x", 2);
	count += ft_print_hex(addr_number);
	return (count);
}
