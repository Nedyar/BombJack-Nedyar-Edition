#include <iostream>
using namespace std;
#include "Mummy.h"
#include <Level.h>

Mummy::Mummy(sf::Vector2f startPos, int maxTurns, bool facingLeft)
{
    pos = startPos;
    vel = sf::Vector2f(0.0,0.0);

    this->maxTurns = maxTurns;
    this->facingLeft = facingLeft;

    texture.loadFromFile("img/Mummy.png");
    sprite = new sf::Sprite(texture);
    postureY = 2;
    sprite->setTextureRect(sf::IntRect(14,16,14,16));

    sprite->setOrigin(sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2);
    sprite->setPosition(pos);
}

Mummy::~Mummy()
{
    Level::GetInstance()->RemoveEnemy(this);
}

void Mummy::Update(float elapsedTime)
{
    sprite->setPosition(pos);

    if (Level::GetInstance()->CheckCollision(sprite))
    {
        pos = sprite->getPosition();
        onGround = true;
        vel.y = 0;
    }

    if (!onGround)
    {
        postureX = 0;
        postureY = 1;

        vel.y += MAX_JUMP_SPEED/7;

        if (vel.y > MAX_JUMP_SPEED)
            vel.y = MAX_JUMP_SPEED;
    }
    else
    {
        vel.x = WALK_SPEED/4 - WALK_SPEED/2*facingLeft;

            postureX += .5;
            postureY = 0;

            if (postureX >= 3)
                postureX = 0;
            else if (postureX < 0)
                postureX = 0;
        if (turns < maxTurns)
        {
            int border = Level::GetInstance()->CheckBorder(sprite);

            if ((border == -1 && facingLeft) || (border == 1 && !facingLeft))
            {

                facingLeft = !facingLeft;
                turns++;
            }
        }
        else if (!Level::GetInstance()->CheckCollision(sprite))
        {
            onGround = false;
            vel.x = 0;
            turns = 0;
            facingLeft = !facingLeft;
        }
    }

    sprite->setTextureRect(sf::IntRect((int)postureX*14, postureY*16,14,16));
    sprite->setScale(1-facingLeft*2,1);

    pos.x += vel.x * elapsedTime;
    pos.y += vel.y * elapsedTime;

    if (pos.y > 185.4)
    {
        pos.y = 185.4;
        Level::GetInstance()->AddEnemy(new Bird(pos));
        delete this;
    }
}
