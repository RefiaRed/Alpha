#include <button.hpp>





Button::Button(std::string identifier, sf::RenderWindow& window, float width, float height, bool active) : TextObject(identifier)
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
    bool b;
    if (isActive) {
        if(
        inHitbox(sf::Mouse::getPosition())
        //rect.getGlobalBounds().contains((sf::Vector2f) sf::Mouse::getPosition(window))
        )
            b = true;
        else
            b = false;
    }
    else
        b = false;

    return b;
    
}

bool Button::isClicked() {
    return isHovering() && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Button::inHitbox(sf::Vector2i point) {
    //I know GetGlobalBounds exists but it just didn't work for me correctly, so Idk
    //Positions are still scuffed but manually moved underneath the window
    
    bool b;
    
    //This didn't work:
    //int x1 = rect.getPosition().x * rect.getPosition().x * 2;
    //int x2 = (rect.getPosition().x * rect.getSize().x) / 5;
    //int y1 = rect.getPosition().y * rect.getPosition().y * 2;
    //int y2 = ((rect.getPosition().y * rect.getSize().y) *2 ) /6;

    int x1 = rect.getPosition().x + window.getPosition().x;
    int x2 = x1 + rect.getSize().x;
    int y1 = rect.getPosition().y * rect.getPosition().y + window.getPosition().y - 10;
    int y2 = y1 + rect.getSize().y ;

    if(x1 <= point.x)
        if(y1 <= point.y)
            if(x2 >= point.x)
                if(y2 >= point.y)
                    b = true;
         
    
    else 
         b= false;
    
    return b;
}