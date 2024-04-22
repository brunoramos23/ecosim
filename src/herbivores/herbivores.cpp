#include "herbivores/herbivores.h"
#include <random>

Herbivores::Herbivores(uint32_t max_age, uint32_t reproduction_probability)
    : max_age_(max_age), reproduction_probability_(reproduction_probability) {}

void Herbivores::move(std::vector<std::vector<entity_t>> &entity_grid)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0, NUM_ROWS - 1);

    uint32_t i = dis(gen);
    uint32_t j = dis(gen);

    // Verifica se a célula está vazia
    if (entity_grid[new_i][new_j].type == empty)
    {
        // Atualiza a posição do herbívoro
        position_.i = new_i;
        position_.j = new_j;
    }
}

void Herbivores::eat(std::vector<std::vector<entity_t>> &entity_grid)
{
     std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0, NUM_ROWS - 1);

    uint32_t i = dis(gen);
    uint32_t j = dis(gen);

    // Verificar se a célula tem uma planta
    if (entity_grid[i][j].type == plants)
    {
        // Remove a planta da célula escolhida
        entity_grid[i][j] = {empty, 0, 0};
        // Aumenta a energia
        energy += 30;
        if (energy > MAXIMUM_ENERGY)
        {
            energy = MAXIMUM_ENERGY;
        }
    }
}

void Herbivores::reproduce(std::vector<std::vector<entity_t>> &entity_grid)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0, NUM_ROWS - 1);

    uint32_t i = dis(gen);
    uint32_t j = dis(gen);

    // Verificar se a célula escolhida está vazia
    if (entity_grid[i][j].type == empty && energy > THRESHOLD_ENERGY_FOR_REPRODUCTION)
    {
        // Criar uma nova instância de herbívoro na célula escolhida
        entity_grid[i][j] = {herbivores, 100, 0}; // Por exemplo, definir a energia inicial e idade do novo herbívoro
        // Reduzir a energia do herbívoro atual após a reprodução
        energy -= 10;
    }
}
