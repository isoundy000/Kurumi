#pragma once

#include "GameActor.h"


class GameCharacter : public GameActor
{
public:

	GameCharacter();

	virtual ~GameCharacter();

	static GameCharacter* create();


	void initCharacterByData(const std::string& filepath, const Size& characterSize, const Vec2& characterPosition);

	inline QFSM* getFSM() { return &m_FSM; }

	inline Armature* getArmature() { return m_armature; }

	void setActorPositionInValidRect(const Vec2& characterPosition);

	/// ��ײ���
	virtual bool getAllDefRECT(std::vector<ActorRect>& actorRectVec) override;

	virtual bool getAllAttRECT(std::vector<ActorRect>& actorRectVec) override;

	virtual const Rect& getAABB()override;


	// ���ý�ɫ����
	virtual void setOrientation(int ori);
	// ��ȡ��ɫ����
	inline int getOrientation() { return m_curOrientation; }

	inline void lockOrientation() { m_isLockOrientation = true; }

	inline void unLockOrientation() { m_isLockOrientation = false; }

	inline bool isLockOrientation() { return m_isLockOrientation; }

	// actor�Ƿ��ڿ���
	bool isInAir();

	////////////////////////////box2d���////////////////////////////////
	bool isIgnoreBodyRotation() const;
	void setIgnoreBodyRotation(bool bIgnoreBodyRotation);

	b2Body* getB2Body() const;
	void setB2Body(b2Body *pBody);

	virtual void syncPhysicsTransform() const;

	// overrides
	virtual const Vec2& getPosition() const override;
	virtual void getPosition(float* x, float* y) const override;
	virtual float getPositionX() const override;
	virtual float getPositionY() const override;
	virtual Vec3 getPosition3D() const override;
	virtual void setPosition(const Vec2 &position) override;
	virtual void setPosition(float x, float y) override;
	virtual void setPositionX(float x) override;
	virtual void setPositionY(float y) override;
	virtual void setPosition3D(const Vec3& position) override;
	virtual float getRotation() const override;
	virtual void setRotation(float fRotation) override;

	virtual void onEnter() override;
	virtual void onExit() override;

protected:

	void updateArmatureInfo();

	virtual void loadArmature(const std::string& filepath);

	const Vec2& getPosFromPhysics() const;

	void afterUpdate(EventCustom *event);

protected:

	QFSM			m_FSM;				// ����״̬��
	Armature*		m_armature;			// ��������

	// ��ǰ���� -1 �� 1 �ұ�
	int	m_curOrientation;
	// ����������
	bool m_isLockOrientation;

	///box2d���
	bool    m_ignoreBodyRotation;
	// box2d specific
	b2Body  *m_pB2Body;
	// Event for update synchronise physic transform
	cocos2d::EventListenerCustom* m_syncTransform;

	Size			m_characterSize;
};
