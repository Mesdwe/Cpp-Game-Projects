#pragma once
#include "Game.h"
class InputComponent
{
public:
	InputComponent();
	virtual ~InputComponent();
	virtual void Update(Paddle* paddle);
};

