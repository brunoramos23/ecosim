#include <cstdint>
#ifndef ENTITY_H
#define ENTITY_H

enum entity_type_t
{
    empty,
    plant,
    herbivore,
    carnivore
};

struct entity_t
{
    entity_type_t type;
    int32_t energy;
    int32_t age;
};

#endif // ENTITY_H
