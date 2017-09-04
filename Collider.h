#ifndef COLLIDER_H
#define COLLIDER_H
#include <SFML/Graphics.hpp>


class Collider
{
    public:
        Collider(sf::RectangleShape& body);
        virtual ~Collider();

        void Move(float dx, float dy) const { body.move(dx, dy); }

        bool CheckCollision(const Collider &other, float push);
        sf::Vector2f GetPosition() const { return body.getPosition(); }
        sf::Vector2f GetHalfSize() const { return body.getSize() / 2.0f;  }

    private:

        sf::RectangleShape& body;
};

#endif // COLLIDER_H
