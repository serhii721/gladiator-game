#pragma once

enum AttackResult
{
	DEALT_DAMAGE,
	DEALT_CRIT_DAMAGE,
	STUNNED,
	WERE_DODGED,
	WERE_BLOCKED,
	WERE_COUNTERATTAKED
};

enum FightStatus
{
	CONTINUE,
	OPPONENT_LOST,
	OPPONNENT_SURRENDERED,
	PLAYER_SURRENDERED,
	PLAYER_LOST
};

enum Attribute
{
	STRENGTH,
	CONSTITUTION,
	DEXTERITY,
	WISDOM,
	INTELLIGENCE,
	CHARISMA
};

enum Limit { MIN, MAX };

enum Cities
{
	ROME,
	NAPLES,
	METAPONTO,
	BOJANO,
	ANCONA,
	PERUGIA,
	FLORENCE,
	BOLOGNA,
	GENOA,
	AQUILEIA,
	MILAN,
	CITIES_NUMBER
};

enum DisplayState
{
	MENU,
	WORLD_MAP,
	FIGHTING,
	STORY_SCREEN
};

enum SoundEnum
{
	SOUND_BUTTON_CLICK,
	SOUND_FIGHT_HIT,
	SOUND_FIGHT_DODGED,
	SOUND_FIGHT_BLOCKED,
	SOUND_FIGHT_CRIT,
	SOUND_FIGHT_STUNNED,
	SOUND_FIGHT_COUNTERATTACKED,
	SOUND_GOLD,
	SOUND_LEVEL_UP,
	MUSIC_MENU_BACKGROUND,
	MUSIC_FIGHT_BACKGROUND,
	SOUND_NUMBER
};