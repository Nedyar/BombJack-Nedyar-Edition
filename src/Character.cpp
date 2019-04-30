#include "Character.h"

void Character::Draw(float percentTick)
{
    sprite->setPosition(sprite->getPosition().x * (1-percentTick) + pos.x * percentTick, sprite->getPosition().y * (1-percentTick) + pos.y * percentTick);
    GraphicsEngine::Instance()->Draw(*sprite);
}

sf::Vector2f Character::GetPosition() {
    return pos;
}
