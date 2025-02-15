#ifndef SOUNDSFORACTION_H
#define SOUNDSFORACTION_H

#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <iostream>
#include <random>
#include <string>

// Приветские
const std::string soundGreeting_1 =
    "../music/zvonok-osoboy-gosudarstvennoy-vajnosti.mp3";
const std::string soundGreeting_2 = "../music/utro-dobroe.mp3";

// Если нету текста
const std::string noText_1 = "../music/tishina-nu-ka-prosnulis.mp3";

// Если нельзя выполнить действие
const std::string cannotPerformed_1 =
    "../music/nepravilno-poprobuy-esch-raz.mp3";
const std::string cannotPerformed_2 = "../music/davai-po-novoi-misha.mp3";

// Если можно выполнить
const std::string canPerform_1 = "../music/ne-urchi-seychas-razberemsya.mp3";

class Randomizer {
private:
  std::mt19937 generator;

public:
  Randomizer() : generator(std::random_device{}()) {}

  int getRandomNumber(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
  }
};

class Greeting {
private:
  sf::SoundBuffer buffer1;
  sf::SoundBuffer buffer2;
  sf::Sound sound1;
  sf::Sound sound2;
  int choice = 0;

public:
  void playAudio() {
    Randomizer randomizer;
    choice = randomizer.getRandomNumber(0, 1);
    if (choice == 0) {
      sound1.play();
    } else if (choice == 1) {
      sound2.play();
    } else {
      std::cerr << "Ошибка! Я не смог найти число от 0 до 1." << std::endl;
    }

    while (sound1.getStatus() == sf::Sound::Playing ||
           sound2.getStatus() == sf::Sound::Playing) {
      sf::sleep(sf::milliseconds(100));
    }
  }

  Greeting() {
    if (!buffer1.loadFromFile(soundGreeting_1)) {
      std::cerr << "Ошибка! Неправельное название файла: " << soundGreeting_1
                << std::endl;
      throw std::runtime_error("Failed to load audio file 1");
    }

    if (!buffer2.loadFromFile(soundGreeting_2)) {
      std::cerr << "Ошибка! Неправельное название файла: " << soundGreeting_2
                << std::endl;
      throw std::runtime_error("Failed to load audio file 2");
    }

    sound1.setBuffer(buffer1);
    sound2.setBuffer(buffer2);

    playAudio();
  }
};

class NoText {
private:
  sf::SoundBuffer buffer1;
  sf::Sound sound1;
  int choice = 0;

public:
  void playAudio() {
    Randomizer randomizer;
    choice = randomizer.getRandomNumber(0, 0);
    if (choice == 0) {
      sound1.play();
    } else {
      std::cerr << "Ошибка! Я не смог найти число 0." << std::endl;
    }

    while (sound1.getStatus() == sf::Sound::Playing) {
      sf::sleep(sf::milliseconds(100));
    }
  }

  NoText() {
    if (!buffer1.loadFromFile(noText_1)) {
      std::cerr << "Ошибка! Неправельное название файла: " << noText_1
                << std::endl;
      throw std::runtime_error("Failed to load audio file 1");
    }
    sound1.setBuffer(buffer1);

    playAudio();
  }
};

class CannotPerformed {
private:
  sf::SoundBuffer buffer1;
  sf::SoundBuffer buffer2;
  sf::Sound sound1;
  sf::Sound sound2;
  int choice = 0;

public:
  void playAudioCP() {
    Randomizer randomizer;
    choice = randomizer.getRandomNumber(0, 1);
    if (choice == 0) {
      sound1.play();
    } else if (choice == 1) {
      sound2.play();
    } else {
      std::cerr << "Ошибка! Я не смог найти число от 0 до 1." << std::endl;
    }

    while (sound1.getStatus() == sf::Sound::Playing ||
           sound2.getStatus() == sf::Sound::Playing) {
      sf::sleep(sf::milliseconds(100));
    }
  }

  CannotPerformed() {
    if (!buffer1.loadFromFile(cannotPerformed_1)) {
      std::cerr << "Ошибка! Неправельное название файла: " << cannotPerformed_1
                << std::endl;
      throw std::runtime_error("Failed to load audio file 1");
    }

    if (!buffer2.loadFromFile(cannotPerformed_2)) {
      std::cerr << "Ошибка! Неправельное название файла: " << cannotPerformed_2
                << std::endl;
      throw std::runtime_error("Failed to load audio file 2");
    }

    sound1.setBuffer(buffer1);
    sound2.setBuffer(buffer2);

    playAudioCP();
  }
};

class CanPerform {
private:
  sf::SoundBuffer buffer1;
  sf::Sound sound1;
  int choice = 0;

public:
  void playAudio() {
    Randomizer randomizer;
    choice = randomizer.getRandomNumber(0, 0);
    if (choice == 0) {
      sound1.play();
    } else {
      std::cerr << "Ошибка! Я не смог найти число 0." << std::endl;
    }

    while (sound1.getStatus() == sf::Sound::Playing) {
      sf::sleep(sf::milliseconds(100));
    }
  }

  CanPerform() {
    if (!buffer1.loadFromFile(canPerform_1)) {
      std::cerr << "Ошибка! Неправельное название файла: " << canPerform_1
                << std::endl;
      throw std::runtime_error("Failed to load audio file 1");
    }
    sound1.setBuffer(buffer1);

    playAudio();
  }
};

#endif // SOUNDSFORACTION_H
