// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United       		          //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : fgroo <student@42.eu>            			      //
//                                                                            //
// ************************************************************************** //


#include "Account.hpp"

#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void) {

	static char	timestamp[18] = "";
	// static std::FILE	*fd = NULL;
	static bool	first = true;

	if (first)
	{
		std::time_t	now = std::time(NULL);
		std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", std::localtime(&now));
		// std::string logfile(timestamp + 1, 15);
		// logfile += ".log";
		// fd = fopen(logfile.c_str(), "w");
		first = false;
	}
	// if (fd)
	// 	fwrite(timestamp, 1, 17, fd);
	std::cout << timestamp << " ";
}

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

Account::Account(int initial_deposit) :  _accountIndex(Account::_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {

	if (initial_deposit < 0)
		initial_deposit = 0;
	_totalAmount += initial_deposit;
	++_nbAccounts;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::makeDeposit(int deposit) {
	if (deposit < 0)
		deposit = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits + 1 << "\n";
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (withdrawal < 0)
		withdrawal = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount)
		return (std::cout << "refused\n", false);
	else
		std::cout  << withdrawal << ";amount:" << (_amount -= withdrawal) << ";nb_withdrawals:" << ++_nbWithdrawals << "\n";
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}
int	Account::checkAmount(void) const {
	return (_amount);
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}