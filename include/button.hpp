#pragma once

#include "textObject.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Mouse.hpp"



class Button : public TextObject {
    private:
        sf::RectangleShape rect;
        sf::Font font;
        sf::Text text;
        sf::Color boxColor =  sf::Color(255, 0, 255, 100);
        sf::Color boxColorHov = sf::Color(255, 0, 255, 200);
        sf::Vector2f position;
        
    
        float width;
        float height;

        bool isActive = true;
        
    public:
        Button(std::string identifier, float width, float height, bool active);
        Button(const Button& other);
        ~Button();
        
    public:
        void update() override;
        void render(sf::RenderWindow& window) override;

        void setPosition(sf::Vector2f position);
        void setText(sf::String newtext);
        bool isHovering();
        bool isClicked();
        bool inHitbox(sf::Vector2i point);

        

};



