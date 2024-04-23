#include "stdafx.h"
#include "Game.h"

Game::Game() :
	menuManager(),
	pWorldMap(make_unique<WorldMap>()),
	pFighting(make_unique<Fighting>()),
	pPlayer(make_unique<Player>()),
	displayState(DisplayState::MENU)
{ }

Game::Game(const Game& GAME) :
	menuManager(GAME.menuManager),
	pWorldMap(make_unique<WorldMap>(*GAME.pWorldMap)),
	pFighting(make_unique<Fighting>()),
	pPlayer(make_unique<Player>(*GAME.pPlayer)),
	displayState(GAME.displayState)
{ }

Game& Game::operator=(const Game& GAME)
{
	if (&GAME == this) return *this;

	if (GAME.pWorldMap)
	{
		if (!pWorldMap)
			pWorldMap = make_unique<WorldMap>(*GAME.pWorldMap);
		else
			*pWorldMap = *GAME.pWorldMap;
	}
	else
		pWorldMap = nullptr;

	if (GAME.pPlayer)
	{
		if (!pPlayer)
			pPlayer = make_unique<Player>(*GAME.pPlayer);
		else
			*pPlayer = *GAME.pPlayer;
	}
	else pPlayer = nullptr;

	pFighting = make_unique<Fighting>();

	menuManager = GAME.menuManager;
	displayState = GAME.displayState;

	return *this;
}

Game::~Game() { }

void Game::setPlayer(const Player& rPlayer)
{
	*pPlayer = rPlayer;
}

void Game::setWorldMap(const WorldMap& rWorldMap)
{
	*pWorldMap = rWorldMap;
}

Player& Game::getPlayer() const
{
	return *pPlayer;
}

WorldMap& Game::getWorldMap() const
{
	return *pWorldMap;
}

MenuManager& Game::getMenuManager()
{
	return menuManager;
}

void Game::drawWindow(HDC hdc, int cx, int cy)
{
	switch (displayState)
	{
	default:case MENU:
		menuManager.drawMenu(hdc, cx, cy);
		break;

	case WORLD_MAP:
		pWorldMap->drawWindow(hdc, cx, cy);
		break;

	case FIGHTING:
		pFighting->drawWindow(hdc, cx, cy);
		break;
	}
}

void Game::resizeWindow(int cx, int cy)
{
	switch (displayState)
	{
	default:case MENU:
		menuManager.resizeMenu(cx, cy);
		break;

	case WORLD_MAP:
		pWorldMap->resizeWindow(cx, cy);
		break;

	case FIGHTING:
		pFighting->resizeWindow(cx, cy);
		break;
	}
}

void Game::handleInput(HWND hWnd, UINT m, WPARAM wp, LPARAM lp)
{
	switch (displayState)
	{
	default:case MENU:
		menuManager.handleInput(hWnd, m, wp, lp);
		break;

	case WORLD_MAP:
		pWorldMap->handleInput(hWnd, m, wp, lp);
		break;

	case FIGHTING:
		pFighting->handleInput(hWnd, m, wp, lp);
		break;
	}
}