#include "stdafx.h"
#include "MenuManager.h"

MenuManager::MenuManager() : currentMenu(nullptr) { }

MenuManager::MenuManager(IMenu* pMenu) : currentMenu(pMenu) { }

MenuManager::MenuManager(const MenuManager& MM) : currentMenu(MM.currentMenu) { }

MenuManager& MenuManager::operator=(const MenuManager& MM)
{
	if (&MM == this) return *this;

	if (currentMenu)
		delete currentMenu;
	currentMenu = MM.currentMenu;
	return *this;
}

MenuManager::~MenuManager()
{
	if (currentMenu)
		delete currentMenu;
}

void MenuManager::setMenu(IMenu* pMenu)
{
	if (currentMenu)
		delete currentMenu;
	currentMenu = pMenu;
}

void MenuManager::drawMenu(HDC hDC, int cx, int cy)
{
	currentMenu->drawMenu(hDC, cx, cy);
}

void MenuManager::resizeMenu(int cx, int cy)
{
	currentMenu->resizeMenu(cx, cy);
}

void MenuManager::handleInput(HWND hWnd, UINT m, WPARAM wp, LPARAM lp)
{
	currentMenu->handleInput(hWnd, m, wp, lp);
}