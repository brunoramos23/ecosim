#pragma once

#include "Entity.hpp"
#include "Movable.hpp"

class Carnivore : public Entity, public Movable
{
public:
    Carnivore(pos_t initialPos, uint32_t id);
    ~Carnivore();

    bool WillMove() override;
    bool WillEat() override;
    void FillEnergy(uint32_t energyBoost) override;

    bool WillReproduce() override;
    bool TooOld() override;
    BoardSerializer Serialize() override;
private:
    static const uint16_t s_MaxAge;
    static const float s_ReproductionProbability;
    static const float s_MoveProbability;
    static const float s_EatProbability;
};