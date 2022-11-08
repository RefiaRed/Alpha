#include "button.hpp"

Button::Button(std::string identifier, sf::RenderWindow* window, float width, float height, bool active) : TextObject(identifier), text(text)
{
    isActive = active;

    this->window = window;
    this->font = font;
    

    //Box
    rect.setSize(sf::Vector2f(width,height));
    rect.setFillColor(boxColor);
    rect.setPosition(0,0);

    
    //Buttontext
    text.setText(".", 25);
    text.setPosition(sf::Vector2f(0,0));

}

Button::Button(const Button& other) : 
    TextObject(other), text(text)
{   
    this->window = window;
    this->font = font;

    //Box
    rect.setSize(sf::Vector2f(width,height));
    rect.setFillColor(boxColor);

    //Buttontext

}

Button::~Button() { };

void Button::update(){
    if (isHovering()){
         text.setColor(sf::Color::Cyan);
         rect.setFillColor(boxColorHov);
     }
     else{
         text.setColor(sf::Color::White);
        rect.setFillColor(boxColor);   
     }

     text;

}

void Button::render(sf::RenderWindow& window) {
    window.draw(rect);
    TextObject::render(window);
    //window.draw(text);
}

void Button::setPosition(sf::Vector2f position) {
    rect.setPosition(position);
    text.setPosition(position);
}        




bool Button::isHovering() {
        return rect.getGlobalBounds().contains((sf::Vector2f) sf::Mouse::getPosition(*this->window));
}

bool Button::isClicked() {
    return isHovering() && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

