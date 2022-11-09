#pragma once

#include "gameObject.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"


class TextObject : public GameObject {
    private:
        sf::Font textFont;
        sf::Text text;
    public:
        TextObject(std::string identifier, sf::String textString);
        TextObject(const TextObject& other);
        ~TextObject() override;
        
    public:
        void update() override;
        void render(sf::RenderWindow& window) override;

        virtual void setPosition(sf::Vector2f position);
        void setText(sf::String newText, int size);
        void setColor(sf::Color color);
        const sf::Vector2f getPosition();
        sf::String getText() const;
        
};



