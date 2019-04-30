#ifndef MUMMY_H
#define MUMMY_H

#include <Character.h>


class Mummy : public Character
{
    public:
        Mummy(sf::Vector2f startPos, int maxTurns, bool facingLeft = false);
        virtual ~Mummy();

        void Update(float elapsedTime) override;

    protected:

    private:
        int turns = 0;
        int maxTurns;
};

#endif // MUMMY_H
