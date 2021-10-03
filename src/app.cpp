#include "app.h"


namespace life {
    app::app(uint8_t rows, uint8_t cols, uint32_t cell_size) 
        : m_board(rows, cols, cell_size)
    {
        InitWindow(rows * cell_size, cols * cell_size, "Game of Life");
        SetTargetFPS(60);
    }

    app::~app() {
        CloseWindow();
    }

    void app::run() {
        while (!WindowShouldClose()) {
            update();

            BeginDrawing();
                render();
            EndDrawing();
        }
    }

    void app::update() {
        m_board.update();
    }

    void app::render() {
        ClearBackground(BLACK);
        m_board.render();
    }
}