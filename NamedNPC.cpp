#include "stdafx.h"
#include "NamedNPC.h"

NamedNPC::NamedNPC() : firstNameIndex(0), lastNameIndex(0) { }

NamedNPC::NamedNPC(int fNameIndex, int lNameIndex) :
	firstNameIndex(fNameIndex),
	lastNameIndex(lNameIndex)
{ }

NamedNPC::NamedNPC(const NamedNPC& C) :
	firstNameIndex(C.firstNameIndex),
	lastNameIndex(C.lastNameIndex)
{ }

NamedNPC& NamedNPC::operator=(const NamedNPC& C)
{
	if (&C == this) return *this;
	firstNameIndex = C.firstNameIndex;
	lastNameIndex = C.lastNameIndex;
	return *this;
}

NamedNPC::~NamedNPC() { }

void NamedNPC::rename(int fNameIndex, int lNameIndex)
{
	firstNameIndex = fNameIndex;
	lastNameIndex = lNameIndex;
}

string NamedNPC::getName()
{
	string name = "";
	name += localization.getFirstName(firstNameIndex);
	name += ' ' + localization.getLastName(lastNameIndex);
	return name;
}
