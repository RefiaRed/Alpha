#pragma once

#include "textObject.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"


class Button : public TextObject {
    private:
        sf::Font font;
        sf::Text text;
    public:
        Button(std::string identifier);
        Button(const Button& other);
        ~Button();
        
    public:
        void isHover();
        
};



