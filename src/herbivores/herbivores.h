#ifndef HERBIVORES_H
#define HERBIVORES_H

#include "entity.h"
#include <vector>
#include <position.h>

class Herbivores
{
public:
    Herbivores(uint32_t max_age, uint32_t reproduction_probability);

    void move(std::vector<std::vector<entity_t>> &entity_grid);
    void eat(std::vector<std::vector<entity_t>> &entity_grid);
    void reproduce(std::vector<std::vector<entity_t>> &entity_grid);

private:
    uint32_t max_age_;
    uint32_t reproduction_probability_;
    Position position_;
};

#endif // HERBIVORES_H
