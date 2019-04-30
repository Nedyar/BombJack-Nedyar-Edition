#ifndef PLAYER_H
#define PLAYER_H

#include <Character.h>

class Player : public Character
{
public:
    Player();
    virtual ~Player();

    bool Jump();
    void Walk(bool left = false);
    void StopWalking();

    void Update(float elapsedTime) override;

protected:

private:
    float jumpedFrom = 0;

    bool walking = false;
    bool jumping = false;
    bool airJump = false;
};

#endif // PLAYER_H
