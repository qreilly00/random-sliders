#include "Slider.h"

Slider::Slider() {
    sliderValue_ = 0;
    maxHeight_ = 0;
}

Slider::Slider(int sliderValue, int maxHeight) {
    sliderValue_ = sliderValue;
    maxHeight_ = maxHeight;
}

std::string Slider::getSliderAsString() {
    std::string answer = "";

    if(maxHeight_ != 0) {
        for(int i = 0; i < maxHeight_; i++) {
            if(i == sliderValue_ - 1) {
                answer += "#";
            } else {
                answer += "|";
            }
        }
    }

    return answer;
}

void Slider::setSliderValue(int sliderValue) {
    sliderValue_ = sliderValue;
}

void Slider::setMaxHeight(int maxHeight) {
    maxHeight_ = maxHeight;
}

int Slider::getSliderValue() {
    return sliderValue_;
}

int Slider::getMaxHeight() {
    return maxHeight_;
}