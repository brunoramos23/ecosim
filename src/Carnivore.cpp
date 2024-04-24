#include "Carnivore.hpp"

const uint16_t Carnivore::s_MaxAge = 80;
const float Carnivore::s_ReproductionProbability = .025;
const float Carnivore::s_MoveProbability = 0.5;
const float Carnivore::s_EatProbability = 1.0;

Carnivore::Carnivore(pos_t initialPos, uint32_t id)
{
    m_CurrentPos = initialPos;
    m_Age = 0;
    m_ID = id;
    m_Energy = 100;
}

Carnivore::~Carnivore()
{
    
}

bool Carnivore::WillMove()
{
    return RandomAction(s_MoveProbability);
}

bool Carnivore::WillEat()
{
    return true;
}

void Carnivore::FillEnergy(uint32_t energyBoost)
{
    m_Energy += energyBoost;
}

bool Carnivore::WillReproduce()
{
    return RandomAction(s_ReproductionProbability);
}

bool Carnivore::TooOld()
{
    return (m_Age > s_MaxAge);
}

BoardSerializer Carnivore::Serialize()
{
    BoardSerializer b = {entity_type_t::carnivore, m_Energy, m_Age};
    return b;
}