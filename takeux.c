/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:00:16 by isel-kha          #+#    #+#             */
/*   Updated: 2024/12/28 22:41:24 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_hexi_ux(unsigned int num)
{
	char	*hex_chars;
	char	hex[16];
	int		i;
	int		count;

	hex_chars = "0123456789ABCDEF";
	i = 0;
	count = 0;
	if (num == 0)
		return (ft_putchar('0'));
	while (num)
	{
		hex[i++] = hex_chars[num % 16];
		num = num / 16;
	}
	while (i-- > 0)
		count += ft_putchar(hex[i]);
	return (count);
}