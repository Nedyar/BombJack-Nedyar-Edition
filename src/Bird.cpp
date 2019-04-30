#include <iostream>
using namespace std;

#include "Bird.h"
#include "Level.h"

Bird::Bird(sf::Vector2f startPos, bool facingLeft)
{
    pos = startPos;
    vel = sf::Vector2f(0.0,0.0);

    this->facingLeft = facingLeft;

    texture.loadFromFile("img/Bird.png");
    sprite = new sf::Sprite(texture);
    postureY = 2;
    sprite->setTextureRect(sf::IntRect(0,16,16,16));

    sprite->setOrigin(sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2);
    sprite->setPosition(pos);
}

Bird::~Bird()
{
    Level::GetInstance()->RemoveEnemy(this);
}

void Bird::Update(float elapsedTime)
{
    sprite->setPosition(pos);

    int direction;
    int collision = Level::GetInstance()->CheckCollision(sprite);
    pos = sprite->getPosition();

    float xDistance = Level::GetInstance()->GetDistanceX(this);
    float yDistance = Level::GetInstance()->GetDistanceY(this);

    if (collision > 0)
        switch (collision)
        {
        case 1:
        case 3:
            if (xDistance > 0)
                direction = 4;
            else
                direction = 2;
            break;
        case 2:
        case 4:
            if (yDistance > 0)
                direction = 1;
            else
                direction = 3;
            break;
        }
    else
    {
        direction = Level::GetInstance()->GetMovementDirection(this);
    }

    switch (direction) {
        case 1:
            vel.x = 0;
            vel.y = -WALK_SPEED/4;
            break;
        case 2:
            vel.x = WALK_SPEED/4;
            vel.y = 0;
            facingLeft = false;
            break;
        case 3:
            vel.x = 0;
            vel.y = WALK_SPEED/4;
            break;
        case 4:
            vel.x = -WALK_SPEED/4;
            vel.y = 0;
            facingLeft = true;
            break;
    }


    postureX += .5;

    if (postureX >= 4)
        postureX = 0;
    else if (postureX < 0)
        postureX = 0;

    if (vel.x == 0)
        postureY = 1;
    else
        postureY = 0;

    sprite->setTextureRect(sf::IntRect((int)postureX*16, postureY*16,16,16));
    sprite->setScale(-1+facingLeft*2,1);

    pos.x += vel.x * elapsedTime;
    pos.y += vel.y * elapsedTime;

    /*if (pos.x < 23.4) {
        pos.x = 23.4;
        facingLeft = !facingLeft;
        turns++;
    }
    if (pos.x > 240.5) {
        turns++;
        pos.x = 240.5;
        facingLeft = !facingLeft;
    }*/

}

