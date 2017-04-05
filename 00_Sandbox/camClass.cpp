#include "camClass.h"



camClass::camClass()
{
	fov = 90.0f;
	position = vector3(4, 3, 3);
	target = vector3(0, 0, 0);
	up = vector3(0, 1, 0);
}

camClass::~camClass()
{
}

matrix4 camClass::GetView(void)
{
	return glm::lookAt(position, target, up);
}

matrix4 camClass::GetProjection(bool bOrthographic)
{
	if (bOrthographic)
	{
		return glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f);
	}
	else
	{
		return glm::perspective(fov, 1280.0f / 720.0f, 0.1f, 200.0f);
	}
}

void camClass::SetPosition(vector3 v3Position)
{
	position = v3Position;
}

void camClass::SetTarget(vector3 v3Target)
{
	target = v3Target;
}

void camClass::SetUp(vector3 v3Up)
{
	up = glm::normalize(v3Up);
}

vector3 camClass::GetForward()
{
	return glm::normalize(target - position);
}

vector3 camClass::GetLeft()
{
	return glm::cross(GetForward(), up);
}

void camClass::MoveForward(float fIncrement)
{
	position += (GetForward() * fIncrement);
	target += (GetForward() * fIncrement);
}

void camClass::MoveSideways(float fIncrement)
{
	position += (GetLeft() * fIncrement);
	target += (GetLeft() * fIncrement);
}

void camClass::MoveVertical(float fIncrement)
{
	position += (up * fIncrement);
	target += (up * fIncrement);
}

void camClass::ChangePitch(float fIncrement)
{
	quaternion q1 = glm::angleAxis(fIncrement, GetLeft());
	SetUp(q1 * up);
	vector3 toTarget = target - position;
	toTarget = q1 * toTarget;
	SetTarget(position + toTarget);
}

void camClass::ChangeRoll(float fIncrement)
{
	quaternion q1 = glm::angleAxis(fIncrement, GetForward());
	SetUp(q1 * up);
}

void camClass::ChangeYaw(float fIncrement)
{
	quaternion q1 = glm::angleAxis(fIncrement, up);
	vector3 toTarget = target - position;
	toTarget = q1 * toTarget;
	SetTarget(position + toTarget);
}
