#pragma once

#include "cocos2d.h"
#include "lua_function/LuaFunction.h"

using namespace cocos2d;

class SpeedController
{
public:

	SpeedController();

	~SpeedController();

	void setLuaUpdateCall(const LuaFunction& luaCall);
	inline void clearLuaUpdateCall()			{ m_enableLuaUpdateCall = false; }
	
	inline void setTarget(Node* target)			{ m_target = target; }
	inline Node* getTarget()					{ return m_target; }

	inline void setStopUpdate(bool isStop) { m_isStopUpdate = isStop; }

	inline bool isStopUpdate() { return m_isStopUpdate; }

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

	inline float getAppendX() { return m_appedValue.x; }
	inline float getAppendY() { return m_appedValue.y; }

	// ���õ�ǰ�Ƿ�Ϊ�������������÷����ֵΪ��ֵ
	// 1�� -1�� 0����
	void setGravityPositive(int x, int y);
	void setForcePositive(int x, int y);

	// �߼�����
	void logicUpdate(float time);

	void defaultValue();

protected:

	void forceUpdate(float time);

private:
	Vec2 m_gravity;		// ����
	Vec2 m_force;		// ��
	float m_friction;	// Ħ����
	Vec2 m_minValue;	// ��Сֵ
	Vec2 m_maxValue;	// ���ֵ

	bool m_enableGravity;	// �����Ƿ�����
	bool m_enableForce;		// ���Ƿ�����
	bool m_enableFriction;	// Ħ�����Ƿ�����
	bool m_enableMaxValue;	// ���ֵ�Ƿ�����
	bool m_enableMinValue;	// ��Сֵ�Ƿ�����

	bool m_isStopUpdate;	// �Ƿ�ֹͣ�߼�����

	Vec2 m_appedValue;

	LuaFunction m_luaUpdateCall;
	bool m_enableLuaUpdateCall;

	Node* m_target;
};
