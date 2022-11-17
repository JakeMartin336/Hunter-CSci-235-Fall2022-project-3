// Jacob Martin
// 10/11/2022
// Network.hpp
// Project 3 - Define and implement the Network template class with a header and a source file. In this project you will design and implement the network as a "bag of accounts".

#ifndef _NETWORK_ //defining Network
#define _NETWORK_

#include "Post.hpp" //include needed headers and libraries
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

template<class ItemType> //defining Network as template
class Network
{
public:
	Network();
	int getSizeOfNetwork() const;
	bool isEmpty() const;
	bool addAccount(ItemType* entry);
	bool removeAccount(const ItemType* entry);
	void clear();
	bool containsAccount(const ItemType* entry) const;

	void populateNetwork(const std::string file);
	void operator-=(Network<ItemType>& entry);

	void printFeedForAccount(ItemType& entry);
	bool authenticateFollow(ItemType& entry, const std::string& name);
	bool addToFeed(const Post& entry);
private:
	static const int DEFAULT_CAPACITY = 200;
	ItemType* items[DEFAULT_CAPACITY];
	int acct_count;
	std::vector<Post> net_posts;

	int getIndexOf(const std::string& usr) const;
};
#include "Network.cpp"
#endif