#pragma once

#include <cstdint>
#include <raylib.h>

namespace life {
    
    class board {
    public:
        board(uint32_t rows, uint32_t cols, uint32_t cell_size);
        ~board();

        void update();
        void render();

    private:
        // Returns number of neighbors of cell at (row, col).
        uint8_t eval_neighbors(uint32_t row, uint32_t col);
        
    private:
        uint32_t m_rows, m_cols;
        uint32_t m_cell_size;

        // Game state will be stored in a 2D buffer of 8-bit uints,
        // with 0 representing dead cells and 1 representing living cells.
        uint8_t** m_buffer;

        // State will be read from m_buffer and changes will be written to m_buffer_swap,
        // after which the two buffer pointers will be swapped.
        uint8_t** m_buffer_swap;
    };

}