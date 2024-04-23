#include "stdafx.h"

NewMenuStorage::NewMenuStorage() :
	age(MIN_AGE),
	unnassignedAttributes(30),
	strength(BASIC_PLAYER_ATTRIBUTES),
	constitution(BASIC_PLAYER_ATTRIBUTES),
	dexterity(BASIC_PLAYER_ATTRIBUTES),
	intelligence(BASIC_PLAYER_ATTRIBUTES),
	wisdom(BASIC_PLAYER_ATTRIBUTES),
	charisma(BASIC_PLAYER_ATTRIBUTES)
{ }

NewMenuStorage::NewMenuStorage(const NewMenuStorage& NMS) :
	age(NMS.age),
	unnassignedAttributes(NMS.unnassignedAttributes),
	strength(NMS.strength),
	constitution(NMS.constitution),
	dexterity(NMS.dexterity),
	intelligence(NMS.intelligence),
	wisdom(NMS.wisdom),
	charisma(NMS.charisma)
{ }

NewMenuStorage& NewMenuStorage::operator=(const NewMenuStorage& NMS)
{
	if (&NMS == this) return *this;

	age = NMS.age;
	unnassignedAttributes = NMS.unnassignedAttributes;
	strength = NMS.strength;
	constitution = NMS.constitution;
	dexterity = NMS.dexterity;
	intelligence = NMS.intelligence;
	wisdom = NMS.wisdom;
	charisma = NMS.charisma;
	return *this;
}