#pragma once

#include "Entity.hpp"

class Plant : public Entity
{
public:
    Plant(pos_t initialPos, uint32_t id);
    ~Plant();

    bool WillReproduce() override;
    bool TooOld() override;

    BoardSerializer Serialize() override;
private:
    static const uint16_t s_MaxAge;
    static const uint16_t s_ReproductionEnergy;
    static const float s_ReproductionProbability;
};