#include "Entity.hpp"
#include <random>

uint16_t Entity::GetAge()
{
    return m_Age;
}

void Entity::AdvanceAge()
{
    m_Age++;
}

uint32_t Entity::GetID()
{
    return m_ID;
}

pos_t Entity::GetCurrentPos()
{
    return m_CurrentPos;
}

bool Entity::RandomAction(float probability)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen) < probability;
}