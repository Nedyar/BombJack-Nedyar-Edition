#include "Platform.h"
#include <cmath>

Platform::Platform(float size, sf::Vector2f position)
{
    texture.loadFromFile("img/platform.png");
    sprite = new sf::Sprite(texture);
    sprite->setTextureRect(sf::IntRect(0,0,40,8));

    sprite->setOrigin(sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2);
    sprite->scale(size,1);
    sprite->setPosition(position);
}

Platform::~Platform()
{
}

void Platform::Draw()
{
    GraphicsEngine::Instance()->Draw(*sprite);
}

int Platform::CheckCollision(sf::Sprite* spr)
{
    if (spr->getGlobalBounds().intersects(this->sprite->getGlobalBounds()))
    {
        float leftPlatform = sprite->getPosition().x - sprite->getGlobalBounds().width/2;
        float rightPlatform = sprite->getPosition().x + sprite->getGlobalBounds().width/2;
        float topPlatform = sprite->getPosition().y - sprite->getGlobalBounds().height/2;
        float bottomPlatform = sprite->getPosition().y + sprite->getGlobalBounds().height/2;

        float leftPlayer = spr->getPosition().x - spr->getGlobalBounds().width/2;
        float rightPlayer = spr->getPosition().x + spr->getGlobalBounds().width/2;
        float topPlayer = spr->getPosition().y - spr->getGlobalBounds().height/2;
        float bottomPlayer = spr->getPosition().y + spr->getGlobalBounds().height/2;

        float topIntersec = bottomPlayer - topPlatform; // Top of platform
        float bottomIntersec = bottomPlatform - topPlayer; // Bottom of platform
        float leftIntersec = rightPlayer - leftPlatform; // Left of platform
        float rightIntersec = rightPlatform - leftPlayer; // Right of platform

        float minYIntersec = std::min(topIntersec,bottomIntersec);
        float minXIntersec = std::min(leftIntersec, rightIntersec);
        float minIntersec = std::min(minXIntersec, minYIntersec);

        if (minIntersec == topIntersec)
        {
            spr->setPosition(spr->getPosition().x, topPlatform-(bottomPlayer - spr->getPosition().y)+0.01);
            return 1;
        }
        else if (minIntersec == bottomIntersec)
        {
            spr->setPosition(spr->getPosition().x, bottomPlatform+(spr->getPosition().y-topPlayer));
            return 3;
        }

        else if (minIntersec == leftIntersec)
        {
            spr->setPosition(leftPlatform - (rightPlayer-spr->getPosition().x), spr->getPosition().y);
            return 4;
        }
        else
        {
            spr->setPosition(rightPlatform + (spr->getPosition().x-leftPlayer), spr->getPosition().y);
            return 2;
        }
    }
    else
        return 0;
}

int Platform::CheckBorder(sf::Sprite* spr)
{
    if (CheckCollision(spr))
    {
        float rightPlatform = sprite->getPosition().x + sprite->getGlobalBounds().width/2;
        float leftPlatform = sprite->getPosition().x - sprite->getGlobalBounds().width/2;

        float leftCharacter = spr->getPosition().x - spr->getGlobalBounds().width/2;
        float rightCharacter = spr->getPosition().x + spr->getGlobalBounds().width/2;

        float left = std::fabs(leftCharacter - leftPlatform);
        float right = std::fabs(rightCharacter - rightPlatform);

        if (left < 1)
            return -1;
        else if (right < 1)
            return 1;
    }
    return 0;
}
