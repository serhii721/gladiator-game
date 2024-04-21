#pragma once
#include "IMenu.h"

class MainMenu :
	public IMenu
{
private:
	vector<HWND> hItems;

	int currentSubMenu;
	vector<HWND> hSubItems;

	unique_ptr<NewMenuStorage> nms;
public:
	enum Item
	{
		BUT_CONTINUE,
		BUT_LOAD_GAME,
		BUT_NEW_GAME,
		BUT_SETTINGS,
		BUT_SPECIALS,
		BUT_EXIT,
		ITEM_NUMBER
	};
	enum NewGameItem
	{
		STAT_CHARACTER_CREATION,
		STAT_NAME,
		STAT_AGE,
		STAT_UNNASSIGNED_ATTRIBUTES,
		STAT_STRENGTH,
		STAT_CONSTITUTION,
		STAT_DEXTERITY,
		STAT_INTELLIGENCE,
		STAT_WISDOM,
		STAT_CHARISMA,
		EDIT_NAME,
		EDIT_AGE,
		EDIT_UNNASSIGNED_ATTRIBUTES,
		EDIT_STRENGTH,
		EDIT_CONSTITUTION,
		EDIT_DEXTERITY,
		EDIT_INTELLIGENCE,
		EDIT_WISDOM,
		EDIT_CHARISMA,
		BUT_AGE_MINUS,
		BUT_STRENGTH_MINUS,
		BUT_CONSTITUTION_MINUS,
		BUT_DEXTERITY_MINUS,
		BUT_INTELLIGENCE_MINUS,
		BUT_WISDOM_MINUS,
		BUT_CHARISMA_MINUS,
		BUT_AGE_PLUS,
		BUT_STRENGTH_PLUS,
		BUT_CONSTITUTION_PLUS,
		BUT_DEXTERITY_PLUS,
		BUT_INTELLIGENCE_PLUS,
		BUT_WISDOM_PLUS,
		BUT_CHARISMA_PLUS,
		NEW_GAME_BUT_BACK,
		NEW_GAME_BUT_NEXT,
		NEW_GAME_ITEM_NUMBER
	};
	enum SettingsItem
	{
		SETTINGS_STAT_VIDEO,
		SETTINGS_STAT_SOUND,
		SETTINGS_BUT_SOUND,
		SETTINGS_BUT_BACK,
		SETTINGS_ITEM_NUMBER
	};
	enum SpecialsItem
	{
		SPECIALS_STAT_SPECIALS,
		SPECIALS_STAT_TEXT,
		SPECIALS_BUT_BACK,
		SPECIALS_ITEM_NUMBER
	};

	MainMenu();
	MainMenu(HWND);
	MainMenu(const MainMenu&);
	MainMenu& operator=(const MainMenu&);
	virtual ~MainMenu();

	void drawMenu(HDC, int, int) override;
	void resizeMenu(int, int) override;
	void updateLanguage() override;
	void handleInput(HWND, UINT, WPARAM, LPARAM) override;
};
