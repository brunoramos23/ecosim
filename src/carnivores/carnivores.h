#ifndef CARNIVORES_H
#define CARNIVORES_H

#include "entity.h"
#include <vector>

struct pos_t
{
    uint32_t i;
    uint32_t j;
};

class Carnivores
{
public:
    Carnivores(uint32_t max_age, uint32_t reproduction_probability);

    void move(std::vector<std::vector<entity_t>> &entity_grid);
    void eat(std::vector<std::vector<entity_t>> &entity_grid);
    void reproduce(std::vector<std::vector<entity_t>> &entity_grid);

private:
    uint32_t max_age_;
    uint32_t reproduction_probability_;
};

#endif // CARNIVORES_H
