/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:57:49 by fgroo             #+#    #+#             */
/*   Updated: 2026/04/16 22:33:24 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void				Contact::setFirstName(const std::string &s) { _first_name = s; }
void				Contact::setLastName(const std::string &s) { _last_name = s; }
void				Contact::setNickname(const std::string &s) { _nickname = s; }
void				Contact::setPhoneNumber(const std::string &s) { _phone_number = s; }
void				Contact::setDarkestSecret(const std::string &s) { _darkest_secret = s; }

const std::string	&Contact::getFirstName(void) const { return _first_name; }
const std::string	&Contact::getLastName(void) const { return _last_name; }
const std::string	&Contact::getNickname(void) const { return _nickname; }
const std::string	&Contact::getPhoneNumber(void) const { return _phone_number; }
const std::string	&Contact::getDarkestSecret(void) const { return _darkest_secret; }
