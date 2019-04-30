#ifndef BIRD_H
#define BIRD_H

#include <Character.h>


class Bird : public Character
{
    public:
        Bird(sf::Vector2f startPos, bool facingLeft = false);
        virtual ~Bird();

        void Update(float elapsedTime) override;

    protected:

    private:
};

#endif // BIRD_H
