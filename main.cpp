#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include "Platform.h"

static const float VIEW_HEIGHT = 512.0f;

void ResizeView(sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
    sf::Texture playerTexture;
    playerTexture.loadFromFile("tux-spritesheet.png");


    Player player(&playerTexture, sf::Vector2u(3,9), 0.1f, 100.0f);

    Platform platform1(nullptr, sf::Vector2f(400.0f, 400.0f), sf::Vector2f(500.0f, 200.0f));
    Platform platform2(nullptr, sf::Vector2f(400.0f, 400.0f), sf::Vector2f(500.0f, 0.0f));

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
            switch (event.type)
            {
                case sf::Event::Closed: app.close();
                    break;
                case sf::Event::Resized: ResizeView(app, view);
                    break;
            }

        }


        player.Update(deltaTime);

        platform1.GetCollider().CheckCollision(player.GetCollider(), 0.0f);
        platform2.GetCollider().CheckCollision(player.GetCollider(), 1.0f);



        view.setCenter(player.GetPosition());


        // Clear screen
        app.clear(sf::Color::Blue);
        // Update the window
        app.setView(view);

        player.Draw(app);
        platform1.Draw(app);
        platform2.Draw(app);

        app.display();
    }

    return EXIT_SUCCESS;
}
