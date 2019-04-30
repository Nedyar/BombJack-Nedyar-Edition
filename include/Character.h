#ifndef CHARACTER_H
#define CHARACTER_H

#include <GraphicsEngine.h>

class Character
{
public:
    // Functions
    virtual void Update(float elapsedTime) = 0;
    void Draw(float percentTick);
    sf::Vector2f GetPosition();

protected:
    // Atributes
    sf::Vector2f pos;
    sf::Vector2f vel;

    bool onGround = false;
    bool facingLeft = false;

    const float WALK_SPEED = 0.1;
    const float MAX_JUMP_SPEED = 0.1;

    sf::Sprite* sprite;
    sf::Texture texture;
    float postureX = 0;
    float postureY = 0;
};

#endif // CHARACTER_H
