/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declaration.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:55:39 by ccepre            #+#    #+#             */
/*   Updated: 2018/12/05 11:35:27 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_attributs g_attr_tab[] =
{
	{'#', &ft_hashtag},
	{'0', &ft_zero},
	{'-', &ft_minus},
	{'+', &ft_plus},
	{' ', &ft_space},
};
