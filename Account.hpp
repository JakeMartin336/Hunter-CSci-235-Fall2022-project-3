// Jacob Martin
// 10/11/2022
// Account.hpp
// Project 3 - Now that accounts are part of a Network, you must also adapt the Account class so that accounts can follow one another.

#ifndef _ACCOUNT_ //defining account
#define _ACCOUNT_

#include "Network.hpp" //include needed headers and libraries
#include "Post.hpp"
#include <vector>
#include <string>
#include <iostream>

class Account
{
public:
	Account();
	Account(std::string name, std::string word);
	void setUsername(const std::string& name);
	std::string getUsername() const;
	void setPassword(const std::string& word);
	std::string getPassword() const;
	bool addPost(const std::string& name, const std::string& word); //updated
	void viewPosts() const;

	Network<Account> *getNetwork() const;
	void setNetwork(Network<Account> *entry);
	
	bool followAccount(const std::string& name);
	std::vector<std::string> viewFollowing() const;
private:
	std::string username;
	std::string password;
	std::vector<Post> all_posts;

	std::vector<std::string> following;
	Network<Account>* network_apartof;
};

#endif