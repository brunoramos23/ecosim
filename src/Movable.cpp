#include "Movable.hpp"
#include <random>

const uint16_t Movable::s_ReproductionCost = 10;
const uint16_t Movable::s_ReproductionThreshold = 20;

uint32_t Movable::AdjacentCellSelection()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0,3);
    return dis(gen);
}

//colocar o custo da movimentação