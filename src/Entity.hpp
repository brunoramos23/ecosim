#pragma once

#include <cstdint>
#include <cstdlib>

struct pos_t
{
    uint16_t i;
    uint16_t j;
};

enum entity_type_t
{
    empty,
    plant,
    herbivore,
    carnivore
};

struct BoardSerializer
{
    entity_type_t type;
    uint16_t energy;
    uint16_t age;
};

class Entity
{
public:
    uint16_t GetAge();
    void AdvanceAge();

    virtual bool WillReproduce() = 0;
    
    uint32_t GetID();

    virtual bool TooOld() = 0;

    pos_t GetCurrentPos();

    virtual BoardSerializer Serialize() = 0;
protected:
    bool RandomAction(float probability);

    pos_t m_CurrentPos;
    uint16_t m_Age;
    //uint16_t m_MaxAge;
    uint16_t m_Energy;
    uint32_t m_ID;
    //uint16_t m_ReproductionEnergy;
    //float m_ReproductionProbability;
};