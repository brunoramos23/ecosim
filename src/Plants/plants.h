#ifndef PLANTS_H
#define PLANTS_H

#include "entity.h"
#include <vector>

struct pos_t
{
    uint32_t i;
    uint32_t j;
};

class Plant
{
public:
    Plant(uint32_t max_age, uint32_t reproduction_probability);

    void grow(std::vector<std::vector<entity_t>> &entity_grid);

private:
    uint32_t max_age_;
    uint32_t reproduction_probability_;
};

#endif // PLANTS_H
