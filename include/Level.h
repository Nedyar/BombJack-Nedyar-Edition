#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <GraphicsEngine.h>
#include <Mummy.h>
#include <Bird.h>
#include <Player.h>
#include <Platform.h>
#include <Bomb.h>

class Level
{
public:
    static Level* Instance(int level, int lives, int score);
    static Level* GetInstance();
    virtual ~Level();

    bool Update(float elapsedTime);
    void Draw(float percentTime);
    void HandleEvents();
    bool IsOpen();

    int CheckCollision(sf::Sprite* sprite);
    int CheckBorder(sf::Sprite* sprite);
    void TakeBomb(sf::Sprite* sprite);

    int GetLevel();
    int GetLives();
    int GetScore();
    void SumScore(int score);
    void AddEnemy(Character* enemy);
    void RemoveEnemy(Character* enemy);
    int GetMovementDirection(Character* enemy);
    float GetDistanceX(Character* enemy);
    float GetDistanceY(Character* enemy);
    GraphicsEngine* engine;

protected:
    Level(int level, int lives, int score);
    Level(const Level&);
    Level &operator= (const Level&);

private:
    static Level* instance;

    sf::Texture texture;
    sf::Sprite* sprite;

    Player* player;
    int level;
    int lives;
    int score;
    int multiplier = 1;

    std::vector<Character*> enemies;
    std::vector<Bomb*> bombs;
    int currentBomb = -1;
    Platform** platforms;
    int nPlatforms;

};

#endif // LEVEL_H
