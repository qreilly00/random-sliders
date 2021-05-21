#ifndef SLIDER_H
#define SLIDER_H

#include <iostream>
#include <string>

class Slider {
private:

    int sliderValue_;
    int maxHeight_;

public:

    Slider();
    Slider(int, int);

    std::string getSliderAsString();

    void setSliderValue(int sliderValue);
    void setMaxHeight(int maxHeight);

    int getSliderValue();
    int getMaxHeight();
};

#endif