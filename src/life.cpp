#include "life.h"

namespace life {
    board::board(uint32_t rows, uint32_t cols, uint32_t cell_size)
        : m_rows(rows), m_cols(cols), m_cell_size(cell_size)
    {
        m_buffer = new uint8_t*[m_rows];
        m_buffer_swap = new uint8_t*[m_rows];
        for (uint32_t i = 0; i < m_rows; ++i) {
            m_buffer[i] = new uint8_t[m_cols];
            m_buffer_swap[i] = new uint8_t[m_cols];

            for (uint32_t j = 0; j < m_cols; ++j)
                m_buffer[i][j] = GetRandomValue(0, 1);
        }
    }

    board::~board() {
        for (uint32_t i = 0; i < m_rows; ++i) {
            delete[] m_buffer[i];
        }
        delete[] m_buffer;
    }

    uint8_t board::eval_neighbors(uint32_t row, uint32_t col) {
        uint8_t neighbors = 0;
        for (int8_t i = -1; i < 2; ++i) {
            for (int8_t j = -1; j < 2; ++j) {
                // The expression (m_rows + row + i) % m_rows wraps around when checking neigbors of cells on the edge.
                neighbors += m_buffer[(m_rows + row + i) % m_rows][(m_cols + col + j) % m_cols];
            }
        }
        return neighbors - m_buffer[row][col];
    }

    void board::update() {
        for (uint32_t i = 0; i < m_rows; ++i) {
            for (uint32_t j = 0; j < m_cols; ++j) {
                uint8_t cell = m_buffer[i][j];
                uint8_t neighbors = eval_neighbors(i, j);

                if (cell == 0 && neighbors == 3)
                    m_buffer_swap[i][j] = 1;
                else if (cell == 1 && (neighbors < 2 || neighbors > 3))
                    m_buffer_swap[i][j] = 0;
                else
                    m_buffer_swap[i][j] = cell;
            }
        }

        uint8_t** temp = m_buffer;
        m_buffer = m_buffer_swap;
        m_buffer_swap = temp;
    }

    void board::render() {
        for (uint32_t i = 0; i < m_rows; ++i) {
            for (uint32_t j = 0; j < m_cols; ++j) {
                if (m_buffer[i][j] == 1)
                    DrawRectangle(i * m_cell_size, j * m_cell_size, m_cell_size, m_cell_size, RAYWHITE);
            }
        }
    }
}