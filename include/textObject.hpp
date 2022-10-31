#pragma once

#include "gameObject.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"


class TextObject : public GameObject {
    private:
        sf::Font font;
        sf::Text text;
    public:
        TextObject(std::string identifier);
        TextObject(const TextObject& other);
        ~TextObject();
        
    public:
        void update() override;
        void render(sf::RenderWindow& window) override;
        
        void setPosition(sf::Vector2f position);
        void setCharSize(int size);
        void setText(sf::String newtext);
        
};



