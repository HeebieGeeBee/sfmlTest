#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    sf::Texture playerTexture;
    playerTexture.loadFromFile("tux-spritesheet.png");


    Player player(&playerTexture, sf::Vector2u(3,9), 0.1f, 100.0f);

    float deltaTime = 0.0f;
    sf::Clock clock;


	// Start the game loop
    while (app.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }


        player.Update(deltaTime);

        // Clear screen
        app.clear(sf::Color::White);
        // Update the window
        player.Draw(app);

        app.display();
    }

    return EXIT_SUCCESS;
}
