/*

  Main function. Loads up the different screens and manages them.
  This is also where sf::RenderWindow is defined.

*/

#include "include.hpp"
#include "screens/screens.hpp"
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include "gui/sound.hpp"



int main() {
  srand(time(NULL)); //Pick a seed


  std::cout << sf::IpAddress::getPublicAddress();

  gui::Sound::init();

  std::vector<CScreen *> screens;
  int screen = 0;
  sf::RenderWindow window(sf::VideoMode(WorldMap::width, WorldMap::height), "Game");

  ScreenMainMenu s0;
  screens.push_back(&s0);

  ScreenGame s1;
  screens.push_back(&s1);
 

  sf::Music music;
  if (!music.openFromFile("resources/song.wav"))
    return -1; // error
  music.setLoop(true);
  music.setVolume(25);
  music.play();

  //The screen class returns an int, which tells which Screen (mainmenu, game) to run
  while (screen >= 0) {
    screen = screens[screen]->run(window);
  }

  return 0;
}
