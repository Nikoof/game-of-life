#pragma once

#include <raylib.h>
#include "life.h"

namespace life {

    class app {
    public:
        app(uint8_t rows, uint8_t cols, uint32_t cell_size);
        ~app();

        void run();

    private:
        void update();
        void render();

    private:
        life::board m_board;
    };

}
