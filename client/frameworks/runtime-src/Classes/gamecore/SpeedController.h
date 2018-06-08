#pragma once

#include "cocos2d.h"
#include "LuaFunction.hpp"

using namespace cocos2d;

// ֹͣ����
enum SpeedControllerStopCondi
{
	SC_CD_FORCE_EQ_ZERO,	// ��Ϊ0ʱ��ֹ����
	SC_CD_FORCE_EQ_MIN,		// ��������Сֵʱ
	SC_CD_FORCE_X_EQ_MIN,	// ��X������Сֵʱ
	SC_CD_FORCE_Y_EQ_MIN,	// ��Y������Сֵʱ
	SC_CD_ALL,				// ��ֹ����
	SC_CD_NONE				// û���κ�����
};

class SpeedController
{
public:

	SpeedController();

	~SpeedController();

	void setEventCall(const LuaFunction& luaCall);

	inline void resetCallForceZero()			{ m_isCallForceZero = false; }

	inline void setTarget(Node* target)			{ m_target = target; }

	inline void setStopCondition(SpeedControllerStopCondi condi) { m_condi = condi; }

	inline SpeedControllerStopCondi getStopCondition() { return m_condi; }

	// ��������
	inline void setGravity(float x, float y)	{ m_gravity = Vec2(x, y); }
	inline float getGravityX()					{ return m_gravity.x; }
	inline float getGravityY()					{ return m_gravity.y; }
	// �Ƿ���������
	inline void setGravityEnable(bool enable)	{ m_enableGravity = enable; }
	inline bool isGravityEnable()				{	return m_enableGravity;	}

	// ������
	inline void setForce(float x, float y)		{ m_force = Vec2(x, y); }
	inline float getForceX()					{ return m_force.x; }
	inline float getForceY()					{ return m_force.y; }
	// �Ƿ�������
	inline void setForceEnable(bool enable)		{ m_enableForce = enable; }
	inline bool isForceEnable()					{ return m_enableForce; }

	// ������Сֵ
	inline void setForceMinValue(float x, float y)	{ m_forceMinValue = Vec2(x, y); }
	inline float getForceMinValueX()				{ return m_forceMinValue.x; }
	inline float getForceMinValueY()				{ return m_forceMinValue.y; }
	// �Ƿ���������Сֵ
	inline void setForceMinValueEnable(bool enable) { m_enableForce = enable; }
	inline bool isForceMinValueEnable()			{ return m_enableForce; }

	// Ħ��������
	inline void setFriction(float friction)		{ m_friction = friction; }
	inline float getFriction()					{ return m_friction; }
	// �Ƿ�����Ħ����
	inline void setFrictionEnable(bool enable)	{ m_enableFriction = enable; }
	inline bool isFrictionEnable()				{ return m_enableFriction; }

	// �������ֵ
	inline void setMaxValue(float x, float y)	{ m_maxValue = Vec2(x, y); }
	inline float getMaxValueX()					{ return m_maxValue.x; }
	inline float getMaxValueY()					{ return m_maxValue.y; }
	// �Ƿ��������ֵ
	inline void setMaxValueEnable(bool enable)	{ m_enableMaxValue = enable; }
	inline bool isMaxValueEnable()				{ return m_enableMaxValue; }

	// ������Сֵ
	inline void setMinValue(float x, float y)	{ m_minValue = Vec2(x, y); }
	inline float getMinValueX()					{ return m_minValue.x; }
	inline float getMinValueY()					{ return m_minValue.y; }
	// �Ƿ��������ֵ
	inline void setMinValueEnable(bool enable)	{ m_enableMinValue = enable; }
	inline bool isMinValueEnable()				{ return m_enableMinValue; }

	// ������ֹ��������

	// �߼�����
	void logicUpdate(float time);

protected:

	void forceUpdate(float time);

	void callEvent(const std::string& eventName);

private:
	SpeedControllerStopCondi m_condi;

	Vec2 m_gravity;		// ����
	Vec2 m_force;		// ��
	Vec2 m_forceMinValue;//����Сֵ
	float m_friction;	// Ħ����
	Vec2 m_minValue;	// ��Сֵ
	Vec2 m_maxValue;	// ���ֵ

	bool m_enableGravity;	// �����Ƿ�����
	bool m_enableForce;		// ���Ƿ�����
	bool m_enableFriction;	// Ħ�����Ƿ�����
	bool m_enableMaxValue;	// ���ֵ�Ƿ�����
	bool m_enableMinValue;	// ��Сֵ�Ƿ�����

	Vec2 m_appedValue;

	LuaFunction m_luaCall;
	bool m_enableLuaCall;

	bool m_isCallForceZero;

	Node* m_target;
};
