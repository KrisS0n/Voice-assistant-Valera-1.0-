#include "commandExecution.h"
#include "constantCommands.h"
#include <algorithm>

PerformingActions::PerformingActions() {
  textOfFile = gettingText(fileName);
  search(textOfFile);
}

std::string PerformingActions::gettingText(const std::string &filename) {
  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Ошибка: не удалось открыть файл!" << std::endl;
    return "";
  }

  file.seekg(0, std::ios::end);
  if (file.tellg() == 2) {
    std::cerr << "Ошибка: файл пустой!" << std::endl;
    file.close();
    return "";
  }

  file.seekg(0, std::ios::beg);

  std::string line;
  std::string fileContent;
  while (std::getline(file, line)) {
    fileContent += line + "\n";
    std::cout << line << std::endl;
  }

  file.close();

  if (std::remove(filename.c_str()) == 0) {
    std::cout << "Файл успешно удалён: " << std::endl;
  } else {
    std::cerr << "Ошибка: не удалось удалить файл " << std::endl;
  }

  return fileContent;
}

void PerformingActions::search(const std::string text) {
  Links links;
  if (text.find(openBrowser) != std::string::npos) {
    links.openBrowser();
  } else if (text.find(openYoutube) != std::string::npos) {
    links.openYouTube();
  } else if (text.find(findYoutube) != std::string::npos) {
    size_t pos = text.find(findYoutube);
    if (pos != std::string::npos) {
      std::string query = text.substr(pos + 14);
      links.openYouTubeWithSearch(query);
    }
  } else {
    std::cout << "Команда не распознана." << std::endl;
  }
}
