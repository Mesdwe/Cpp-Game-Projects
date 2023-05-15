#include "AIInput.h"
#include <iostream>

AIInput::AIInput(Ball* ball)
	:_ball(ball)
{
}

AIInput::~AIInput()
{
}

void AIInput::Update(Paddle* paddle)
{
	if (_ball->GetBallDirectionX() > 0)
	{
		if (_ball->GetPos().x < 600 && _ball->GetPos().x>400)
		{
			if (_ball->GetPos().y > paddle->GetPos().y + paddle->GetRect().h / 2)
			{
				paddle->MoveDown();

			}
			else if (_ball->GetPos().y < paddle->GetPos().y - paddle->GetRect().h / 2)
				paddle->MoveUp();
			else
				paddle->StopMoving();
		}
		//predict y
		else if (_ball->GetPos().x >= 600)
		{
			if (!_hasPrediction)
			{
				_predictY = Predict(paddle);
				_hasPrediction = true;
			}

			if (_predictY > paddle->GetPos().y + paddle->GetRect().h / 2)
			{
				paddle->MoveDown();

			}
			else if (_predictY < paddle->GetPos().y - paddle->GetRect().h / 2)
				paddle->MoveUp();
			else
				paddle->StopMoving();

		}

	}
	else
		_hasPrediction = false;
}

float AIInput::Predict(Paddle* paddle)
{
	float predictY = _ball->GetPos().y;
	std::cout << _predictY << std::endl;

	float x = paddle->GetPos().x - _ball->GetPos().x;
	float t = x / _ball->GetSpeed().x;
	float y = _ball->GetPos().y + _ball->GetSpeed().y * t;
	predictY = y;
	while (predictY < 30 || predictY>570)
	{
		if (predictY < 30)
		{
			predictY = 30 - (y - 30);
			y = predictY;
		}
		if (predictY > 570)
		{
			predictY = 570 - (y - 570);
			y = predictY;

		}
	}

	float r3 = -80 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (80 + 80)));

	return predictY + r3;
}
