#ifndef VOICE_H
#define VOICE_H

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XTest.h>
#include <X11/keysym.h>
#include <chrono>
#include <cstdlib>
#include <curl/curl.h>
#include <iostream>
#include <thread>
#include <unistd.h>

class KeySimulator {
private:
  Display *display;

public:
  KeySimulator() {
    display = XOpenDisplay(nullptr);
    if (display == nullptr) {
      std::cerr << "Cannot open display" << std::endl;
      exit(1);
    }
  }

  ~KeySimulator() { XCloseDisplay(display); }

  void clickButton(KeySym keysym) {
    XTestFakeKeyEvent(display, XKeysymToKeycode(display, keysym), True,
                      CurrentTime);
    XFlush(display);
  }

  void releasingButton(KeySym keysym) {
    XTestFakeKeyEvent(display, XKeysymToKeycode(display, keysym), False,
                      CurrentTime);
    XFlush(display);
  }
};
class OpenBrowser {
private:
  const std::string url =
      "https://docs.google.com/document/d/"
      "1lmGLPCf6xnEH0aTa3uc-JzAt-1Kc1dU71l0HRok_oto/edit?tab=t.0";
  std::string command = "xdg-open " + url;
  int result = 0;

public:
  OpenBrowser() {
    result = system(command.c_str());

    if (result == 0) {
      std::cout << "Браузер открыт по ссылке: " << url << std::endl;
    } else {
      std::cerr << "Не удалось открыть браузер." << std::endl;
    }
  }
};

class LaunchinBrowser {
public:
  LaunchinBrowser() {
    OpenBrowser openBrowser;
    KeySimulator keySimulator;

    std::this_thread::sleep_for(std::chrono::milliseconds(4000));

    keySimulator.clickButton(XK_Shift_L);
    keySimulator.clickButton(XK_Control_L);
    keySimulator.clickButton(XK_s);
    keySimulator.releasingButton(XK_s);
    keySimulator.releasingButton(XK_Control_L);
    keySimulator.releasingButton(XK_Shift_L);

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    keySimulator.clickButton(XK_Alt_L);
    keySimulator.clickButton(XK_slash);
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    keySimulator.releasingButton(XK_Alt_L);
    keySimulator.releasingButton(XK_slash);

    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    keySimulator.clickButton(XK_t);
    keySimulator.releasingButton(XK_t);

    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    keySimulator.clickButton(XK_Return);
    keySimulator.releasingButton(XK_Return);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    keySimulator.clickButton(XK_Control_L);
    keySimulator.clickButton(XK_a);
    keySimulator.releasingButton(XK_a);
    keySimulator.releasingButton(XK_Control_L);

    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    keySimulator.clickButton(XK_Delete);
    keySimulator.releasingButton(XK_Delete);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    // system("pkill xdg-open ");
  }
};

#endif // !VOICE_H
