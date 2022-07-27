#pragma once
#include "PlacableActor.h"

class Player;

class Shopkeep : public PlacableActor
{
public:
	Shopkeep(int x, int y)
		: PlacableActor(x, y, ActorColor::RedOnWhite)
	{

	};

	virtual ActorType GetType() override { return ActorType::Shopkeep; }
	virtual void Draw() override;
};