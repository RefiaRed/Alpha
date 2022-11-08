#include <SFML/Graphics.hpp>
#include <iostream>

#include <scene.hpp>
#include <spriteObject.hpp>
#include <sceneHandler.hpp>
#include <textObject.hpp>
#include <string>
#include <button.hpp>

sf::Vector2f mousepos;



int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Alpha Project", sf::Style::Close);
    window.setPosition(sf::Vector2i(0,0));

    Scene scene1("scene01");

    TextObject here("here");
    here.setPosition(sf::Vector2f(10.0f, 10.0f));
    here.setCharSize(30);
    here.setText("O");
    scene1.addGameObject(here);
    
    TextObject exittext("exittext");
    exittext.setPosition(sf::Vector2f(window.getSize().x /2, window.getSize().y - 100));
    exittext.setText("Esc to exit");
    scene1.addGameObject(exittext);
    Button trialButton("trialbutton", window, 200.0f, 100.0f, true);
    trialButton.setPosition(sf::Vector2f(300, 300));
    trialButton.setCharSize(30);
    trialButton.setText("Click Here");
    scene1.addGameObject(trialButton);

    Button trialButton2("trialbutton2", window, 200.0f, 100.0f, true);
    trialButton2.setPosition(sf::Vector2f(10,10));
    trialButton2.setText("Trial Button 2");
    scene1.addGameObject(trialButton2);


    //Start scene 2 (but it's useless)
    Scene scene2("scene02");

    SpriteObject sprite1("soldierSprite", "assets/head.png");
    sprite1.setPosition(sf::Vector2f(70.0f, 70.0f));
    sprite1.setScale(sf::Vector2f(5.0f, 5.0f));
    scene2.addGameObject(sprite1);
    SpriteObject sprite2("soldierSprite", "assets/head_hurt.png");
    sprite2.setPosition(sf::Vector2f(170.0f, 170.0f));
    sprite2.setScale(sf::Vector2f(5.0f, 5.0f));
    scene2.addGameObject(sprite2);
    

    TextObject testingtext("testtext");
    scene2.addGameObject(testingtext); 
    
    


    SceneHandler handler;
    handler.addScene(scene1);
    handler.addScene(scene2);
    



    int counter = 0;
    while (window.isOpen()) {
        mousepos= (sf::Vector2f) sf::Mouse::getPosition();
        
        //check for Events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::A) {
                    if (counter == 0) {
                        handler.stackScene("scene02");
                        counter++;
                    } else {
                        handler.popScene();
                        counter--;
                    }
                }
                if (event.key.code == sf::Keyboard::Escape){
                    window.close();
                }
                
                
            }   
            here.setPosition((sf::Vector2f) sf::Mouse::getPosition(window));

            if (trialButton2.isClicked()){
                    window.close();
            }
                
            if (trialButton.isClicked()){
                    window.close();
            }

        }
        
        

        window.clear();
        handler.update();
        handler.render(window);
        window.display();
    }

    return 0;
}





