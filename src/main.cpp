#include "app.h"

const unsigned int width      = 900;  //px
const unsigned int height     = 900;  //px
const unsigned int cell_width = 6;    //px

int main() {
    life::app app(width / cell_width, height / cell_width, cell_width);
    app.run();
}