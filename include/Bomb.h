#ifndef BOMB_H
#define BOMB_H

#include <GraphicsEngine.h>

class Bomb
{
    public:
        Bomb(sf::Vector2f position);
        virtual ~Bomb();

        void Draw();
        void Update();

        bool TakeBomb(sf::Sprite* sprite);
        void SetCurrent();
        sf::Vector2f GetPosition();

    private:
        sf::Sprite* sprite;
        sf::Texture texture;

        bool current = false;

        float posture = 0;
};

#endif // BOMB_H
