/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:28:50 by malmeida          #+#    #+#             */
/*   Updated: 2021/04/14 19:21:22 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_checker(t_flags *flags)
{
	if (flags->minus && flags->zero)
		flags->zero = 0;
	if (flags->zero && flags->precision >= 0)
		flags->zero = 0;
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
}

void	signed_int_conversion(va_list args, t_flags *flags)
{
	char	*nbr;
	int		len;

	flags_checker(flags);
	nbr = ft_itoa(va_arg(args, int));
	len = ft_strlen(nbr);
	if (flags->precision > len)
		nbr = apply_precision(nbr, len, flags);
	len = ft_strlen(nbr);
	while (flags->width > len && !(flags->minus) && !(flags->zero))
	{
		ft_putchar(' ');
		len++;
	}
	while (flags->width > len && flags->zero)
	{
		ft_putchar('0');
		len++;
	}
	if (!(flags->precision == 0 && nbr[0] == '0' && nbr[1] == '\0'))
		ft_putstr(nbr);
	while (flags->width > len++ && flags->minus)
		ft_putchar(' ');
	freebird((void *)&nbr);
}

void	unsigned_int_conversion(va_list args, t_flags *flags)
{
	char	*nbr;
	int		len;

	flags_checker(flags);
	nbr = ft_itoa(va_arg(args, unsigned int));
	len = ft_strlen(nbr);
	if (flags->precision > len)
		nbr = apply_precision(nbr, len, flags);
	len = ft_strlen(nbr);
	while (flags->width > len && !(flags->minus) && !(flags->zero))
	{
		ft_putchar(' ');
		len++;
	}
	while (flags->width > len && flags->zero)
	{
		ft_putchar('0');
		len++;
	}
	ft_putstr(nbr);
	while (flags->width > len && flags->minus)
	{
		ft_putchar(' ');
		len++;
	}
}

void	hex_low_conversion(va_list args, t_flags *flags)
{
	char	*nbr;
	int		len;

	flags_checker(flags);
	nbr = hex_itoa(va_arg(args, unsigned int), "01234556789abcdef");
	len = ft_strlen(nbr);
	if (flags->precision > len)
		nbr = apply_precision(nbr, len, flags);
	len = ft_strlen(nbr);
	while (flags->width > len && !(flags->minus) && !(flags->zero))
	{
		ft_putchar(' ');
		len++;
	}
	while (flags->width > len && flags->zero)
	{
		ft_putchar('0');
		len++;
	}
	ft_putstr(nbr);
	while (flags->width > len && flags->minus)
	{
		ft_putchar(' ');
		len++;
	}
}

void	hex_up_conversion(va_list args, t_flags *flags)
{
	char	*nbr;
	int		len;

	flags_checker(flags);
	nbr = hex_itoa(va_arg(args, unsigned int), "01234556789ABCDEF");
	len = ft_strlen(nbr);
	if (flags->precision > len)
		nbr = apply_precision(nbr, len, flags);
	len = ft_strlen(nbr);
	while (flags->width > len && !(flags->minus) && !(flags->zero))
	{
		ft_putchar(' ');
		len++;
	}
	while (flags->width > len && flags->zero)
	{
		ft_putchar('0');
		len++;
	}
	ft_putstr(nbr);
	while (flags->width > len && flags->minus)
	{
		ft_putchar(' ');
		len++;
	}
}
