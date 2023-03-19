#pragma once
#include "FuncBase.h"

class Player
{
	float health;
	float level;
	float damage = 5;
	float hunger;

public:

	Player(float health, float level, float hunger)
	{
		this->health = health;
		this->level = level;
		this->hunger = hunger;

	}

	void LowingHunger()
	{
		hunger = hunger - 0.1;
	}

	void StateHunger()
	{
		hunger = 0;
	}

	void LowingHealth(float howmuch)
	{
		health = health - howmuch;
	}

	float GetHealth()
	{
		return health;
	}

	float GetLevel()
	{
		return level;
	}

	float GetDamage()
	{
		return damage + health + level;
	}

	float GetHunger()
	{
		return hunger;
	}
};


