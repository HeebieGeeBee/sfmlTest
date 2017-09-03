#include <SFML/Graphics.hpp>
#include "Animation.h"

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    sf::RectangleShape paddle;
    paddle.setSize(sf::Vector2f(50, 20));
    paddle.setFillColor(sf::Color(125,125,125));
    paddle.setOutlineColor(sf::Color(255,0,0));
    paddle.setOrigin(25.0f, 10.0f);
    paddle.setPosition(app.getSize().x/2, app.getSize().y - 40);

    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    player.setPosition(206.0f, 206.0f);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("spritesheet_caveman.png");
    player.setTexture(&playerTexture);

    Animation animation(&playerTexture, sf::Vector2u(4,4), 1.3f);

    float deltaTime = 0.0f;
    sf::Clock clock;


    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 4;
    textureSize.y /= 4;

    player.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));


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


        animation.Update(0, deltaTime, false);
        player.setTextureRect(animation.uvRect);
        // Clear screen
        app.clear(sf::Color::White);

        app.draw(player);
        app.draw(paddle);
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
