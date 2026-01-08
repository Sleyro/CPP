#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
	private:

		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
		bool 		full;
		
	public:

		Contact();

		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetNickName() const;
		std::string GetPhoneNumber() const;
		std::string GetDarkestSecret() const;

		void	SetContact(const std::string& first,
							const std::string& last,
							const std::string& nick,
							const std::string& phone,
							const std::string& secret);

		bool	IsFull() const;
};

#endif