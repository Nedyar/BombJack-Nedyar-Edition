#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include <SFML/Graphics.hpp>
#include <string>

const int WIDTH = 320;
const int HEIGHT = 200;

class GraphicsEngine
{
public:
    static GraphicsEngine* Instance();
    virtual ~GraphicsEngine();

    void Draw(sf::Sprite sprite);
    void Draw(char* score, char* multiplier);
    void Draw(int lives);
    void DrawScores();
    void Display();
    void Clear();

    void AddScore(char* score, sf::Vector2f position);

    sf::RenderWindow window;

protected:
    GraphicsEngine();
    GraphicsEngine(const GraphicsEngine&);
    GraphicsEngine &operator= (const GraphicsEngine&);
private:
    static GraphicsEngine* instance;

    //HUB
    sf::Sprite* sprite;
    sf::Texture texture;
    sf::Font font;
    sf::Sprite* livesSprite;
    sf::Texture livesTexture;
    std::vector<sf::Text> scores;
    std::vector<sf::Clock> clocks;
};

#endif // GRAPHICSENGINE_H
