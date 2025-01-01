/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takeu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:08:12 by isel-kha          #+#    #+#             */
/*   Updated: 2024/12/28 20:08:14 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n >= 10)
		count += ft_putunsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
