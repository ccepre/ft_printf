/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:33:51 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/13 14:42:27 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_format.h"

int	get_attributs(t_stack *new, const char *restrict format, int *i)
{
	char	*attributs;
	char	*tmp;

	if (!(new->attributs))
		new->attributs = ft_strsub(&format[*i], 0, 1);
	else if (!(ft_strchr(new->attributs, format[*i])))
	{
		attributs = ft_strsub(&format[*i], 0, 1);
		tmp = new->attributs;
		if (!(new->attributs = ft_strjoin(new->attributs, attributs)))
			return (-1);
		ft_strdel(&attributs);
		ft_strdel(&tmp);
	}
	return (0);
}

int	get_modifier(t_stack *new, const char *restrict format, int *i)
{
	if (new->modifier)
		ft_strdel(&new->modifier);
	if (format[*i + 1] == format[*i] && format[*i] != 'L')
	{
		if (!(new->modifier = ft_strsub(format, *i, 2)))
			return (-1);
		(*i)++;
	}
	else
	{
		if (!(new->modifier = ft_strsub(&format[*i], 0, 1)))
			return (-1);
	}
	return (0);
}

int	get_precision(t_stack *new, const char *restrict format, int *i)
{
	(*i)++;
	new->precision = ft_atoi(&format[*i]);
	while (format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
	(*i)--;
	return (0);
}

int	get_width(t_stack *new, const char *restrict format, int *i)
{
	new->width = ft_atoi(&format[*i]);
	while (format[*i] >= '0' && format[*i] <= '9')
		(*i)++;
	(*i)--;
	return (0);
}

int	ft_format_parser(const char *restrict format, t_stack *new)
{
	int		i;
	int		j;

	i = 0;
	while (ft_strchr("#+-0 .0123456789hlL", format[++i]) && format[i] != 0)
	{
		j = -1;
		while (++j < 4)
			if (ft_strchr(g_format_tab[j].format, format[i]))
			{
				if (g_format_tab[j].f(new, format, &i) == -1)
					return (-1);
				break ;
			}
	}
	if (format[i])
	{
		new->format = format[i];
		i++;
	}
	return (i);
}
