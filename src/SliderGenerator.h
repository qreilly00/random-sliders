#ifndef SLIDERGENERATOR_H
#define SLIDERGENERATOR_H

#include <iostream>
#include <string>
#include <vector>
#include<random>

#include "Slider.h"

class SliderGenerator {
private:

    std::vector<Slider> sliders_;
    std::vector<int> sliderValues_;
    int maxSliders_;
    int maxHeight_;

public:

    SliderGenerator();

    void createSliders();
    void displaySliders();

    bool getUserInput();

    //bool checkUserInt(std::string);
    bool validUserInt(std::string);
    bool rangeUserInt(std::string);

    int getRandomInt(int x, int y);

    void setSliderValues(std::vector<int> sliderValues);
    void setMaxSliders(int maxSliders);
    void setMaxHeight(int maxHeight);

    std::vector<int> getSliderValues();
    int getMaxSliders();
    int getMaxHeight();
};

#endif