#include <SFML/Graphics.hpp>

#include <scene.hpp>
#include <spriteObject.hpp>
#include <sceneHandler.hpp>
#include <textObject.hpp>
#include <string>
//#include <button.hpp>



int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Alpha Project", sf::Style::Close);
    

    Scene scene1("scene01");

    
    TextObject exittext("exittext");
    exittext.setPosition(sf::Vector2f(window.getSize().x /2, window.getSize().y - 100));
    exittext.setText("Esc to exit");
    scene1.addGameObject(exittext);
    TextObject trialButton("trialbutton");
    trialButton.setPosition(sf::Vector2f(window.getSize().x -300, 10));
    trialButton.setText("Click Here");
    trialButton.setCharSize(30);
    scene1.addGameObject(trialButton);

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
            
            

        }
        window.clear();
        handler.update();
        handler.render(window);
        window.display();
    }

    return 0;
}





