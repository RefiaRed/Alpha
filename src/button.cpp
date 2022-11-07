#include <button.hpp>





Button::Button(std::string identifier, float width, float height, bool active) : TextObject(identifier)
{
    
    isActive = active;

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
    bool b;
    if (isActive) {
        inHitbox(sf::Mouse::getPosition());
        //rect.getGlobalBounds().contains((sf::Vector2f) sf::Mouse::getPosition(&window));
         b =true;
    }
    else
        b = false;

    return b;
    
}

bool Button::isClicked() {
    return isHovering() && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Button::inHitbox(sf::Vector2i point) {
    //I know GetGlobalBounds exists but it just didn't work for me correctly, so I tried building my own
    
    bool b;
    
    int x1 = rect.getPosition().x;
    int x2 = rect.getPosition().x + rect.getSize().x;
    int y1 = rect.getPosition().y;
    int y2 = rect.getPosition().y + rect.getSize().y;

    if(x1 <= point.x <= x2){
        if(y1 <= point.y <= y2)
         b = true;
    }
    else {
         b= false;
    }
    return b;
}