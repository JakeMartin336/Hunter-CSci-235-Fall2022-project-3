/// Jacob Martin
// 10/11/2022
// Account.cpp
// Project 3 - Now that accounts are part of a Network, you must also adapt the Account class so that accounts can follow one another.

#include "Account.hpp" //include needed headers and libraries

Account::Account() //constructor
{
	username = "";
	password = "";
	network_apartof = nullptr; //setting network apart of to null until network is assigned
}

Account::Account(std::string name, std::string word) //param constructor
{
	username = name; //setting account username to value passed
	password = word; //setting account password to value passed
	network_apartof = nullptr; //setting network apart of to null until network is assigned
}

void Account::setUsername(const std::string& name) //setting username to value passed
{
	username = name;
}

std::string Account::getUsername() const //returning account username
{
	return username;
}

void Account::setPassword(const std::string& word) //setting password to value passed
{
	password = word;
}

std::string Account::getPassword() const //returning password
{
	return password;
}

bool Account::addPost(const std::string& name, const std::string& word) //adding post to account post vector
{
	Post temp(name, word, getUsername()); //creates new post object
	if (name != "" || word != "") //if proper format for post
	{
		all_posts.push_back(temp); //then add post to vector of posts
		if(network_apartof != nullptr) //checks if its apart of a network
			network_apartof -> addToFeed(temp); // if it is not, then set the network to the current network
		return true;
	}
	else
		return false;
}

void Account::viewPosts() const//view all posts from account
{
	for(int i = 0; i < all_posts.size(); i++) //cycle through vector of posts from the account
	{
		all_posts[i].displayPost(); //display the post in proper format
		std::cout << std::endl;
	}
}

Network<Account>* Account::getNetwork() const //return the network the account is apart of
{
	return network_apartof;
}

void Account::setNetwork(Network<Account> *entry) //set the network the account is apart of from the value passed
{
	network_apartof = entry;
}

bool Account::followAccount(const std::string& name) //adding account to following vector
{
	bool final = true;
    for (int i = 0; i < following.size(); i++) //cycle through current following
        if (following[i] == name) //if account is already following then final = false, thus returning false
            final = false;
    if (network_apartof != nullptr && final == true && getNetwork()->containsAccount(this))//if this account is apart of the network that wants to follow, and not already following the account passed
    {
        following.push_back(name); //if passed then add account passed to the following vector
        return true;
    }
    return false;
}

std::vector<std::string> Account::viewFollowing() const
{
	return following;
}