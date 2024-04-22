#include "plants.h"
#include <random>

Plant::Plant(uint32_t max_age, uint32_t reproduction_probability)
    : max_age_(max_age), reproduction_probability_(reproduction_probability) {}

void Plant::grow(std::vector<std::vector<entity_t>> &entity_grid)
{
    // Implementar a lógica de crescimento da planta aqui
    // Exemplo: escolher uma célula vazia adjacente aleatoriamente e colocar uma nova planta
}
