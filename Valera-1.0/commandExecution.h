#ifndef COMMANDEXECUTION_H
#define COMMANDEXECUTION_H

#include <cstdio>
#include <filesystem>
#include <fstream>

#include "constantCommands.h"
#include "soundsForAction.h"

class PerformingActions {
private:
  const std::string fileName = "../../../Загрузки/Новый документ.txt";
  std::string textOfFile;

public:
  PerformingActions();
  std::string gettingText(const std::string &filename);
  void search(const std::string text);
};

class Links {
private:
  const std::string Browser = "https://www.google.com";
  const std::string YouTube = "https://www.youtube.com";
  const std::string YouTubeWithSearch =
      "https://www.youtube.com/results?search_query=";

public:
  void openBrowser() {
    std::string url = Browser;
    system(("xdg-open " + url).c_str());
  }

  void openYouTube() {
    std::string url = YouTube;
    system(("xdg-open " + url).c_str());
  }

  void openYouTubeWithSearch(const std::string &query) {
    std::string url = YouTubeWithSearch + query;
    system(("xdg-open " + url).c_str());
  }
};

#endif // !COMMANDEXECUTION_H
