/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:57:49 by fgroo             #+#    #+#             */
/*   Updated: 2026/04/07 18:51:26 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>

class	Contact {
	public:
		void				setFirstName(const std::string &s);
		void				setLastName(const std::string &s);
		void				setNickname(const std::string &s);
		void				setPhoneNumber(const std::string &s);
		void				setDarkestSecret(const std::string &s);

		const std::string	&getFirstName(void) const;
		const std::string	&getLastName(void) const;
		const std::string	&getNickname(void) const;
		const std::string	&getPhoneNumber(void) const;
		const std::string	&getDarkestSecret(void) const;

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

class	PhoneBook {
	public:
		PhoneBook(void);
		void		MENU(void);

	private:
		Contact	contacts[8];
		int		count;

		void		ADD(void);
		void		SEARCH(void);
		void		stream_trunc(const std::string &s);
		std::string	get_input(const std::string &prompt);
};

#endif
