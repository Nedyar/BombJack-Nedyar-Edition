#include <Level.h>

#define UPDATE_TICK_TIME (1000/15) // ~67

int main()
{
    Level* level = Level::Instance(1,3,0);

    //sf::Clock clock;
    sf::Clock updateClock;
    sf::Time timeElapsed;

    //bool firstTime = true;

    // Start the game loop
    while (level->IsOpen())
    {
        level->HandleEvents();

        if (updateClock.getElapsedTime().asMilliseconds() >= UPDATE_TICK_TIME)
        {
            timeElapsed = updateClock.restart();
            if (!level->Update(timeElapsed.asMilliseconds())) {
                if (level->GetLevel() == 5)
                    level = Level::Instance(1,3,0);
                else
                    level = Level::Instance(level->GetLevel()+1,level->GetLives(),level->GetScore());
            }
        }

        float percentTick = std::min(1.0, updateClock.getElapsedTime().asMilliseconds()/(double)UPDATE_TICK_TIME);
        level->Draw(percentTick);
    }

    return EXIT_SUCCESS;
}
