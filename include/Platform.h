#ifndef PLATFORM_H
#define PLATFORM_H

#include <GraphicsEngine.h>


class Platform
{
    public:
        Platform(float size, sf::Vector2f position);
        virtual ~Platform();

        void Draw();

        int CheckCollision(sf::Sprite* sprite);
        int CheckBorder(sf::Sprite* sprite);

    private:
        sf::Sprite* sprite;
        sf::Texture texture;
};

#endif // PLATFORM_H
