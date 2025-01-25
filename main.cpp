#include <iostream>
#include <sstream>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "libraries/badger2040/badger2040.hpp"

using namespace std;
using namespace pimoroni;

Badger2040 display;

string location = "Somewhere on Earth";
string temperature = "??";
string humidity = "??";

void render() {
    display.pen(15);
    display.clear();
    display.pen(0);

    display.font("bitmap14_outline");
    display.text("Paul is:", 10, 0, 3.0f);

    display.font("bitmap8");
    display.text(location, 10, 50, 2.0f);

    display.rectangle(0, 110, 296, 28);
    display.pen(15);

    ostringstream office;
    office << "Office is " << temperature << " C, " << humidity << "% RH";
    display.text(office.str(), 10, 116, 0.5f);

    display.update();
}

int main() {
    stdio_init_all();

    sleep_ms(500);

    display.init();
    display.update_speed(1);

    render();

    while(true) {
        string input;
        getline(cin, input);

        string last_location = location;
        string last_temperature = temperature;
        string last_humidity = humidity;

        if (input.rfind("LOC ", 0) == 0)
            location = input.substr(4);

        if (input.rfind("TH ", 0) == 0)
            sscanf(input.data(), "TH %2s %2s", temperature.data(), humidity.data());

        if (last_location != location || last_temperature != temperature || last_humidity != humidity)
            render();
    }
}
