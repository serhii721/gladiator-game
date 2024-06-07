#pragma once
#include "Fighter.h"
#include "Leveling.h"

class Player :
	public Fighter,
	public Leveling
{
private:
	string name;
public:
	Player();
	Player(const Fighter&, const Leveling&, const string&);
	Player(const Player&);
	Player& operator=(const Player&);
	virtual ~Player();

	void setName(const string&);

	const string& getName() const;

	// Save and load
	void saveToFile(const string&);
	void loadFromFile(const string&);
};
