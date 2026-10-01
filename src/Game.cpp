
#include "Game.h"
#include <iostream>


Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL)); //seeds random number generator with the current time
}

Game::~Game()
{

}

// We call this once after the game class is instantiated
// Duhh
bool Game::init()
{
	if(!background_texture.loadFromFile("../Data/Images/WhackaMole Worksheet/background.png"))
	{
		std::cout << "background texture failed to load \n";
	}
	background = sf::Sprite(background_texture);

	if (!bird_texture.loadFromFile("../Data/Images/WhackaMole Worksheet/bird.png"))
	{
		std::cout << "bird texture failed to load \n";
	}
	bird = sf::Sprite(bird_texture);
	bird.setPosition({200, 150});
	bird.setScale({ 0.5, 0.5 });

	if (!font.openFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "Font failed to load \n";
	}

	//title_text

  return true;
}

// Update runs after event polling and before rendering
// use it for everything that needs to update between frames
void Game::update(float dt)
{
	switch (game_state)
	{
	case GameState::MENU:

		break;
	case GameState::PLAYING:

		break;
	case GameState::GAMEOVER:

		break;
	}

}

// Runs after update, use it to tell the window what to draw this frame
void Game::render()
{
	switch (game_state)
	{
	case GameState::MENU:
		window.draw(background);
		window.draw(title_text);
		break;
	case GameState::PLAYING:
		window.draw(background);
		window.draw(bird);
		break;
	case GameState::GAMEOVER:




		break;
	}

}

//Called by event polling when a MouseButtonPressed event is found
void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
	// Event contains mouse position and which button was clicked

	// Don't need to extract position to a variable like this, this is just to show you it's a Vector2i
	sf::Vector2i position = event->position;

	// You can tell which button was pressed by comparing it to SFML's definitions of mouse buttons
	if (event->button == sf::Mouse::Button::Left)
	{
		//Left mouse button was pressed
	}
}

//Called by event polling when a MouseButtonReleased event is found
void Game::mouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
	//Works the same as MouseButtonPressed
	if (event->button == sf::Mouse::Button::Left)
	{
		//Left mouse button was released
	}
}

// Called by event polling when a KeyPressed event is found
void Game::keyPressed(const sf::Event::KeyPressed* event)
{
	// You can tell which button was pressed by the scancode to SFML's definitions of keyboard keys
	if (event->scancode == sf::Keyboard::Scancode::W)
	{
		//game_state = GameState::PLAYING;
		// W was pressed
	}

}

// Called by event polling when a KeyReleased event is found
void Game::keyReleased(const sf::Event::KeyReleased* event)
{
	// Works the same way as KeyPressed
	if (event->scancode == sf::Keyboard::Scancode::W)
	{
		// W was released
	}

}


