#include "Plant.hpp"

const uint16_t Plant::s_MaxAge = 10;
const uint16_t Plant::s_ReproductionEnergy = 0;
const float Plant::s_ReproductionProbability = .2;

Plant::Plant(pos_t initialPos, uint32_t id)
{
    m_CurrentPos = initialPos;
    m_Age = 0;
    m_ID = id;
}

Plant::~Plant()
{}

bool Plant::TooOld()
{
    return (m_Age > s_MaxAge);
}

bool Plant::WillReproduce()
{
    return RandomAction(s_ReproductionProbability);
}

BoardSerializer Plant::Serialize()
{
    BoardSerializer b = {entity_type_t::plant, m_Energy, m_Age};
    return b;
}