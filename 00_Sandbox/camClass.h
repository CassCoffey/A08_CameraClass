#pragma once
#include "RE\ReEng.h"

class camClass
{
	public:
		camClass();
		~camClass();

		matrix4 GetView(void);
		matrix4 GetProjection(bool bOrthographic);

		void SetPosition(vector3 v3Position);
		void SetTarget(vector3 v3Target);
		void SetUp(vector3 v3Up);
		
		vector3 GetForward();
		vector3 GetLeft();

		void MoveForward(float fIncrement);
		void MoveSideways(float fIncrement);
		void MoveVertical(float fIncrement);
		void ChangePitch(float fIncrement);
		void ChangeRoll(float fIncrement);
		void ChangeYaw(float fIncrement);


	private:
		vector3 position;
		vector3 target;
		vector3 up;

		float fov;
};

