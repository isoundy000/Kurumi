#pragma once

#include "ecs/anaxHelper.h"
#include "lua_function/LuaFunction.h"

// �������
/*
 * -1�泯��
 * 1�泯��
*/
class OrientationComponent : public anax::Component, public Ref
{
public:

	OrientationComponent()
	{
		m_lockOrientation = false;
		m_orientation = 1;
	}

	virtual ~OrientationComponent()
	{}

	bool setOrientation(int orientation)
	{
		if (m_lockOrientation || m_orientation == orientation)
		{
			return false;
		}
		m_orientation = orientation;
		if (m_orientationTurnCall.isvalid())
		{
			m_orientationTurnCall.ppush();
			m_orientationTurnCall.pusharg(orientation);
			m_orientationTurnCall.pcall();
		}
		return true;
	}

	int m_orientation;

	bool m_lockOrientation;

	LuaFunction m_orientationTurnCall;
};

DEFINE_COMPONENT(OrientationComponent);
