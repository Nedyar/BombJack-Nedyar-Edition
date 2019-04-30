#include "Bomb.h"

Bomb::Bomb(sf::Vector2f position)
{
    texture.loadFromFile("img/SpriteSheet.png");
    sprite = new sf::Sprite(texture);
    sprite->setTextureRect(sf::IntRect(5 + 15 + 6, 5 + 6*16 + 6*6, 12, 15));

    sprite->setOrigin(sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2);
    sprite->setPosition(position);
}

Bomb::~Bomb()
{
    //dtor
}

void Bomb::Draw()
{
    GraphicsEngine::Instance()->Draw(*sprite);
}

void Bomb::Update()
{
    if (current)
    {
        posture += .5;

        if (posture >= 5)
            posture = 2;
        else if (posture < 2)
            posture = 2;

        int col = 6 + ((int)posture)*15+ ((int)posture)*5;
        int row = 5 + 6*16 + 6*6;

        sprite->setTextureRect(sf::IntRect(col, row,15,15));
    }
}

bool Bomb::TakeBomb(sf::Sprite* sprite)
{
    float bombWidth = this->sprite->getGlobalBounds().width;
    float bombHeight = this->sprite->getGlobalBounds().height;
    sf::Vector2f bombPosition = this->sprite->getPosition();

    int reduction = 5;

    sf::FloatRect bombCollider = sf::FloatRect(bombPosition.x-(bombWidth/2-reduction),bombPosition.y-(bombHeight/2-reduction),bombWidth-reduction*2,bombHeight-reduction*2);

    return sprite->getGlobalBounds().intersects(bombCollider);
}

void Bomb::SetCurrent()
{
    current = true;
}

sf::Vector2f Bomb::GetPosition() {
    return sprite->getPosition();
}
