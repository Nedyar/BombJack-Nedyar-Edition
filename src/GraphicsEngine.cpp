#include "GraphicsEngine.h"

GraphicsEngine* GraphicsEngine::instance = 0;

GraphicsEngine* GraphicsEngine::Instance()
{
    if (!instance)
        instance = new GraphicsEngine();
    return instance;
}

GraphicsEngine::GraphicsEngine()
{
    window.create(sf::VideoMode(WIDTH, HEIGHT), "BombJack - Nedyar Edition");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    texture.loadFromFile("img/HUB.png");
    sprite = new sf::Sprite(texture);

    font.loadFromFile("Starjedi.ttf");

    livesTexture.loadFromFile("img/SpriteSheet.png");
    livesSprite = new sf::Sprite(livesTexture);
    livesSprite->setTextureRect(sf::IntRect(4,4,15,15));
    livesSprite->setOrigin(livesSprite->getLocalBounds().width/2, livesSprite->getLocalBounds().height/2);
}

GraphicsEngine::~GraphicsEngine()
{
    delete instance;
}

void GraphicsEngine::Clear()
{
    window.clear(sf::Color(200,200,200,255));
    window.draw(*sprite);
}

void GraphicsEngine::Draw(sf::Sprite sprite)
{
    window.draw(sprite);
}

void GraphicsEngine::Draw(char* str, char* str2)
{
    sf::Text text;
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(9);
    text.setPosition(262,14);

    window.draw(text);


    sf::Text text2;
    text2.setFont(font);
    int tam = sizeof(str2)/sizeof(char);
    char* stri2 = new char[tam + 2];
    stri2[0] = 'x';
    stri2[1] = ' ';
    for (int i = 0; i < tam; i++)
        stri2[i+2] = str2[i];
    text2.setString(stri2);
    text2.setCharacterSize(7);
    text2.setPosition(283,27);
    text2.setColor(sf::Color::Red);

    window.draw(text2);
}

void GraphicsEngine::Draw(int lives)
{
    for (int i = 1; i < lives; i++) {
        livesSprite->setPosition(318-i*20,74);
        window.draw(*livesSprite);
    }
}

void GraphicsEngine::AddScore(char* score, sf::Vector2f position) {

    sf::Text text;
    text.setFont(font);
    text.setString(score);
    text.setCharacterSize(5);
    text.setPosition(position.x - 4, position.y - 3);

    scores.push_back(text);
    clocks.push_back(sf::Clock());
}

void GraphicsEngine::DrawScores() {
    for (int i = 0; i < scores.size(); i++) {
        window.draw(scores.at(i));
        if (clocks.at(i).getElapsedTime().asSeconds() >= 1) {
            scores.erase(scores.begin()+i);
            clocks.erase(clocks.begin()+i);
            i--;
        }
    }
}

void GraphicsEngine::Display()
{
    window.display();
}
