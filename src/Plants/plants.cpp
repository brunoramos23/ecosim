#include "Plants/plants.h"
#include <random>

Plant::Plant(uint32_t max_age, uint32_t reproduction_probability)
    : max_age_(max_age), reproduction_probability_(reproduction_probability) {}

void Plant::grow(std::vector<std::vector<entity_t>> &entity_grid, uint32_t NUM_ROWS)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0, NUM_ROWS - 1);

    uint32_t i = dis(gen);
    uint32_t j = dis(gen);

    // Verificar se a célula escolhida está vazia
    if (entity_grid[i][j].type == empty)
    {
        entity_grid[i][j] = {plant, 0, 0};
    }
}
