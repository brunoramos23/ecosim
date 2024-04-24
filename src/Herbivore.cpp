#include "Herbivore.hpp"

#include "Herbivore.hpp"

const uint16_t Herbivore::s_MaxAge = 50;
const float Herbivore::s_ReproductionProbability = .025;
const float Herbivore::s_MoveProbability = 0.5;
const float Herbivore::s_EatProbability = 1.0;

Herbivore::Herbivore(pos_t initialPos, uint32_t id)
{
    m_CurrentPos = initialPos;
    m_Age = 0;
    m_ID = id;
    m_Energy = 100;
}

Herbivore::~Herbivore()
{
    
}

bool Herbivore::WillMove()
{
    return RandomAction(s_MoveProbability);
}

bool Herbivore::WillEat()
{
    return true;
}

void Herbivore::FillEnergy(uint32_t energyBoost)
{
    m_Energy += energyBoost;
}

bool Herbivore::WillReproduce()
{
    return RandomAction(s_ReproductionProbability);
}

bool Herbivore::TooOld()
{
    return (m_Age > s_MaxAge);
}

BoardSerializer Herbivore::Serialize()
{
    BoardSerializer b = {entity_type_t::herbivore, m_Energy, m_Age};
    return b;
}