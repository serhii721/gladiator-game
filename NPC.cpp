#include "stdafx.h"
#include "NPC.h"

NPC::NPC() : Fighter(), NamedNPC(), Leveling() { }

NPC::NPC(const Fighter& F, const NamedNPC& C, const Leveling& L) : Fighter(F), NamedNPC(C), Leveling(L) { }

NPC::NPC(const NPC& C) : Fighter(C), NamedNPC(C), Leveling(C) { }

NPC& NPC::operator=(const NPC& C)
{
	if (&C == this) return *this;
	Fighter::operator=(C);
	NamedNPC::operator=(C);
	Leveling::operator=(C);
	return *this;
}

NPC::~NPC() { }

unique_ptr<NPC> NPC::clone() const
{
	return make_unique<NPC>(*this);
}
