#include "Game.h"
#include <thread>
#include <chrono>

Game::Game()
	: m_pStateMachine(nullptr)
	, isGameOver(false)
{

}

void Game::Initialize(GameStateMachine* pStateMachine)
{
	if (pStateMachine != nullptr)
	{
		pStateMachine->Init();
		m_pStateMachine = pStateMachine;
	}
}

void Game::RunGameLoop()
{
	std::thread Drawer(&Game::Draw, this);
	std::thread Updater(&Game::Update, this, true);
	
	Updater.join();
	Drawer.join();
}

void Game::Deinitialize()
{
	if (m_pStateMachine != nullptr)
		m_pStateMachine->Cleanup();
}

bool Game::Update(bool processInput)
{
	while (!isGameOver)
	{
		isGameOver = m_pStateMachine->UpdateCurrentState(processInput);
	}
	return true;
}

void Game::Draw()
{
	while (!isGameOver)
	{
		m_pStateMachine->DrawCurrentState();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}
