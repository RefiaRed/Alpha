#include <button.hpp>

Button::Button(std::string identifier) : TextObject(identifier)
{
    text.setFont(font);
    text.setCharacterSize(24);
    text.setString("Button\n");
}

Button::Button(const Button& other) : 
    TextObject(other.getIdentifier()) 
{
    text.setFont(font);
    text.setCharacterSize(24);
    text.setString("Button\n");
}

void Button::isHover(){
    text.setFillColor(sf::Color::Cyan);
}


