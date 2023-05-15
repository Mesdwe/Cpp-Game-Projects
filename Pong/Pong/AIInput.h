#pragma once
#include "InputComponent.h"
class AIInput :public InputComponent
{
public:
	AIInput(Ball* ball);
	virtual ~AIInput();
	virtual void Update(Paddle* paddle) override;

private:
	float Predict(Paddle* paddle);

	

private:
	Ball* _ball;
	bool _hasPrediction = false;
	float _predictY = 0;
};

