#pragma once
#include "IMenu.h"

class StoryScreen :
	public IMenu
{
private:
	vector<HWND> hItems;

	HBITMAP hBackgroundImage;
	HBRUSH hBackgroundBrush;

	bool isChoiceRequired;
	bool haveFought;
	bool haveWon;

public:
	enum Screen
	{
		WELCOME_SCREEN,
		START_GAME_SCREEN,
		FIRST_VICTORY,
		STOLEN_MONEY,
		CENTURION_OFFER,
		GAINED_FREEDOM,
		QUEST_PERUGIA_SHANDAR,
		SCREEN_NUMBER
	};
	enum WelcomeScreenItems
	{
		WELCOME_SCREEN_STAT_DATE,
		WELCOME_SCREEN_STAT_TEXT,
		WELCOME_SCREEN_ITEM_NUMBER
	};
	enum StolenMoneyScreenItems
	{
		STOLEN_MONEY_SCREEN_STAT_1,
		STOLEN_MONEY_SCREEN_STAT_2,
		STOLEN_MONEY_SCREEN_STAT_3,
		STOLEN_MONEY_SCREEN_STAT_ESCAPE,
		STOLEN_MONEY_SCREEN_STAT_STAY,
		STOLEN_MONEY_SCREEN_BUT_ESCAPE,
		STOLEN_MONEY_SCREEN_BUT_STAY,
		STOLEN_MONEY_SCREEN_ITEM_NUMBER
	};
	enum CenturionOfferScreenItems
	{
		CENTURION_OFFER_SCREEN_STAT_1,
		CENTURION_OFFER_SCREEN_STAT_2,
		CENTURION_OFFER_SCREEN_STAT_ACCEPT,
		CENTURION_OFFER_SCREEN_STAT_DECLINE,
		CENTURION_OFFER_SCREEN_BUT_ACCEPT,
		CENTURION_OFFER_SCREEN_BUT_DECLINE,
		CENTURION_OFFER_SCREEN_ITEM_NUMBER
	};
	enum GainedFreedomScreenItems
	{
		GAINED_FREEDOM_SCREEN_STAT_1,
		GAINED_FREEDOM_SCREEN_STAT_2,
		GAINED_FREEDOM_SCREEN_STAT_CHOSE_REBELS,
		GAINED_FREEDOM_SCREEN_STAT_CHOSE_LEGION,
		GAINED_FREEDOM_SCREEN_BUT_CHOOSE_REBELS,
		GAINED_FREEDOM_SCREEN_BUT_CHOOSE_LEGION,
		GAINED_FREEDOM_SCREEN_ITEM_NUMBER
	};
	enum QuestPerugiaShandarAbhilashaItems
	{
		SHANDAR_STAT_INTRO,
		SHANDAR_BUT_INTRO,
		SHANDAR_STAT_INTRO2,
		SHANDAR_BUT_CHOICE1_QUESTION_WHERE,
		SHANDAR_BUT_CHOICE1_QUESTION_WHO,
		SHANDAR_BUT_CHOICE1_QUESTION_WHY,
		SHANDAR_BUT_CHOICE1_LEAVE,
		SHANDAR_STAT_CHOICE1_ANSWER_WHO,
		SHANDAR_STAT_CHOICE1_ANSWER_WHY,
		SHANDAR_STAT_CHOICE1_ANSWER_WHERE,
		SHANDAR_BUT_CHOICE2_TALK,
		SHANDAR_BUT_CHOICE2_LEAVE,
		SHANDAR_STAT_CHOICE2_ANSWER_TALK,
		SHANDAR_BUT_CHOICE3_FIGHT,
		SHANDAR_BUT_CHOICE3_STRENGTH,
		SHANDAR_BUT_CHOICE3_CHARISMA,
		SHANDAR_STAT_CHOICE3_FIGHT_WIN,
		SHANDAR_STAT_CHOICE3_FIGHT_LOSE,
		SHANDAR_STAT_CHOICE3_STRENGTH_WIN,
		SHANDAR_STAT_CHOICE3_STRENGTH_LOSE,
		SHANDAR_STAT_CHOICE3_CHARISMA_WIN,
		SHANDAR_STAT_CHOICE3_CHARISMA_LOSE,
		SHANDAR_BUT_COMEBACK_NIGHT,
		SHANDAR_STAT_COMEBACK_NIGHT,
		SHANDAR_BUT_CHOICE4_NIGHT_ENTER,
		SHANDAR_BUT_CHOICE4_NIGHT_DEXTERITY,
		SHANDAR_STAT_CHOICE4_NIGHT_DEXTERITY_WIN,
		SHANDAR_STAT_CHOICE4_NIGHT_DEXTERITY_LOSE,
		SHANDAR_STAT_ENTER_HOUSE,
		SHANDAR_BUT_ENTER_HOUSE,
		SHANDAR_STAT_ENTER_HOUSE2,
		SHANDAR_BUT_CHOICE5_FIGHT,
		SHANDAR_BUT_CHOICE5_CHARISMA,
		SHANDAR_STAT_CHOICE5_FIGHT_WIN,
		SHANDAR_STAT_CHOICE5_FIGHT_LOSE,
		SHANDAR_STAT_LOST_QUEST,
		SHANDAR_STAT_CHOICE5_CHARISMA_WIN,
		SHANDAR_STAT_CHOICE5_CHARISMA_LOSE,
		SHANDAR_BUT_CHOICE6_SPARE,
		SHANDAR_BUT_CHOICE6_EXECUTE,
		SHANDAR_BUT_CHOICE6_EXTORT,
		SHANDAR_BUT_CHOICE6_EXILE,
		SHANDAR_STAT_CHOICE6_EXECUTED,
		SHANDAR_STAT_CHOICE6_EXTORT,
		SHANDAR_STAT_CHOICE6_EXILE,
		SHANDAR_BUT_CHOICE6_EXTORT_EXECUTE,
		SHANDAR_BUT_CHOICE6_WHERE_GIRL,
		SHANDAR_STAT_FOUND_GIRL,
		SHANDAR_BUT_GREET_GIRL,
		SHANDAR_STAT_GREET_GIRL,
		SHANDAR_BUT_LETS_LEAVE,
		SHANDAR_STAT_LEAVE_QUIET,
		SHANDAR_STAT_LEAVE_LOUD,
		SHANDAR_STAT_RETURNED_DAUGHTER,
		SHANDAR_BUT_ASK_REWARD,
		SHANDAR_BUT_GOODBYE,
		SHANDAR_STAT_REWARD,
		SHANDAR_STAT_GOODBYE,
		SHANDAR_BUT_NAME,
		SHANDAR_STAT_THANKS,
		SHANDAR_STAT_END,
		SHANDAR_ITEM_NUMBER
	};

	StoryScreen();
	StoryScreen(HWND);
	StoryScreen(const StoryScreen&);
	StoryScreen& operator=(const StoryScreen&);
	virtual ~StoryScreen();

	void drawMenu(HWND, HDC, int, int) override;
	void resizeMenu(int, int) override;
	void handleInput(HWND, UINT, WPARAM, LPARAM) override;
	bool stylizeWindow(HWND, UINT, WPARAM, LPARAM, LRESULT&) override;
	void displayScreen(HWND, Screen);

private:
	Screen currentScreen;
	int currentSubScreen;

public:
	void setCurrentScreen(Screen);
	void setCurrentSubScreen(int);

	Screen getCurrentScreen() const;
	int getCurrentSubScreen() const;

};
