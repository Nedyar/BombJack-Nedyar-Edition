#include "Player.h"

#include <Level.h>

Player::Player()
{
    pos = sf::Vector2f((240.5-23.4)/2+23.4,(185.4-16.5)/2+16.5);
    vel = sf::Vector2f(0.0,0.0);

    texture.loadFromFile("img/SpriteSheet.png");
    sprite = new sf::Sprite(texture);
    sprite->setTextureRect(sf::IntRect(4,4,15,15));

    sprite->setOrigin(sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2);
    sprite->setPosition(pos);
}

Player::~Player()
{

}

bool Player::Jump()
{
    if (onGround)
    {
        onGround = false;
        jumping = true;

        jumpedFrom = pos.y;

        return true;
    }
    else if (pos.y < jumpedFrom-0.6 || pos.y > jumpedFrom+0.6)
    {
        jumping = false;
        airJump = true;
    }

    return false;
}

void Player::Walk(bool left)
{
    facingLeft = left;
    vel.x = WALK_SPEED - facingLeft*(WALK_SPEED*2); // if facingLeft, velocity will be 1-2 = -1, otherwise, it will be 1+0 = 1
    walking = true;
}

void Player::StopWalking()
{
    walking = false;
    vel.x = 0;
}

void Player::Update(float elapsedTime)
{
    sprite->setPosition(pos);
    bool topTouched = false;
    int collision = Level::GetInstance()->CheckCollision(sprite);

    pos = sprite->getPosition();
    switch (collision)
    {
    case 1:
        if (!onGround && !jumping)
        {
            onGround = true;
            jumping = false;
            vel.y = 0;
        }
        break;
    case 3:
        jumping = false;
        vel.y = 0;
        topTouched = true;
        break;
    }


    if (walking)
    {
        postureX += .2;
        postureY = 0;

        if (postureX >= 5)
            postureX = 1;
        else if (postureX < 1)
            postureX = 1;

    }
    else
    {
        postureX = 0;
        postureY = 0;
    }


    if (jumping)
    {
        postureX = 9;
        postureY = 0;

        if (walking)
            postureX = 13;

        vel.y -= MAX_JUMP_SPEED/7;

        if (vel.y < -MAX_JUMP_SPEED)
            vel.y = -MAX_JUMP_SPEED;

    }
    else if (!onGround)
    {
        postureX = 10;
        postureY = 0;

        if (walking)
            postureX = 14;


        vel.y += MAX_JUMP_SPEED/7;

        if (vel.y > MAX_JUMP_SPEED)
            vel.y = MAX_JUMP_SPEED;

    }


    if (airJump)
    {
        postureX = 0;
        postureY = 0;

        vel.y = 0;

        airJump = false;
    }


    int col = 4 + ((int)postureX)*15+ ((int)postureX)*5;
    int row = 4 + ((int)postureY);

    sprite->setTextureRect(sf::IntRect(col, row,15,15));
    sprite->setScale(1-facingLeft*2,1);

    pos.x += vel.x * elapsedTime;
    pos.y += vel.y * elapsedTime;

    if (!collision && pos.y < 185.39)
        onGround = false;

    if (pos.x < 23.4)
        pos.x = 23.4;
    if (pos.x > 240.5)
        pos.x = 240.5;

    if (pos.y < 16.5)
    {
        pos.y = 16.5;
        jumping = false;
        vel.y = 0;
        topTouched = true;
    }
    if (pos.y > 185.4)
    {
        pos.y = 185.4;
        postureX = 12;
        postureY = 0;
        onGround = true;
        vel.y = 0;
    }

    if (topTouched)
        Level::GetInstance()->SumScore(2);

    Level::GetInstance()->TakeBomb(sprite);
}
