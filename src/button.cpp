#include "button.hpp"

Button::Button(std::string identifier, sf::RenderWindow* window, float width, float height, bool active) : TextObject(identifier)
{
    isActive = active;

    this->window = window;

    //Box
    rect.setSize(sf::Vector2f(width,height));
    rect.setFillColor(boxColor);
    
    //Buttontext
    text.setFont(font);
    text.setCharacterSize(24);
    text.setString("Button");
}

Button::Button(const Button& other) : 
    TextObject(other.getIdentifier()) 
{
    //Box
    rect.setSize(sf::Vector2f(width,height));
    rect.setFillColor(boxColor);

    //Buttontext
    text.setFont(font);
    text.setCharacterSize(24);
    text.setString("Button\n");
}

Button::~Button() { };

void Button::update(){
    if (isHovering()){
         text.setFillColor(sf::Color::Cyan);
         rect.setFillColor(boxColorHov);
     }
     else{
         text.setFillColor(sf::Color::White);
        rect.setFillColor(boxColor);   
     }

     text.getString();

}

void Button::render(sf::RenderWindow& window) {
    window.draw(rect);
    window.draw(text);
}

void Button::setPosition(sf::Vector2f position) {
    rect.setPosition(position);
    text.setPosition((position.x + (rect.getSize().x/2)),(position.y + (rect.getSize().y* 0.2 )));
}        

void Button::setText(sf::String newtext) {
    text.setString(newtext);
}


bool Button::isHovering() {
        return rect.getGlobalBounds().contains((sf::Vector2f) sf::Mouse::getPosition(*this->window));
}

bool Button::isClicked() {
    return isHovering() && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

