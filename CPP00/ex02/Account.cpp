#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
}
Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	 _nbDeposits = 0;
	 _nbWithdrawals = 0;
	_nbAccounts++;
	 Account::_totalAmount += initial_deposit;
	 _displayTimestamp();
	 std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}
Account::~Account()
{
	_displayTimestamp();
	 std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}
int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount( void )
{
	return _totalAmount;
}
int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
void Account::displayAccountsInfos( void )
{

	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}
void Account::makeDeposit( int deposit)
{
	int p_amount = this->checkAmount();
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << p_amount
				<< ";deposit:" << deposit
				<< ";amount:" << this->checkAmount()
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = this->checkAmount();
	if (this->_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << p_amount
				  << ";withdrawal:refused"
				  << std::endl;
		return false;
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << p_amount
				  << ";withdrawal:" << withdrawal
				  << ";amount:" << this->checkAmount()
				  << ";nb_withdrawals:" << this->_nbWithdrawals
				  << std::endl;
		return true;
	}
}

int Account::checkAmount( void ) const
{
	return _amount;
}
void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->checkAmount()
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t now = time(NULL);
	struct tm *Time = localtime(&now);
	char buffer[20];

	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", Time);
	std::cout << "[" << buffer << "] ";
}