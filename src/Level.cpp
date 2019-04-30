#include <iostream>
using namespace std;

#include "Level.h"
#include <sstream>
#include <string.h>
#include <cmath>

Level* Level::instance = 0;

Level* Level::Instance(int level, int lives, int score)
{
    delete instance;

    instance = new Level(level, lives, score);
    return instance;
}

Level* Level::GetInstance()
{
    return instance;
}

Level::Level(int lvl, int lfs, int scr)
{
    engine = GraphicsEngine::Instance();

    level = lvl;
    score = scr;
    lives = lfs;
    player = new Player();

    char* file;
    switch (lvl)
    {
    case 1:
        file = "img/level_1_sphinx.png";

        nPlatforms = 5;
        platforms = new Platform*[nPlatforms];
        platforms[0] = new Platform(1.5,sf::Vector2f(172.5,47));
        platforms[1] = new Platform(1,sf::Vector2f(78,69.5));
        platforms[2] = new Platform(1.5,sf::Vector2f(145.5,132.5));
        platforms[3] = new Platform(1,sf::Vector2f(51,153.5));
        platforms[4] = new Platform(2,sf::Vector2f(186,173));


        bombs.push_back(new Bomb(sf::Vector2f(240,17)));    //1
        bombs.push_back(new Bomb(sf::Vector2f(213,17)));    //2
        bombs.push_back(new Bomb(sf::Vector2f(186,17)));    //3

        bombs.push_back(new Bomb(sf::Vector2f(132,59)));    //4
        bombs.push_back(new Bomb(sf::Vector2f(159,59)));    //5
        bombs.push_back(new Bomb(sf::Vector2f(186,59)));    //6
        bombs.push_back(new Bomb(sf::Vector2f(213,59)));    //7

        bombs.push_back(new Bomb(sf::Vector2f(240,80)));    //8
        bombs.push_back(new Bomb(sf::Vector2f(240,101)));   //9
        bombs.push_back(new Bomb(sf::Vector2f(240,122)));   //10
        bombs.push_back(new Bomb(sf::Vector2f(240,143)));   //11

        bombs.push_back(new Bomb(sf::Vector2f(24,80)));     //12
        bombs.push_back(new Bomb(sf::Vector2f(24,101)));    //13
        bombs.push_back(new Bomb(sf::Vector2f(24,122)));    //14
        bombs.push_back(new Bomb(sf::Vector2f(24,143)));    //15

        bombs.push_back(new Bomb(sf::Vector2f(51,17)));     //16
        bombs.push_back(new Bomb(sf::Vector2f(78,17)));     //17
        bombs.push_back(new Bomb(sf::Vector2f(105,17)));    //18

        bombs.push_back(new Bomb(sf::Vector2f(213,161)));   //19
        bombs.push_back(new Bomb(sf::Vector2f(186,161)));   //20
        bombs.push_back(new Bomb(sf::Vector2f(159,161)));   //21

        bombs.push_back(new Bomb(sf::Vector2f(105,185)));   //22
        bombs.push_back(new Bomb(sf::Vector2f(78,185)));    //23
        bombs.push_back(new Bomb(sf::Vector2f(51,185)));    //24


        enemies.push_back(new Mummy(sf::Vector2f(78,20),3));
        enemies.push_back(new Bird(sf::Vector2f(78,150)));

        break;
    case 2:
        file = "img/level_2_acrop.png";

        nPlatforms = 6;
        platforms = new Platform*[nPlatforms];
        platforms[0] = new Platform(1.1,sf::Vector2f(226.5,69.5));
        platforms[1] = new Platform(1.1,sf::Vector2f(37.5,69.5));
        platforms[2] = new Platform(1.1,sf::Vector2f(64.5,113));
        platforms[3] = new Platform(1.1,sf::Vector2f(199.5,113));
        platforms[4] = new Platform(1.1,sf::Vector2f(91.5,155));
        platforms[5] = new Platform(1.1,sf::Vector2f(172.5,155));


        bombs.push_back(new Bomb(sf::Vector2f(159,101)));   //1
        bombs.push_back(new Bomb(sf::Vector2f(186,101)));   //2
        bombs.push_back(new Bomb(sf::Vector2f(213,101)));   //3

        bombs.push_back(new Bomb(sf::Vector2f(186,38)));    //4
        bombs.push_back(new Bomb(sf::Vector2f(213,38)));    //5
        bombs.push_back(new Bomb(sf::Vector2f(240,38)));    //6

        bombs.push_back(new Bomb(sf::Vector2f(159,59)));    //7
        bombs.push_back(new Bomb(sf::Vector2f(132,59)));    //8
        bombs.push_back(new Bomb(sf::Vector2f(105,59)));    //9

        bombs.push_back(new Bomb(sf::Vector2f(159,17)));    //10
        bombs.push_back(new Bomb(sf::Vector2f(132,17)));    //11
        bombs.push_back(new Bomb(sf::Vector2f(105,17)));    //12

        bombs.push_back(new Bomb(sf::Vector2f(78,38)));     //13
        bombs.push_back(new Bomb(sf::Vector2f(51,38)));     //14
        bombs.push_back(new Bomb(sf::Vector2f(24,38)));     //15

        bombs.push_back(new Bomb(sf::Vector2f(51,101)));    //16
        bombs.push_back(new Bomb(sf::Vector2f(78,101)));    //17
        bombs.push_back(new Bomb(sf::Vector2f(105,101)));   //18

        bombs.push_back(new Bomb(sf::Vector2f(51,143)));    //19
        bombs.push_back(new Bomb(sf::Vector2f(78,143)));    //20
        bombs.push_back(new Bomb(sf::Vector2f(105,143)));   //21

        bombs.push_back(new Bomb(sf::Vector2f(159,143)));   //22
        bombs.push_back(new Bomb(sf::Vector2f(186,143)));   //23
        bombs.push_back(new Bomb(sf::Vector2f(213,143)));   //24


        break;
    case 3:
        file = "img/level_3_castle.png";

        nPlatforms = 5;
        platforms = new Platform*[nPlatforms];
        platforms[0] = new Platform(1.1,sf::Vector2f(91.5,50));
        platforms[1] = new Platform(1.1,sf::Vector2f(172.5,50));
        platforms[2] = new Platform(1,sf::Vector2f(132.5,134));
        platforms[3] = new Platform(1,sf::Vector2f(51,155));
        platforms[4] = new Platform(1,sf::Vector2f(213,155));

        bombs.push_back(new Bomb(sf::Vector2f(159,80)));    //1
        bombs.push_back(new Bomb(sf::Vector2f(159,101)));   //2
        bombs.push_back(new Bomb(sf::Vector2f(159,122)));   //3

        bombs.push_back(new Bomb(sf::Vector2f(186,143)));   //4
        bombs.push_back(new Bomb(sf::Vector2f(213,143)));   //5
        bombs.push_back(new Bomb(sf::Vector2f(240,143)));   //6

        bombs.push_back(new Bomb(sf::Vector2f(159,38)));    //7
        bombs.push_back(new Bomb(sf::Vector2f(186,38)));    //8

        bombs.push_back(new Bomb(sf::Vector2f(213,17)));    //9
        bombs.push_back(new Bomb(sf::Vector2f(240,17)));    //10

        bombs.push_back(new Bomb(sf::Vector2f(105,38)));    //11
        bombs.push_back(new Bomb(sf::Vector2f(78,38)));     //12

        bombs.push_back(new Bomb(sf::Vector2f(51,17)));     //13
        bombs.push_back(new Bomb(sf::Vector2f(24,17)));     //14

        bombs.push_back(new Bomb(sf::Vector2f(78,185)));    //15
        bombs.push_back(new Bomb(sf::Vector2f(105,185)));   //16

        bombs.push_back(new Bomb(sf::Vector2f(159,185)));   //17
        bombs.push_back(new Bomb(sf::Vector2f(186,185)));   //18

        bombs.push_back(new Bomb(sf::Vector2f(24,143)));    //19
        bombs.push_back(new Bomb(sf::Vector2f(51,143)));    //20
        bombs.push_back(new Bomb(sf::Vector2f(78,143)));    //21

        bombs.push_back(new Bomb(sf::Vector2f(105,80)));    //22
        bombs.push_back(new Bomb(sf::Vector2f(105,101)));   //23
        bombs.push_back(new Bomb(sf::Vector2f(105,122)));   //24

        break;
    case 4:
        file = "img/level_4_city.png";

        nPlatforms = 4;
        platforms = new Platform*[nPlatforms];
        platforms[0] = new Platform(1.1,sf::Vector2f(64.5,50));
        platforms[1] = new Platform(1.1,sf::Vector2f(199.5,50));

        platforms[2] = new Platform(1.1,sf::Vector2f(64.5,155));
        platforms[3] = new Platform(1.1,sf::Vector2f(199.5,155));

        bombs.push_back(new Bomb(sf::Vector2f(105,143)));   //1
        bombs.push_back(new Bomb(sf::Vector2f(78,143)));    //2
        bombs.push_back(new Bomb(sf::Vector2f(51,143)));    //3

        bombs.push_back(new Bomb(sf::Vector2f(186,101)));   //4
        bombs.push_back(new Bomb(sf::Vector2f(213,101)));   //5
        bombs.push_back(new Bomb(sf::Vector2f(240,101)));   //6

        bombs.push_back(new Bomb(sf::Vector2f(78,101)));    //7
        bombs.push_back(new Bomb(sf::Vector2f(51,101)));    //8
        bombs.push_back(new Bomb(sf::Vector2f(24,101)));    //9

        bombs.push_back(new Bomb(sf::Vector2f(186,38)));    //10
        bombs.push_back(new Bomb(sf::Vector2f(213,38)));    //11
        bombs.push_back(new Bomb(sf::Vector2f(240,38)));    //12

        bombs.push_back(new Bomb(sf::Vector2f(78,38)));     //13
        bombs.push_back(new Bomb(sf::Vector2f(51,38)));     //14
        bombs.push_back(new Bomb(sf::Vector2f(24,38)));     //15

        bombs.push_back(new Bomb(sf::Vector2f(24,185)));    //16
        bombs.push_back(new Bomb(sf::Vector2f(51,185)));    //17
        bombs.push_back(new Bomb(sf::Vector2f(78,185)));    //18

        bombs.push_back(new Bomb(sf::Vector2f(186,185)));   //19
        bombs.push_back(new Bomb(sf::Vector2f(213,185)));   //20
        bombs.push_back(new Bomb(sf::Vector2f(240,185)));   //21

        bombs.push_back(new Bomb(sf::Vector2f(159,143)));   //22
        bombs.push_back(new Bomb(sf::Vector2f(186,143)));   //23
        bombs.push_back(new Bomb(sf::Vector2f(213,143)));   //24

        break;
    case 5:
        file = "img/level_5_lines.png";

        nPlatforms = 0;

        bombs.push_back(new Bomb(sf::Vector2f(105,122)));   //1
        bombs.push_back(new Bomb(sf::Vector2f(105,143)));   //2
        bombs.push_back(new Bomb(sf::Vector2f(105,164)));   //3

        bombs.push_back(new Bomb(sf::Vector2f(51,38)));     //4
        bombs.push_back(new Bomb(sf::Vector2f(51,59)));     //5
        bombs.push_back(new Bomb(sf::Vector2f(51,80)));     //6

        bombs.push_back(new Bomb(sf::Vector2f(51,122)));    //7
        bombs.push_back(new Bomb(sf::Vector2f(51,143)));    //8
        bombs.push_back(new Bomb(sf::Vector2f(51,164)));    //9

        bombs.push_back(new Bomb(sf::Vector2f(159,122)));   //10
        bombs.push_back(new Bomb(sf::Vector2f(159,143)));   //11
        bombs.push_back(new Bomb(sf::Vector2f(159,164)));   //12

        bombs.push_back(new Bomb(sf::Vector2f(105,38)));    //13
        bombs.push_back(new Bomb(sf::Vector2f(105,59)));    //14
        bombs.push_back(new Bomb(sf::Vector2f(105,80)));    //15

        bombs.push_back(new Bomb(sf::Vector2f(213,38)));    //16
        bombs.push_back(new Bomb(sf::Vector2f(213,59)));    //17
        bombs.push_back(new Bomb(sf::Vector2f(213,80)));    //18

        bombs.push_back(new Bomb(sf::Vector2f(213,122)));   //19
        bombs.push_back(new Bomb(sf::Vector2f(213,143)));   //20
        bombs.push_back(new Bomb(sf::Vector2f(213,164)));   //21

        bombs.push_back(new Bomb(sf::Vector2f(159,38)));    //22
        bombs.push_back(new Bomb(sf::Vector2f(159,59)));    //23
        bombs.push_back(new Bomb(sf::Vector2f(159,80)));    //24

        break;
    }

    texture.loadFromFile(file);
    sprite = new sf::Sprite(texture);
}

Level::~Level()
{
    //dtor
}

bool Level::Update(float timeElapsed)
{
    player->Update(timeElapsed);

    for (int i = 0; i < enemies.size(); i++)
    {
        enemies.at(i)->Update(timeElapsed);
    }

    if (currentBomb != -1)
        bombs.at(currentBomb)->Update();

    if (bombs.empty())
    {
        return false;
    }

    return true;
}

void Level::Draw(float percentTick)
{
    // Clear screen
    engine->Clear();

    engine->Draw(*sprite);

    engine->DrawScores();



    for (int i = 0; i < bombs.size(); i++)
    {
        bombs[i]->Draw();
    }

    player->Draw(percentTick);

    for (int i = 0; i < enemies.size(); i++)
    {
        enemies.at(i)->Draw(percentTick);
    }

    for (int i = 0; i < nPlatforms; i++)
    {
        platforms[i]->Draw();
    }


    std::stringstream strs;
    strs << score;
    std::string temp_str = strs.str();
    char* char_type = (char*) temp_str.c_str();

    std::stringstream strs2;
    strs2 << multiplier;
    std::string temp_str2 = strs2.str();
    char* char_type2 = (char*) temp_str2.c_str();
    engine->Draw(char_type,char_type2);

    engine->Draw(lives);

    engine->Display();
}

void Level::HandleEvents()
{
    // Process events
    sf::Event event;
    while (engine->window.pollEvent(event))
    {
        // Close window : exit
        if (event.type == sf::Event::Closed)
            engine->window.close();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player->Walk(false);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player->Walk(true);
        else
            player->StopWalking();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            if (player->Jump())
                score += 2*multiplier;

    }

}

bool Level::IsOpen()
{
    return engine->window.isOpen();
}

int Level::CheckCollision(sf::Sprite* sprite)
{
    for (int i = 0; i < nPlatforms; i++)
    {
        int collision = platforms[i]->CheckCollision(sprite);
        //cout << "Colision con plataforma " << i << ": " << collision << endl;
        if (collision > 0)
            return collision;
    }
    return 0;
}

int Level::CheckBorder(sf::Sprite* sprite)
{
    for (int i = 0; i < nPlatforms; i++)
    {
        int border = platforms[i]->CheckBorder(sprite);
        if (border)
            return border;
    }
    return false;
}

void Level::TakeBomb(sf::Sprite* sprite)
{
    for (int i = 0; i < bombs.size(); i++)
    {
        if (bombs.at(i)->TakeBomb(sprite))
        {
            int score = 20;

            if (currentBomb != -1)
                if (currentBomb == i)
                    score *= 2;
                else if (i < currentBomb)
                    currentBomb--;

            std::stringstream strs;
            strs << score;
            std::string temp_str = strs.str();
            char* char_type = (char*) temp_str.c_str();
            GraphicsEngine::Instance()->AddScore(char_type, bombs.at(i)->GetPosition());

            bombs.erase(bombs.begin()+i);

            if (bombs.empty())
                currentBomb = -1;
            else
            {
                if (currentBomb == -1)
                    currentBomb = i;

                if (currentBomb >= bombs.size())
                    currentBomb = 0;

                bombs.at(currentBomb)->SetCurrent();
            }

            this->score += score*multiplier;
        }
    }
}

int Level::GetLevel()
{
    return level;
}

int Level::GetLives()
{
    return lives;
}

int Level::GetScore()
{
    return score;
}

void Level::SumScore(int score)
{
    this->score += score*multiplier;
}

void Level::AddEnemy(Character* enemy)
{
    enemies.push_back(enemy);
}

void Level::RemoveEnemy(Character* enemy)
{
    for (int i = 0; i < enemies.size(); i++)
    {
        if (enemies.at(i) == enemy)
        {
            //cout << "arma borrada" << endl;
            enemies.erase(enemies.begin()+i);
            break;
        }
    }
}

float Level::GetDistanceX(Character* enemy) {
    float xPosEnemy = enemy->GetPosition().x;
    float xPosPlayer = player->GetPosition().x;

    return xPosEnemy - xPosPlayer;
}

float Level::GetDistanceY(Character* enemy) {
    float yPosEnemy = enemy->GetPosition().y;
    float yPosPlayer = player->GetPosition().y;

    return yPosEnemy - yPosPlayer;
}

int Level::GetMovementDirection(Character* enemy)
{
    float xPosEnemy = enemy->GetPosition().x;
    float yPosEnemy = enemy->GetPosition().y;
    float xPosPlayer = player->GetPosition().x;
    float yPosPlayer = player->GetPosition().y;

    float xDistance = std::fabs(xPosEnemy - xPosPlayer);
    float yDistance = std::fabs(yPosEnemy - yPosPlayer);

    float minDistance = std::min(xDistance, yDistance);

    int result;

    if (minDistance == xDistance)
    {
        if (yPosEnemy > yPosPlayer)
            result = 1;
        else
            result = 3;
    }
    else
    {
        if (xPosEnemy < xPosPlayer)
            result = 2;
        else
            result = 4;
    }

    return result;
}
