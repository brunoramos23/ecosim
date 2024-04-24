#pragma once

#include <cstdint>
#include <cstdlib>

class Movable
{
public:
    virtual bool WillMove() = 0;
    virtual bool WillEat() = 0;
    virtual void FillEnergy(uint32_t energyBoost) = 0;
    uint32_t AdjacentCellSelection();
protected:
    static const uint16_t s_ReproductionCost;
    static const uint16_t s_ReproductionThreshold;
};