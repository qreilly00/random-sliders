#include "SliderGenerator.h"

SliderGenerator::SliderGenerator() {
    sliders_.resize(0);
    sliderValues_.resize(0);
    maxSliders_ = 0;
    maxHeight_ = 0;

    if(getUserInput()) {
        createSliders();
        displaySliders();
    } else 
        std::cout << "Input error. Letters found when numbers expected, value out of range or height of slider is 0." << std::endl;
    
}

void SliderGenerator::createSliders() {
    for(int i = 0; i < maxSliders_; i++) {
        sliders_.push_back(Slider(sliderValues_[i], maxHeight_));
    }
}

void SliderGenerator::displaySliders() {
    //std::string sliderString;

    // Print the [i] character of each slider, followed by a space, to print vertically.
    if(maxHeight_ != 0 && maxSliders_ != 0) {
        for(int i = maxHeight_ - 1; i >= 0; i--) {
            for(auto x : sliders_) {
                std::cout << x.getSliderAsString()[i] << " ";
            }

            std::cout << std::endl;
        }
    } /*else 
        std::cout << "Cannot print as the value of sliders or height is 0";*/
}

bool SliderGenerator::getUserInput() {
    std::string maxSliders;
    std::string maxHeight;
    std::string choice;

    std::string sliderValue;

    std::cout << "How many sliders are there?: ";
    std::cin >> maxSliders;
    //std::cin.clear();
    //std::cin.ignore(INT_MAX);
    std::cout << std::endl;

    // Check if the input string contains non numerical values. If none are found, convert to an int.
    if(!validUserInt(maxSliders))
        return 0;
    else 
        maxSliders_ = std::stoi(maxSliders); 

    std::cout << "How tall are the sliders?: ";
    std::cin >> maxHeight;
    //std::cin.clear();
    //std::cin.ignore(INT_MAX);
    std::cout << std::endl;

    if(!validUserInt(maxHeight))
        return 0;
    else 
        maxHeight_ = std::stoi(maxHeight); 

    std::cout << "Whould you like me to generate some numbers for you?: ";
    std::cin >> choice;
    //std::cin.clear();
    //std::cin.ignore(INT_MAX);
    std::cout << std::endl;

    if(choice == "y" || choice == "Y" || 
        choice == "yes" || choice == "yEs" || choice == "yES" || choice == "yeS" || 
        choice == "Yes" || choice == "YEs" || choice == "YES" || choice == "YeS" ) {
        for(int i = 0; i < maxSliders_; i++) {
            sliderValues_.push_back(getRandomInt(1, maxHeight_));
        }
    } else {
        for(int i = 0; i < maxSliders_; i++) {
            std::cout << "Please enter value " << i << ": ";
            std::cin >> sliderValue;
            //std::cin.clear();
            //std::cin.ignore(INT_MAX);
            std::cout << std::endl;

            if(!validUserInt(sliderValue) || !rangeUserInt(sliderValue))
                return 0;
            else 
                 sliderValues_.push_back(std::stoi(sliderValue)); 
        }
    }

    

    return 1;
}

/*bool SliderGenerator::checkUserInt(std::string input) {
    if(validUserInt(input) == 1 && rangeUserInt(input) == 1)
        return 1;
    return 0;
}*/

bool SliderGenerator::validUserInt(std::string input) {
    int counter = 0;

    for(int i = 0; i < input.size(); i++) {
        if(input[i] >= '0' && input[i] <= '9') {
            counter++;
        }
    }

    if(counter == input.size()) 
        return 1;
    return 0;
}

bool SliderGenerator::rangeUserInt(std::string input) {
    int value = std::stoi(input);

    if(value > 0 && value <= maxHeight_)
        return 1;
    return 0;
}

int SliderGenerator::getRandomInt(int x, int y) {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(x, y);

    return distribution(generator);
}

void SliderGenerator::setSliderValues(std::vector<int> sliderValues) {
    sliderValues_ = sliderValues;
}

void SliderGenerator::setMaxSliders(int maxSliders) {
    maxSliders_ = maxSliders;
}

void SliderGenerator::setMaxHeight(int maxHeight) {
    maxHeight_ = maxHeight;
}
    
std::vector<int> SliderGenerator::getSliderValues() {
    return sliderValues_;
}

int SliderGenerator::getMaxSliders() {
    return maxSliders_;
}

int SliderGenerator::getMaxHeight() {
    return maxHeight_;
}