#ifndef TEXTCONVERSION_H
#define TEXTCONVERSION_H

#include <codecvt>
#include <cwctype>
#include <fstream>
#include <iostream>
#include <istream>
#include <locale>
#include <string>

class TextConversion {
private:
  const std::wstring fileNameDesigner = L"../../../Загрузки/Новый документ.txt";
  const std::string fileNameFunction = "../../../Загрузки/Новый документ.txt";
  const std::string language = "ru_RU.UTF-8";
  std::wstring content;
  std::wstring line;
  std::wstring processedText;

public:
  TextConversion() {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");

    std::wstring content = openFile(fileNameDesigner);
    if (content.empty()) {
      return;
    }

    processedText = processText(content);

    writeFile(fileNameDesigner, processedText);
  }

  std::wstring openFile(const std::wstring &filename) {
    std::wifstream file(fileNameFunction);
    if (!file) {
      std::wcerr << L"Не удалось открыть файл!" << std::endl;
      return nullptr;
    }
    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));
    while (std::getline(file, line)) {
      content += line + L'\n';
    }
    file.close();

    return content;
  }

  std::wstring processText(const std::wstring &text) {
    std::wstring processedText;
    for (wchar_t c : text) {
      c = std::tolower(c, std::locale(language));
      if (!std::iswpunct(c)) {
        processedText += c;
      } else {
        processedText += L' ';
      }
    }
    return processedText;
  }

  void writeFile(const std::wstring &filename, const std::wstring &text) {
    std::wofstream file(fileNameFunction);
    if (!file.is_open()) {
      std::wcerr << L"Не удалось открыть файл для записи!" << std::endl;
      return;
    }

    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));

    file << text;
    file.close();

    std::wcout << L"Текст успешно записан в файл: " << filename << std::endl;
  }
};

#endif // !TEXTCONVERSION_H
